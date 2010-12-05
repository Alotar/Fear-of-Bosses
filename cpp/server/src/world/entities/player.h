#ifndef FOB_SERVER_WORLD_ENTITES_PLAYER_H_
#define FOB_SERVER_WORLD_ENTITES_PLAYER_H_

#include <string>

#include <boost/uuid/uuid.hpp>

#include "entity.h"

namespace fob {
namespace server {
namespace world {
namespace entities {

class Player : public Entity {
 public:
  Player(const boost::uuids::uuid &uid, const std::string &name);
  virtual ~Player();
};

}  // namespace entities
}  // namespace world
}  // namespace server
}  // namespace fob
 
#endif  // FOB_SERVER_WORLD_ENTITES_MONSTER_H_
