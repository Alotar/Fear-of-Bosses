#include "chatmanager.h"

namespace fob {
namespace server {

ChatManager::ChatManager(std::queue<std::pair< boost::uuids::uuid, network::Message*> > *out_msg)
  : out_msg_(out_msg) {}

ChatManager::~ChatManager() {}

void ChatManager::RegisterClient(const boost::uuids::uuid &uid, const std::string &name) {
  struct Client new_client;
  new_client.uid = uid;
  new_client.name = name;
  new_client.channel = "main";
  clients_.push_back(new_client);
}

void ChatManager::RemoveClient(const boost::uuids::uuid &uid) {
  clients_.erase(Find(uid));
}

void ChatManager::Send(const std::string &name, const std::string &message) {
  std::string channel = Find(name)->channel;
  network::Message *msg = new network::Message(network::Message::kTypeChat);
  msg->Inject(name);
  msg->Inject(message);
  for (std::vector<struct Client>::iterator iter = clients_.begin(); iter != clients_.end(); ++iter) {
    if (iter->channel == channel) {
      network::Message *msg_copy = new network::Message(msg->GetString());
      out_msg_->push(std::make_pair(iter->uid, msg_copy));
    }
  }
  delete msg;
}

void ChatManager::ChangeChannel(const std::string &name,const std::string &channel) {
  Find(name)->channel = channel;
}

std::vector<struct ChatManager::Client>::iterator ChatManager::Find(const std::string &name) {
  for (std::vector<struct Client>::iterator iter = clients_.begin(); iter != clients_.end(); ++iter) {
    if (iter->name == name) {
      return iter;
    }
  }
}

std::vector<struct ChatManager::Client>::iterator ChatManager::Find(const boost::uuids::uuid &uid) {
  for (std::vector<struct Client>::iterator iter = clients_.begin(); iter != clients_.end(); ++iter) {
    if (iter->uid == uid) {
      return iter;
    }
  }
}

}  // namespace server
}  // namespace fob
