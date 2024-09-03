#include <memory>
#include "../include/base.h"
#include "../include/request.h"

int main () {
  // Socket* socket = new Socket("54.39.7.252", 80);
  std::unique_ptr<Socket> socket = std::make_unique<Socket>("54.39.7.252", 80);
  


  socket->connect_socket();
  // socket->send_socket();
  // std::cout << socket->receive();

  return 0;
}