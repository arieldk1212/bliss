#include <memory>
#include "../include/bliss.h"

// ** SOCKET TESTING **

// int main () {
//   // Socket* socket = new Socket("54.39.7.252", 80);
//   std::unique_ptr<Socket> socket = std::make_unique<Socket>("54.39.7.252", 443);
//   socket->connect_socket();
//   // socket->send_socket();
//   std::cout << socket->receive();

//   return 0;
// }


// ** REQUEST TESTING **

int main () {
  const std::string URL = "https://cplusplus.com";
  std::unique_ptr<Request> req = std::make_unique<Request>(URL);
  req->request_info();

  const std::string URL2 = "https://www.facebook.com";
  std::unique_ptr<Request> req2 = std::make_unique<Request>(URL2);
  req2->request_info();
}