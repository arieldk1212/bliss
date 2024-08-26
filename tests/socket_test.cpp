#include "../include/tcp.h"

int main () {
  Socket* socket = new Socket("162.159.137.70", 443);
  
  socket->connect_socket();
  socket->send_socket();
  std::cout << socket->receive();

  delete socket;

  return 0;
}