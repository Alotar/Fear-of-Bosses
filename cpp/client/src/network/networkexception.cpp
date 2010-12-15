#include "networkexception.h"

namespace fob {
namespace client {
namespace network {

NetworkException::NetworkException(std::string msg)
  : message_(msg) {}

NetworkException::~NetworkException() {}

const std::string &NetworkException::message() {
  return message_;
}

}  // namespace network
}  // namespace client
}  // namespace fob
