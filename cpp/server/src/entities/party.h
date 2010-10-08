#ifndef FOB_SERVER_ENTITIES_PARTY_H_
#define FOB_SERVER_ENTITIES_PARTY_H_

#include <vector>
#include <boost/uuid/uuid.hpp>

namespace fob {
namespace server {
namespace entities {

class Party {
 public:
  Party(const boost::uuids::uuid &uid);
  virtual ~Party();

  boost::uuids::uuid &uid();

  void AddMember(Entity *member);
  bool RemoveMember(Entity *member);

  Entity* GetReadyMember();
 
 private:
  const boost::uuids::uuid uid_;
  std::vector<Entity*> members_;
};

}  // namespace entities
}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_ENTITY_PARTY_H_
