#include <iostream>

#include "manager.h"

int main(int argc, char *argv[]) {
  std::cout << "Loading server. Port is 30123" << std::endl;
  fob::server::Manager manager(30123);
  manager.Run();
  return 0;
}
