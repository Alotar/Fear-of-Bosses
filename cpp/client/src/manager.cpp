#include "manager.h"

namespace fob {
namespace client {

Manager::Manager(const std::string &ip, uint16_t port)
  : connection_manager_(ip, port),
    interface_manager_(),
    chat_manager_(&connection_manager_, &interface_manager_) {}

Manager::~Manager() {}

void Manager::Init() {
  connection_manager_.Init();
  std::string const_str = "Name: ";
  interface_manager_.Print(interface::InterfaceManager::kStandard, const_str);
  name_ = interface_manager_.GetString(interface::InterfaceManager::kStandard);
  chat_manager_.set_name(name_);

  // Connecting and sending name
  connection_manager_.Connect();
  network::Message *login_msg = connection_manager_.Listen();
  if (login_msg->GetType() != network::Message::kTypeLogin) {
    return;  // Wrong message type
  } else {
    network::Message::StdMessage msg_type;
    int fd;
    login_msg->Extract(msg_type);
    if (msg_type != network::Message::kMsgRequest) {
      return;  // Who the hell programmed the server?
    }
    login_msg->Extract(fd);
    network::Message out_msg(network::Message::kTypeLogin);
    out_msg.Inject(name_);
    out_msg.Inject(fd);
    const_str = out_msg.GetString();
    connection_manager_.Send(const_str);
  }
  delete login_msg;

  // Receiving confirmation
  login_msg = connection_manager_.Listen();
  if (login_msg->GetType() != network::Message::kTypeLogin) {
    return;  // Wrong message type
  } else {
    network::Message::StdMessage msg_type;
    login_msg->Extract(msg_type);
    if (msg_type != network::Message::kMsgOk) {
      return;  // TODO(Alotar): handle wrong login
    }
    login_msg->Extract(uid_);
  }
  delete login_msg;

  std::string greet = "You are logged as " + name_ + " in the channel #main";
  interface_manager_.Print(interface::InterfaceManager::kChat, greet);
}

void Manager::Run() {
  // Main cycle
  bool running = true;
  while (running) {
    char key = interface_manager_.GetKeyPress();
    if (key == 10) {  // Return
      std::string message = interface_manager_.GetString(interface::InterfaceManager::kChat);
      chat_manager_.Send(message);
    } else if (key == 27) {  // Escape
      running = false;
    }

    network::Message *msg_in = connection_manager_.Listen(false);
    if (msg_in != NULL) {  // New message incoming
      network::Message::MessageType msg_type = msg_in->GetType();
      switch (msg_type) {
        case network::Message::kTypeChat: {
          std::string chat_name;
          std::string chat_msg;
          msg_in->Extract(chat_name);
          msg_in->Extract(chat_msg);
          chat_manager_.Receive(chat_name, chat_msg);
          break;
        }
        default:
          break;
      }
      delete msg_in;
    }
  }
}

}  // namespace client
}  // namespace fob
