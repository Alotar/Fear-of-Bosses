#include <iostream>

#include "manager.h"
#include "network/networkexception.h"

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " ip port." << std::endl;
    return 1;
  }
  try {
    std::string ip = argv[1];
    uint16_t port = atoi(argv[2]);

    fob::client::Manager manager(ip, port);

    manager.Init();
    manager.Run();
  }
  catch (fob::client::network::NetworkException &e) {
    std::cout << "Client quit with following error: " << e.message() << std::endl;
    return 1;
  }
  return 0;
}
