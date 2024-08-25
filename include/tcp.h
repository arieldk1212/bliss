#ifndef TCP_H
#define TCP_H

#include <sys/socket.h>
#include <cstdint>
#include <iostream>

#define LOCALHOST "127.0.0.1"
#define PORT 8080

class Socket {
public:
  Socket()
  : m_socket_ip_address(LOCALHOST), m_socket_port(PORT) {};
  Socket(const char* ip, uint16_t port)
  : m_socket_ip_address(ip), m_socket_port(port) {}
  virtual ~Socket() { std::cout << "Socket Deleted."; }

  void set_ip_address(const char* socket_ip_address) { m_socket_ip_address = socket_ip_address; }
  void set_port(uint16_t socket_port) { m_socket_port = socket_port; }

  const Socket& socket_info() const { return *this; }
private:
  const char* m_socket_ip_address;
  uint16_t m_socket_port;
};


// make it generic for future updates, maybe user-agent or server.
class ClientSocket : public Socket {
private:

};

#endif