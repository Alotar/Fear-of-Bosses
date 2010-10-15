#ifndef FOB_SERVER_WORLD_WORLD_H_
#define FOB_SERVER_WORLD_WORLD_H_

#include <vector>

#include "entities/entity.h"
#include "entities/party.h"
#include "items/item.h"

namespace fob {
namespace server {
namespace world {

class World {
 public:
  World();
  virtual ~World();

 private:
  std::vector<entities::Party*> party_list_;
  std::vector<entities::Entity*> entity_list_;
  std::vector<items::Item*> item_list_;
};

}  // namespace world
}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_WORLD_WORLD_H_
