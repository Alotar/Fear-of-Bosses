#include "party.h"

#include <boost/foreach.hpp>

namespace fob {
namespace server {
namespace entities {

Party::Party(const boost::uuids::uuid &uid)
  : uid_(uid) {}

Party::~Party() {}

boost::uuids::uuid &uid() {
  return uid_;
}

void Party::AddMember(Entity *member) {
  //TODO Bounds
  members_.push_back(member);
}

bool Party::RemoveMember(Entity *member) {
  BOOST_FOREACH (Entity *i, members_) {
    if (i == member) {
      members_.erase(i);
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
