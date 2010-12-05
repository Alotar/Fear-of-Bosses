#ifndef FOB_SERVER_NETWORK_MESSAGE_H_
#define FOB_SERVER_NETWORK_MESSAGE_H_

#include <string>
#include <sstream>

#include <boost/uuid/uuid.hpp>

namespace fob {
namespace server {
namespace network {

class Message {
 public:
  enum MessageType {
    kTypeLogin,
    kTypeLogout,
    kTypeChat
  };

  enum StdMessage {
    kMsgRequest,
    kMsgOk
  };

  Message(MessageType type);
  Message(const std::string &content);
  virtual ~Message();

  std::string GetString();

  void Inject(int var);
  void Inject(const std::string &var);
  void Inject(const boost::uuids::uuid &var);
  void Inject(StdMessage msg);

  MessageType GetType();

  void Extract(int &var);
  void Extract(std::string &var);
  void Extract(boost::uuids::uuid &var);
  void Extract(StdMessage &var);

 private:
  std::stringstream content_;
};

}  // namespace network
}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_NETWORK_MESSAGE_H_
