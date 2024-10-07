#include "../inc/bliss.h"

#include <cassert>

int main () {
  std::string URL = "https://cplusplus.com/reference/cassert/assert/";
  std::string URL2 = "https://www.example.com/";
  std::unique_ptr<Request> req = std::make_unique<Request>();
  std::string data = req->get(URL2);
  std::cout << data;
  // assert(req->get_host() == "cplusplus.com");

  // const std::string URL2 = "https://www.facebook.com";
  // std::unique_ptr<Request> req2 = std::make_unique<Request>();
  // req2->set_base_url(URL2);
  // req2->request_info();
  // assert(req2->get_host() == "www.facebook.com");
  return 0;
}