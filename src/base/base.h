#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <cstring>
#include <cstdint>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string>
#include <string.h>

#define BUFFER_LENGTH 80 * 1024

class Socket {
public:
  Socket();
  Socket(std::string socket_ip_address, uint16_t socket_port);
  ~Socket();

  const Socket& socket_info() const; // socket_info(const *this), returns const *this (unchangeable).
  void set_port(uint16_t socket_port);
  void set_address(std::string socket_ip_address);

  void connect_socket();
  void send_socket(std::string request);
  std::string receive();
  void terminate();

private:
  std::string m_socket_address;
  uint16_t m_socket_port;
  int m_socket_fd;
};

#endif