#include "../inc/bliss.h"
#include <memory>
#include <cassert>

int main () {
  std::unique_ptr<Socket> socket = std::make_unique<Socket>("54.39.7.252", 443);
  assert(socket->get_ip() == "54.39.7.252");

  return 0;
}