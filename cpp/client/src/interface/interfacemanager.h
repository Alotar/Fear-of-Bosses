#ifndef FOB_CLIENT_INTERFACE_INTERFACEMANAGER_H_
#define FOB_CLIENT_INTERFACE_INTERFACEMANAGER_H_

#include <string>

namespace fob {
namespace client {
namespace interface {

class InterfaceManager {
 public:
  enum Interface {
    kStandard,
    kChat
  };

 public:
  InterfaceManager();
  virtual ~InterfaceManager();
  
  void Print(Interface out, std::string &msg);
  std::string GetString(Interface in);
  char GetKeyPress();
};

}  // namespace interface
}  // namespace client
}  // namespace fob

#endif  // FOB_CLIENT_INTERFACE_INTERFACEMANAGER_H_
