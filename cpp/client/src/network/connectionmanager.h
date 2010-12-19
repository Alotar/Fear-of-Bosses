#ifndef FOB_CLIENT_NETWORK_CONNECTIONMANAGER_H_
#define FOB_CLIENT_NETWORK_CONNECTIONMANAGER_H_

#include <string>
#include <netinet/in.h>

#include "message.h"

namespace fob {
namespace client {
namespace network {

class ConnectionManager {
 public:
  ConnectionManager(const std::string &ip, uint16_t port);
  virtual ~ConnectionManager();

  void Init();
  void Connect();
  void Disconnect();

  void Send(std::string &message);
  Message *Listen(bool wait = true);

 private:
  bool initialized_;

  struct sockaddr_in server_address_;
  int socket_;
};

}  // namespace network
}  // namespace client
}  // namespace fob

#endif  // FOB_CLIENT_NETWORK_CONNECTIONMANAGER_H_
