#ifndef FOB_CLIENT_NETWORK_MESSAGE_H_
#define FOB_CLIENT_NETWORK_MESSAGE_H_

#include <string>
#include <sstream>

#include <boost/uuid/uuid.hpp>

namespace fob {
namespace client {
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

  enum ChatMessage {
    kChatSend,
    kChatChannel
  };

 public:
  Message(MessageType type);
  Message(const std::string &content);
  virtual ~Message();

  std::string GetString();

  void Inject(int var);
  void Inject(const std::string &var);
  void Inject(const boost::uuids::uuid &var);
  void Inject(StdMessage msg);
  void Inject(ChatMessage msg);

  MessageType GetType();

  void Extract(int &var);
  void Extract(std::string &var);
  void Extract(boost::uuids::uuid &var);
  void Extract(StdMessage &var);
  void Extract(ChatMessage &var);

 private:
  std::stringstream content_;
};

}  // namespace network
}  // namespace client
}  // namespace fob

#endif  // FOB_CLIENT_NETWORK_MESSAGE_H_
