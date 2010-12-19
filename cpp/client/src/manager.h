#ifndef FOB_CLIENT_MANAGER_H_
#define FOB_CLIENT_MANAGER_H_

#include <string>

#include <boost/uuid/uuid.hpp>

#include "network/connectionmanager.h"
#include "interface/interfacemanager.h"
#include "chatmanager.h"

namespace fob {
namespace client {

class Manager {
 public:
  Manager(const std::string &ip, uint16_t port);
  virtual ~Manager();

  void Run();

 private:
  network::ConnectionManager connection_manager_;
  interface::InterfaceManager interface_manager_;
  ChatManager chat_manager_;

  std::string name_;
  boost::uuids::uuid uid_;
};

}  // namespace client
}  // namespace fob

#endif  // FOB_CLIENT_MANAGER_H_
