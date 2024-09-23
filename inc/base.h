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
  Socket(const std::string& socket_ip_address, uint16_t socket_port);
  ~Socket();

  const Socket& socket_info() const; 
  const std::string get_ip() const;

  void set_port(uint16_t socket_port);
  void set_address(const std::string& socket_ip_address);
  // INFO socket_info(const *this), returns const *this (unchangeable).

public:
  void connect_socket();
  void terminate();
  void send_socket(const std::string& request);
  std::string receive();
private:
  std::string m_socket_address;
  uint16_t m_socket_port;
  int m_socket_fd;
};

#endif
