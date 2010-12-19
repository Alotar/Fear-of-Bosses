#include "world.h"

namespace fob {
namespace server {
namespace world {

World::World()
  : player_name_list_() {}

World::~World() {}

const boost::uuids::uuid World::AddPlayer(const std::string &name) {
  std::vector<std::string>::iterator iter = 
                          std::find(player_name_list_.begin(),
                                    player_name_list_.end(), name);
  std::string dup;
  if (iter != player_name_list_.end()) {
    dup = *iter;
  }
  if(dup == name) {  // player already exists
    typedef boost::unordered_map<boost::uuids::uuid, entities::Player*> umap;
    for(umap::iterator iter = player_list_.begin(); iter != player_list_.end(); iter++) {
      if (iter->second->name() == name) {
        return iter->first;
      }
    }
  }
  player_name_list_.push_back(name);
  boost::uuids::uuid uid = uuid_gen();
  entities::Player *player = new entities::Player(uid, name);
  player_list_[uid] = player;
  return uid;
}

void World::RemovePlayer(const boost::uuids::uuid &uid) {
  std::string name = player_list_[uid]->name();
  player_list_.erase(uid);
  player_name_list_.erase(std::find(player_name_list_.begin(), player_name_list_.end(), name));
}

}  // namespace world
}  // namespace server
}  // namespace fob
