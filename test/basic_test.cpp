#include "../inc/bliss.h"

#include <cassert>
#include <cstddef>

int main () {
  std::string URL = "https://cdn-client.medium.com/lite/static/js/main.b2097cfb.js";
  std::unique_ptr<Request> req = std::make_unique<Request>();
  std::string data = req->get(URL);
  std::cout << data;
  // assert(req->get_host() == "cplusplus.com");

  // const std::string URL2 = "https://www.facebook.com";
  // std::unique_ptr<Request> req2 = std::make_unique<Request>();
  // req2->set_base_url(URL2);
  // req2->request_info();
  // assert(req2->get_host() == "www.facebook.com");
  return 0;
}