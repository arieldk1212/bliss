#include "response.h"
#include "../inc/bliss.h"

#include <cassert>

int main () {
  std::string URL = "https://cplusplus.com/reference/cassert/assert/";
  std::string URL2 = "https://www.example.com/";
  std::unique_ptr<Request> req = std::make_unique<Request>();
  std::unique_ptr<Request> req2 = std::make_unique<Request>();
  // Response res { req->get(URL) };
  Response res2 { req2->get(URL) };
  res2.print_response();
  // assert(req->get_host() == "cplusplus.com");

  return 0;
}
