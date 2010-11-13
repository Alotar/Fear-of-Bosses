#ifndef FOB_SERVER_NETWORK_NETWORKEXCEPTION_H_
#define FOB_SERVER_NETWORK_NETWORKEXCEPTION_H_

#include <string>

namespace fob {
namespace server {
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
}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_NETWORK_NETWORKEXCEPTION_H_
