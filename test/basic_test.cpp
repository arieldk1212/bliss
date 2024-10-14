#include "../inc/bliss.h"

#include <cassert>

int main () {
  std::string URL = "https://cplusplus.com/reference/cassert/assert/";
  std::string URL2 = "https://www.example.com/";
  std::unique_ptr<Request> req = std::make_unique<Request>();
  std::unique_ptr<Request> req2 = std::make_unique<Request>();
  // std::string data = req->get(URL);
  // std::string data2 = req2->get(URL2);
  // std::cout << data;
  // std::cout << data2;
  // assert(req->get_host() == "cplusplus.com");

  return 0;
}
