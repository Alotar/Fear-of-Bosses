#ifndef FOB_SERVER_CHATMANAGER_H_
#define FOB_SERVER_CHATMANAGER_H_

#include <string>
#include <queue>
#include <utility>
#include <vector>

#include <boost/uuid/uuid.hpp>

#include "network/message.h"

namespace fob {
namespace server {

class ChatManager {
 private:
  struct Client {
    boost::uuids::uuid uid;
    std::string name;
    std::string channel;
  };

 public:
  ChatManager(std::queue<std::pair< boost::uuids::uuid, network::Message*> > *out_msg);
  ~ChatManager();

  void RegisterClient(const boost::uuids::uuid &uid, const std::string &name);
  void RemoveClient(const boost::uuids::uuid &uid);

  void Send(const std::string &name, const std::string &message);
  void ChangeChannel(const std::string &name, const std::string &channel);

 private:
  std::vector<struct Client>::iterator Find(const std::string &name);
  std::vector<struct Client>::iterator Find(const boost::uuids::uuid &uid);

 private:
  std::queue<std::pair< boost::uuids::uuid, network::Message*> > *out_msg_;

  std::vector<struct Client> clients_;
};

}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_CHATMANAGER_H_
