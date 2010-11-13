#include "networkexception.h"

namespace fob {
namespace server {
namespace network {

NetworkException::NetworkException(std::string msg)
  : message_(msg) {}

NetworkException::~NetworkException() {}

const std::string &NetworkException::message() {
  return message_;
}

}  // namespace network
}  // namespace server
}  // namespace fob
