#ifndef FOB_SERVER_WORLD_ITEMS_ITEM_H_
#define FOB_SERVER_WORLD_ITEMS_ITEM_H_

#include <string>

#include <boost/uuid/uuid.hpp>

namespace fob {
namespace server {
namespace world {
namespace items {

class Item {
 public:
  Item(const boost::uuids::uuid &uid, const std::string &name);
  virtual ~Item();

  const boost::uuids::uuid &uid();
  const std::string &name();

 private:
  const boost::uuids::uuid uid_;
  const std::string name_;
};

}  // namespace items
}  // namespace world
}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_WORLD_ITEMS_ITEM_H_
