#include "response.h"
#include "../inc/bliss.h"

#include <cassert>

int main () {
  std::string URL = "https://cplusplus.com/reference/cassert/assert/";
  std::unique_ptr<Request> req = std::make_unique<Request>();
  Response res { req->get(URL) };
  res.print_response();

  std::string dummy_data; // TODO: implement a test for post method

  // std::string URL2 = "https://www.example.com/";
  // std::unique_ptr<Request> req2 = std::make_unique<Request>();
  // Response res2 { req->get(URL2) };
  // res2.print_response();
  // assert(req->get_host() == "cplusplus.com");

  return 0;
}
