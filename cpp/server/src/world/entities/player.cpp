#include "player.h"

namespace fob {
namespace server {
namespace world {
namespace entities {

Player::Player(const boost::uuids::uuid &uid, const std::string &name)
  : Entity(uid, name) {}

Player::~Player() {}

}  // namespace entities
}  // namespace world
}  // namespace server
}  // namespace fob
