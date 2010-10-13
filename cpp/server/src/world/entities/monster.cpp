#include "monster.h"

namespace fob {
namespace server {
namespace world {
namespace entities {

Monster::Monster(const boost::uuids::uuid &uid, const std::string &name)
  : Entity(uid, name) {}

Monster::~Monster() {}

}  // namespace entities
}  // namespace world
}  // namespace server
}  // namespace fob
