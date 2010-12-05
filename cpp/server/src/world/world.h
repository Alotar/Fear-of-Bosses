#ifndef FOB_SERVER_WORLD_WORLD_H_
#define FOB_SERVER_WORLD_WORLD_H_

#include <string>
#include <vector>

#include <boost/unordered_map.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>

#include "entities/player.h"
#include "entities/monster.h"
#include "entities/party.h"
#include "items/item.h"

namespace fob {
namespace server {
namespace world {

class World {
 public:
  World();
  virtual ~World();

  const boost::uuids::uuid AddPlayer(const std::string &name);
  void RemovePlayer(const boost::uuids::uuid &uid);

 private:
  boost::uuids::random_generator uuid_gen;

  boost::unordered_map<boost::uuids::uuid, entities::Party*> party_list_;
  boost::unordered_map<boost::uuids::uuid, entities::Player*> player_list_;
  boost::unordered_map<boost::uuids::uuid, entities::Monster*> monster_list_;
  boost::unordered_map<boost::uuids::uuid, items::Item*> item_list_;

  std::vector<std::string> player_name_list_;
};

}  // namespace world
}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_WORLD_WORLD_H_
