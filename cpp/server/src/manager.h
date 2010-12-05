#ifndef FOB_SERVER_MANAGER_H
#define FOB_SERVER_MANAGER_H

#include <queue>

#include <boost/uuid/uuid.hpp>

#include "world/world.h"
#include "network/connectionmanager.h"
#include "chatmanager.h"

namespace fob {
namespace server {

class Manager {
 public:
  Manager();
  ~Manager();

 private:
  void LoginClient(int fd, std::string &name);
  void LogoutClient(boost::uuids::uuid &uid);

  void ManageIncMsg();
  void ManageOutMsg();

 private:
  world::World world_;
  network::ConnectionManager connection_manager_;
  ChatManager chat_manager_;

  std::queue<network::Message*> inc_msg_;
  std::queue< std::pair<boost::uuids::uuid, network::Message*> > out_msg_;
};

}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_MANAGER_H
