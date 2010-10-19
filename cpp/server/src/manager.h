#ifndef FOB_SERVER_MANAGER_H
#define FOB_SERVER_MANAGER_H

#include "world/world.h"
#include "network/connectionmanager.h"

namespace fob {
namespace server {

class Manager {
 public:
  Manager();
  ~Manager();

 private:
  world::World world_;
  network::ConnectionManager connection_manager_;
};

}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_MANAGER_H
