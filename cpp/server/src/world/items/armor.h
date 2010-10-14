#ifndef FOB_SERVER_WORLD_ITEMS_ARMOR_H_
#define FOB_SERVER_WORLD_ITEMS_ARMOR_H_

#include <string>
//#include <vector>

#include <boost/uuid/uuid.hpp>

#include "item.h"

namespace fob {
namespace server {
namespace world {
namespace items {

class Armor : public Item {
 public:
  Armor(const boost::uuids::uuid &uid, const std::string &name);
  virtual ~Armor();

  bool Init(int defense);

  int defense();

 private:
  bool initiated_;
  
  int defense_;
  //TODO(Alotar): types
  //TODO(Alotar): attributes
};

}  // namespace items
}  // namespace world
}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_WORLD_ITEMS_ARMOR_H_
