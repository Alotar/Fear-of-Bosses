#include "party.h"

#include <boost/foreach.hpp>

namespace fob {
namespace server {
namespace world {
namespace entities {

Party::Party(const boost::uuids::uuid &uid)
  : uid_(uid) {}

Party::~Party() {}

const boost::uuids::uuid &Party::uid() {
  return uid_;
}

void Party::AddMember(Entity *member) {
  //TODO Bounds
  members_.push_back(member);
}

void Party::RemoveMember(Entity *member) {
  members_.erase(std::find(members_.begin(), members_.end(), member));
}

Entity *Party::GetReadyMember() {
  // placeholder
  return NULL;
}

}  // namespace entities
}  // namespace world
}  // namespace server
}  // namespace fob
