#include "manager.h"

namespace fob {
namespace server {

Manager::Manager()
  : world_(),
    connection_manager_(1234, &inc_msg_) {}

Manager::~Manager() {}

}  // namespace server
}  // namespace fob
