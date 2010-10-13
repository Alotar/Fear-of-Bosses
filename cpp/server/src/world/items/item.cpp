#include "item.h"

namespace fob {
namespace server {
namespace world {
namespace items {

Item::Item(const boost::uuids::uuid &uid, const std::string &name)
  : uid_(uid),
    name_(name) {}

Item::~Item() {}

}  // namespace items
}  // namespace world
}  // namespace server
}  // namespace fob
