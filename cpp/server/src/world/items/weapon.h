#ifndef FOB_SERVER__WORLD_ITEMS_WEAPON_H_
#define FOB_SERVER__WORLD_ITEMS_WEAPON_H_

#include <string>
//#include <vector>

#include <boost/uuid/uuid.hpp>

#include "item.h"
#include "attributes/rangeattribute.h"

namespace fob {
namespace server {
namespace world {
namespace items {

class Weapon : public Item {
 public:
  Weapon(const boost::uuids::uuid &uid, const std::string &name);
  virtual ~Weapon();

  bool Init(int min_dmg, int max_dmg, bool two_handed);

  const ::fob::server::attributes::RangeAttribute &damage();
  bool two_handed();

 private:
  bool initiated_;

  ::fob::server::attributes::RangeAttribute damage_;
  bool two_handed_;
  //TODO(Alotar): attributes
};

}  // namespace items
}  // namespace world
}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER__WORLD_ITEMS_WEAPON_H_
