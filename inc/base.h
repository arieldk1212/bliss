#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string>

#define BUFFER_LENGTH 80 * 1024

class Socket {
public:
  Socket(int socket_port);
  Socket(const std::string& socket_ip_address, int socket_port);
  ~Socket() = default;

  Socket(Socket&& socket); // Move
  Socket& operator=(Socket&& Socket) noexcept; // Move Assignment Operator
  Socket(const Socket&) = delete; // Not Allow Copy
  Socket& operator=(const Socket&) = delete; // Of Any Type

  const Socket& socket_info() const; 
  const std::string get_ip() const;

  void set_port(int socket_port);
  void set_address(const std::string& socket_ip_address);
  // INFO socket_info(const *this), returns const *this (unchangeable).
public:
  void connect_socket();
  void terminate();
  void send_socket(const std::string& request);
  std::string receive();
private:
  std::string m_socket_address;
  int m_socket_port;
  int m_socket_fd;
};

#endif
