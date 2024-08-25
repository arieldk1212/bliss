#ifndef TCP_H
#define TCP_H

#include <iostream>
#include <cstring>
#include <cstdint>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class Socket {
public:
  Socket();
  Socket(const char* ip, uint16_t port);
  ~Socket();

  void set_ip_address(const char* socket_ip_address);
  void set_port(uint16_t socket_port);

  // socket_info(const *this), returns const *this (unchangeable).
  const Socket& socket_info() const;

  void connect_socket();
  void close_socket();
  // for send function we need to call send and add in it -> socket, buffer (our case is data)
  // this funnction needs to accept the request!
  void send();

private:
  const char* m_socket_ip_address;
  uint16_t m_socket_port;
  int socket_fd;
};


// TODO: 
// 1. make it generic for future updates, maybe user-agent or server.
//    class ClientSocket : public Socket {};

#endif