#ifndef BASE_H
#define BASE_H

#include <string>
#include <unistd.h>
#include <stdexcept>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <openssl/crypto.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_LENGTH 80 * 1024

class Socket {
public:
  Socket(int socket_port);
  Socket(const std::string& socket_ip_address, int socket_port);
  ~Socket();

  Socket(Socket&& socket) noexcept; // Move
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

  std::string ssl(const std::string& url);
private:
  std::string m_socket_address;
  int m_socket_port;
  int m_socket_fd;
};

#endif
