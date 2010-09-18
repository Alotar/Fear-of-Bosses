#include "party.cpp"

namespace fob {
namespace server {
namespace entities {

Party::Party() {}

Party::~Party() {}

void Party::AddMember(Entity *member) {
  //TODO Bounds
  members_.push_back(member);
}

bool Party::RemoveMember(Entity *member) {
  for (std::vector<Entity*>::iterator iter = members_.begin();
       iter != members_.end();
       ++iter) {
    if (*iter == member) {
      members_.erase(iter);
      return true;
    }
  }
  return false;
}

Entity *Party::GetReadyMember() {
  // placeholder
  return NULL;
}

} // namespace entities
} // namespace server
} // namespace fob
