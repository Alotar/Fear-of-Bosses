#include "connectionmanager.h"

#include <iostream>

#include <cstring>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>

#include "networkexception.h"

namespace fob {
namespace client {
namespace network {

ConnectionManager::ConnectionManager(const std::string &ip, uint16_t port)
  : initialized_(false),
    socket_(0) {
  memset(&server_address_, 0, sizeof(server_address_));

  server_address_.sin_family = AF_INET;
  server_address_.sin_port = htons(port);

  if (inet_aton(ip.c_str(), &server_address_.sin_addr) == 0) {
    throw NetworkException("Invalid remote IP address.");
  }
}

ConnectionManager::~ConnectionManager() {}

void ConnectionManager::Init() {
  if (initialized_) {
    return;
  }

  socket_ = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_ == -1) {
    throw NetworkException("Error creating socket.");
  }
  initialized_ = true;
}

void ConnectionManager::Connect() {
  if (!initialized_) {
    throw NetworkException("Connecting with uninitialized manager.");
  }

  if (connect(socket_, (struct sockaddr*)&server_address_, sizeof(server_address_)) == -1) {
    throw NetworkException("Error connecting to host.");
  }
}

void ConnectionManager::Disconnect() {
  close(socket_);
}

void ConnectionManager::Send(std::string &message) {
  uint16_t length = message.length();
  char *msg = new char[length+sizeof(length)];
  memcpy(msg+sizeof(length), message.c_str(), length);
  length = htons(length);
  memcpy(msg, &length, sizeof(length));
  length = ntohs(length);

  uint16_t left_to_send = length + sizeof(length);
  uint16_t already_sent = 0;
  while (left_to_send > 0) {
    int sent = send(socket_, msg, left_to_send, 0);
    already_sent += sent;
    left_to_send -= sent;
  }

  delete msg;
}

Message *ConnectionManager::Listen(bool wait) {
  if (!wait) {  // If it's not required to wait
    fd_set fds;
    struct timeval tv;

    FD_ZERO(&fds);
    FD_SET(socket_, &fds);
    tv.tv_sec = 1;  // 1s
    tv.tv_sec = 0;

    int n = select(socket_+1, &fds, NULL, NULL, &tv);
    if (n == 0) {  // Timeout
      return NULL;
    }
  }

  uint16_t msg_len;
  int rec_len = recv(socket_, &msg_len, sizeof(msg_len), 0);
  if (rec_len <= 0) {
    throw("Error receiving package.");
  }
  else {
    msg_len = ntohs(msg_len);

    char buffer[msg_len+1];
    memset(buffer, 0, sizeof(buffer));

    uint16_t rec = 0;  // already received length

    while (msg_len > 0) {  // getting the whole message
      rec_len = recv(socket_, buffer+rec, msg_len, 0);
      rec += rec_len;
      msg_len -= rec_len;
    }
    std::string str_buffer(buffer);
    Message *msg = new Message(str_buffer);
    return msg;
  }
}

}  // namespace network
}  // namespace client
}  // namespace fob
