#ifndef FOB_SERVER_WORLD_WORLD_H_
#define FOB_SERVER_WORLD_WORLD_H_

#include <boost/unordered_map.hpp>
#include <boost/uuid/uuid.hpp>

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
  boost::unordered_map<boost::uuids::uuid, entities::Party*> party_list_;
  boost::unordered_map<boost::uuids::uuid, entities::Entity*> entity_list_;
  boost::unordered_map<boost::uuids::uuid, items::Item*> item_list_;
};

}  // namespace world
}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_WORLD_WORLD_H_
