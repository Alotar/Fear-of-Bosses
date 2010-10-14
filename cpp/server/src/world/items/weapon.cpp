#include "weapon.h"

namespace fob {
namespace server {
namespace world {
namespace items {

Weapon::Weapon(const boost::uuids::uuid &uid, const std::string &name)
  : Item(uid, name),
    initiated_(false),
    damage_(0,0) {}

Weapon::~Weapon() {}

bool Weapon::Init(int min_dmg, int max_dmg, bool two_handed) {
  if (initiated_) {
    return false;
  }

  damage_.set_max(max_dmg);
  damage_.set_min(min_dmg);
  two_handed_ = two_handed;

  initiated_ = true;
  return true;
}

const ::fob::server::attributes::RangeAttribute &Weapon::damage() {
  return damage_;
}

bool Weapon::two_handed() {
  return two_handed_;
}

}  // namespace items
}  // namespace world
}  // namespace server
}  // namespace fob
