#include "connectionmanager.h"

#include <iostream>
#include <cstring>
#include <arpa/inet.h>

#include "networkexception.h"

namespace fob {
namespace server {
namespace network {

ConnectionManager::ConnectionManager(uint16_t port, std::queue<Message*> *inc_msg)
  : initialized_(false),
    last_client_(0),
    inc_msg_(inc_msg) {
  FD_ZERO(&clients_);
  memset(&server_address_, 0, sizeof(server_address_));

  server_address_.sin_family = AF_INET;
  server_address_.sin_addr.s_addr = htonl(INADDR_ANY);
  server_address_.sin_port = htons(port);
}

ConnectionManager::~ConnectionManager() {}

void ConnectionManager::Init() {
  if ((listen_socket_ = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    throw NetworkException("Error creating listening socket");
  }

  if (bind(listen_socket_, (struct sockaddr*)&server_address_, sizeof(server_address_)) == -1) {
    throw NetworkException("Error binding listening socket");
  }

  AddClient(listen_socket_);
  initialized_ = true;
}

void ConnectionManager::Listen() {
  if (!initialized_) {
    throw NetworkException("ConnectionManager not initialized");
  }

  if (listen(listen_socket_, 10) == -1) {
    throw NetworkException("Error listening");
  }

  fd_set read_fd = clients_;
  if (select(last_client_+1, &read_fd, NULL, NULL, NULL) == -1) {
    throw NetworkException("Error in select()");
  }
  
  for (int i = 0; i <= last_client_; i++) {
    if (FD_ISSET(i, &read_fd)) {
      if (i == listen_socket_) {  // new client
        struct sockaddr_in client_address;
        memset(&client_address, 0, sizeof(client_address));
        socklen_t address_length = sizeof(client_address);

        int new_fd = accept(listen_socket_, (struct sockaddr*)&client_address, &address_length);
        if (new_fd != -1) {
          HandleNewClient(new_fd);

          std::cout << ", from " << inet_ntoa(client_address.sin_addr) << std::endl;
        }
      }
      else {  // client sending data
        uint16_t msg_len;
        int rec_len = recv(i, &msg_len, sizeof(msg_len), 0);
        if (rec_len <= 0) {
          DisconnectClient(i);
        }
        else {
          msg_len = ntohs(msg_len);

          char buffer[msg_len+1];
          memset(buffer, 0, sizeof(buffer));

          uint16_t rec = 0;  // already received length

          while (msg_len > 0) {  // getting the whole message
            rec_len = recv(i, buffer+rec, msg_len, 0);
            rec += rec_len;
            msg_len -= rec_len;
          }
          std::string str_buffer(buffer);
          Message *msg = new Message(str_buffer);
          inc_msg_->push(msg);
        }
      }
    }
  }
}

void ConnectionManager::Send(boost::uuids::uuid &client, std::string &message) {
  int fd = fd_uid_map_.right.at(client);
  Send(fd, message);
}

void ConnectionManager::Send(int descriptor, const std::string &message) {
  uint16_t length = message.length();
  char* msg = new char[length+sizeof(length)];
  memcpy(msg+sizeof(length), message.c_str(), length);
  length = htons(length);
  memcpy(msg, &length, sizeof(length));
  length = ntohs(length);

  if (!FD_ISSET(descriptor, &clients_)) {
    delete msg;
    throw NetworkException("Client is not registered");
  }

  uint16_t left_to_send = length + sizeof(length);
  uint16_t already_sent = 0;
  while (left_to_send > 0) {
    int sent = send(descriptor, msg+already_sent, left_to_send, 0);
    already_sent += sent;
    left_to_send -= sent;
  }

  delete msg;
}

void ConnectionManager::RegisterClient(int descriptor, const boost::uuids::uuid &uid) {
  typedef boost::bimap<int, boost::uuids::uuid> map;
  fd_uid_map_.insert(map::value_type(descriptor, uid));
}

void ConnectionManager::AddClient(int descriptor) {
  FD_SET(descriptor, &clients_);
  if (descriptor > last_client_) {
    last_client_ = descriptor;
  }
}

void ConnectionManager::HandleNewClient(int descriptor) {
  std::cout << "New client on socket " << descriptor;
  Message login(Message::kTypeLogin);
  login.Inject(Message::kMsgRequest);
  login.Inject(descriptor);
  AddClient(descriptor);
  Send(descriptor, login.GetString());
}

void ConnectionManager::DisconnectClient(int descriptor) {
  std::cout << "Client " << descriptor << " has disconnected." << std::endl;
  Message *logout = new Message(Message::kTypeLogout);
  logout->Inject(fd_uid_map_.left.at(descriptor));
  inc_msg_->push(logout);
}

void ConnectionManager::DisconnectClient(const boost::uuids::uuid &client) {
  int fd = fd_uid_map_.right.at(client);
  fd_uid_map_.left.erase(fd);
  FD_CLR(fd, &clients_);
  close(fd);
}

}  // namespace network
}  // namespace server
}  // namespace fob
