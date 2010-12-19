#include "interfacemanager.h"

#include <iostream>

#include <cstdio>
#include <unistd.h>
#include <termios.h>

namespace fob {
namespace client {
namespace interface {

InterfaceManager::InterfaceManager() {}

InterfaceManager::~InterfaceManager() {}

void InterfaceManager::Print(Interface out, std::string &msg) {
  switch (out) {
    case kStandard:
      std::cout << msg;
    case kChat:
      std::cout << msg;
  }
}

std::string InterfaceManager::GetString(InterfaceManager::Interface in) {
  std::string msg;
  switch (in) {
    case kStandard:
      std::cin >> msg;
    case kChat:
      std::cout << "Chat: ";
      std::cin >> msg;
  }
  return msg;
}

char InterfaceManager::GetKeyPress() {
  struct termios old_terminal;
  struct termios new_terminal;
  tcgetattr(STDIN_FILENO, &old_terminal);
  new_terminal = old_terminal;
  new_terminal.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_terminal);
  char input = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal);
  return input;
}

}  // namespace interface
}  // namespace client
}  // namespace fob
