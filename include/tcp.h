#ifndef TCP_H
#define TCP_H

#include <iostream>
#include <cstring>
#include <cstdint>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string>
#include <string.h>

#define DEFAULT_PORT 443 // http
#define DEFAULT_HOST "127.0.0.1"
#define BUFFER_LENGTH 80 * 1024

class Socket {
public:
  Socket();
  Socket(std::string ip, uint16_t port);
  ~Socket();

  // socket_info(const *this), returns const *this (unchangeable).
  const Socket& socket_info() const;

  void set_ip_address(std::string socket_ip_address);
  void set_port(uint16_t socket_port);
  std::string get_ip_address();
  uint16_t get_port();

  void connect_socket();
  bool send_socket();
  std::string receive();
  bool close_socket();

private:
  std::string m_socket_ip_address;
  uint16_t m_socket_port;
  int socket_fd;
};


// TODO: 
// 1. make it generic for future updates, maybe user-agent or server.
//    class ClientSocket : public Socket {};

#endif