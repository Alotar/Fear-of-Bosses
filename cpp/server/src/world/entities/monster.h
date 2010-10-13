#ifndef FOB_SERVER_ENTITES_MONSTER_H_
#define FOB_SERVER_ENTITES_MONSTER_H_

#include <string>

#include <boost/uuid/uuid.hpp>

#include "entity.h"

namespace fob {
namespace server {
namespace world {
namespace entities {

class Monster : public Entity {
 public:
  Monster(const boost::uuids::uuid &uid, const std::string &name);
  virtual ~Monster();
};

}  // namespace entities
}  // namespace world
}  // namespace server
}  // namespace fob
 
#endif  // FOB_SERVER_ENTITES_MONSTER_H_
