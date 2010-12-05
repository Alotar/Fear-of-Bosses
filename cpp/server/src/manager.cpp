#include "manager.h"

namespace fob {
namespace server {

Manager::Manager()
  : world_(),
    connection_manager_(1234, &inc_msg_),
    chat_manager_(&out_msg_) {}

Manager::~Manager() {}

void Manager::ManageIncMsg() {
  while (!inc_msg_.empty()) {
    network::Message *msg = inc_msg_.front();
    network::Message::MessageType type = msg->GetType();

    std::string name;
    boost::uuids::uuid uid;
    switch (type) {
      case network::Message::kTypeLogin:
        int fd;
        msg->Extract(name);
        msg->Extract(fd);
        LoginClient(fd, name);
        break;
      case network::Message::kTypeLogout:
        msg->Extract(uid);
        LogoutClient(uid);
        break;
      case network::Message::kTypeChat:
        break;
    }

    delete msg;
    inc_msg_.pop();
  }
}

void Manager::LoginClient(int fd, std::string &name) {
  boost::uuids::uuid uid = world_.AddPlayer(name);
  connection_manager_.RegisterClient(fd, uid);
  chat_manager_.RegisterClient(uid, name);

  network::Message *msg = new network::Message(network::Message::kTypeLogin);
  msg->Inject(network::Message::kMsgOk);
  msg->Inject(uid);
  out_msg_.push(std::make_pair(uid, msg));
}

void Manager::LogoutClient(boost::uuids::uuid &uid) {
  world_.RemovePlayer(uid);
  chat_manager_.RemoveClient(uid);
  connection_manager_.DisconnectClient(uid);
}

void Manager::ManageOutMsg() {
  while (!out_msg_.empty()) {
    std::string msg = out_msg_.front().second->GetString();
    connection_manager_.Send(out_msg_.front().first, msg);
    out_msg_.pop();
  }
}

}  // namespace server
}  // namespace fob
