#include <memory>
#include "../include/tcp.h"

int main () {
  // Socket* socket = new Socket("54.39.7.252", 80);
  std::unique_ptr<Socket> socket = std::make_unique<Socket>("127.0.0.1", 80);
  
  socket->connect_socket();
  socket->send_socket();
  std::cout << socket->receive();

  // delete socket;

  return 0;
}