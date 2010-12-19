#include "chatmanager.h"

namespace fob {
namespace client {

ChatManager::ChatManager(network::ConnectionManager *cm,
                         interface::InterfaceManager *im)
  : interface_(im),
    network_(cm) {}

ChatManager::~ChatManager() {}

void ChatManager::set_name(std::string &name) {
  name_ = name;
}

void ChatManager::Send(std::string &message) {
  network::Message msg(network::Message::kTypeChat);
  if (message.compare(0,3,"/j ") == 0) {
    msg.Inject(network::Message::kChatChannel);
    msg.Inject(name_);
    std::string channel = message.substr(3);
    msg.Inject(channel);
    std::string chan_cast = "Channel: " + channel;
    interface_->Print(interface::InterfaceManager::kChat, chan_cast);
  } else {
    msg.Inject(network::Message::kChatSend);
    msg.Inject(name_);
    msg.Inject(message);
  }
  std::string msg_string = msg.GetString();
  network_->Send(msg_string);
}

void ChatManager::Receive(std::string &name, std::string &msg) {
  std::string message = name + ": " + msg;
  interface_->Print(interface::InterfaceManager::kChat, message);
}

}  // namespace client
}  // namespace fob
