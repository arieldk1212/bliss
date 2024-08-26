#include "../include/tcp.h"

int main () {
  Socket* socket = new Socket("127.0.0.1", 8080);
  
  socket->connect_socket();
  // socket->send_socket();

  delete socket;

  return 0;
}