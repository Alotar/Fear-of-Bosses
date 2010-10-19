#ifndef FOB_SERVER_MANAGER_H
#define FOB_SERVER_MANAGER_H

#include "world/world.h"

namespace fob {
namespace server {

class Manager {
 public:
  Manager();
  ~Manager();

 private:
  world::World world;
};

}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_MANAGER_H
