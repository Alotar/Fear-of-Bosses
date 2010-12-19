#include <iostream>

#include "manager.h"
#include "network/networkexception.h"

int main(int argc, char *argv[]) {
  std::cout << "Loading server. Port is 30123" << std::endl;

  try {
    fob::server::Manager manager(30123);
    manager.Run();
  }
  catch (fob::server::network::NetworkException &e) {
    std::cout << "Server quit with the following error: " << e.message() << std::endl;
    return 1;
  }
  return 0;
}
