#ifndef FOB_CLIENT_NETWORK_NETWORKEXCEPTION_H_
#define FOB_CLIENT_NETWORK_NETWORKEXCEPTION_H_

#include <string>

namespace fob {
namespace client {
namespace network {

class NetworkException {
 public:
  NetworkException(std::string msg);
  ~NetworkException();

  const std::string &message();

 private:
  std::string message_;
};

}  // namespace network
}  // namespace client
}  // namespace fob

#endif  // FOB_CLIENT_NETWORK_NETWORKEXCEPTION_H_
