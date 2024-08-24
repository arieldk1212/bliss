#ifndef TCP_H
#define TCP_H

#include <sys/socket.h>
#include <cstdint>

// create basic client socket class, that will handle the socket and wait for responses from the user-agent server.
class ClientSocket {
private:
  const char* m_socket_ip_address;
  uint32_t m_socket_port;
public:
  ClientSocket(const char* ip, uint32_t port)
  : m_socket_ip_address(ip), m_socket_port(port) {}


};

#endif