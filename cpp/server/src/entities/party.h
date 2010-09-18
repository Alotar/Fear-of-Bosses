#ifndef FOB_SERVER_ENTITIES_PARTY_H_
#define FOB_SERVER_ENTITIES_PARTY_H_

#include <vector>

namespace fob {
namespace server {
namespace entities {

class Party {
 public:
  Party();
  virtual ~Party();

  void AddMember(Entity *member);
  bool RemoveMember(Entity *member);

  Entity* GetReadyMember();
 
 private:
  std::vector<Entity*> members_;
};

} // namespace entities
} // namespace server
} // namespace fob

#endif // FOB_SERVER_ENTITY_PARTY_H_
