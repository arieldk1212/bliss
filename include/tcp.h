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

#define BUFFER_LENGTH 80 * 1024

class Socket {
public:
  Socket();
  Socket(std::string, uint16_t);
  ~Socket();

  // socket_info(const *this), returns const *this (unchangeable).
  const Socket& socket_info() const;

  void set_address(std::string);
  void set_port(uint16_t);
  std::string get_ip_address();
  uint16_t get_port();

  void connect_socket();
  void send_socket();
  std::string receive();
  void close_socket();

private:
  std::string m_socket_address;
  uint16_t m_socket_port;
  int socket_fd;
};

#endif