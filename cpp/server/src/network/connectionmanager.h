#ifndef FOB_SERVER_NETWORK_CONNECTIONMANAGER_H_
#define FOB_SERVER_NETWORK_CONNECTIONMANAGER_H_

#include <queue>
#include <string>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>

#include <boost/bimap.hpp>
#include <boost/uuid/uuid.hpp>

#include "message.h"

namespace fob {
namespace server {
namespace network {

class ConnectionManager {
 public:
  ConnectionManager(uint16_t port, std::queue<Message*> *inc_msg);
  ~ConnectionManager();

  void Init();

  void Listen();

  void Send(const boost::uuids::uuid &client, const std::string &message);
  void RegisterClient(int descriptor, const boost::uuids::uuid &uid);
  void DisconnectClient(const boost::uuids::uuid &client);

 private:
  void Send(int descriptor, const std::string &mesage);
  void AddClient(int descriptor);
  void HandleNewClient(int descriptor);
  void DisconnectClient(int descriptor);

 private:
  bool initialized_;

  struct sockaddr_in server_address_;
  int listen_socket_;

  fd_set clients_;
  int last_client_;

  boost::bimap<int, boost::uuids::uuid> fd_uid_map_;

  std::queue<Message*> *inc_msg_;
};

}  // namespace network
}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_NETWORK_CONNECTIONMANAGER_H_
