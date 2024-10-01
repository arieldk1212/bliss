#include "../inc/bliss.h"
#include <memory>
#include <cassert>

int main () {
  std::string URL = "https://cplusplus.txt/reference/cassert/assert";
  std::unique_ptr<Request> req = std::make_unique<Request>();
  // req->set_base_url(URL);
  // req->request_info();
  std::string data = req->get(URL);
  // Response res(req->get(URL));
  // res.view_data();
  // req->request_info();
  // assert(req->get_host() == "cplusplus.com");

  // const std::string URL2 = "https://www.facebook.com";
  // std::unique_ptr<Request> req2 = std::make_unique<Request>();
  // req2->set_base_url(URL2);
  // req2->request_info();
  // assert(req2->get_host() == "www.facebook.com");
  return 0;
}