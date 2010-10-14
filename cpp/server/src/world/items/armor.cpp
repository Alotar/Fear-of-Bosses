#include "armor.h"

namespace fob {
namespace server {
namespace world {
namespace items {

Armor::Armor(const boost::uuids::uuid &uid, const std::string &name)
  : Item(uid, name),
    initiated_(false) {}

Armor::~Armor() {}

bool Armor::Init(int defense) {
  if (initiated_) {
    return false;
  }

  defense_ = defense;

  initiated_ = true;
  return true;
}

int Armor::defense() {
  return defense_;
}

}  // namespace items
}  // namespace world
}  // namespace server
}  // namespace fob
