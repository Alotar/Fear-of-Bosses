#ifndef FOB_CLIENT_CHATMANAGER_H_
#define FOB_CLIENT_CHATMANAGER_H_

#include <string>

#include "network/message.h"
#include "network/connectionmanager.h"
#include "interface/interfacemanager.h"

namespace fob {
namespace client {

class ChatManager {
 public:
  ChatManager(network::ConnectionManager *cm,
              interface::InterfaceManager *im);
  virtual ~ChatManager();

  void set_name(std::string &name);

  void Send(std::string &message);
  void Receive(std::string &name, std::string &msg);

 private:
  std::string name_;

  interface::InterfaceManager *interface_;
  network::ConnectionManager *network_;
};

}  // namespace client
}  // namespace fob

#endif  // FOB_CLIENT_CHATMANAGER_H_
