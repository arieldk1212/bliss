#ifndef BASE_H
#define BASE_H

#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_LENGTH 80 * 1024

/* ERROR DETECTION DEFINES */
#define CHK_NULL(x) if ((x)==NULL) exit (1)
#define CHK_ERR(err,s) if ((err)==-1) { perror(s); exit(1); }
#define CHK_SSL(err) if ((err)==-1) { ERR_print_errors_fp(stderr); exit(2); }

class Socket {
public:
  Socket(int socket_port);
  Socket(const std::string& socket_ip_address, int socket_port);
  ~Socket();

  Socket(Socket&& socket) noexcept; // Move
  Socket& operator=(Socket&& Socket) noexcept; // Move Assignment Operator
  Socket(const Socket&) = delete; // Not Allow Copy
  Socket& operator=(const Socket&) = delete; // Of Any Type

  const Socket& get_socket_info() const;
  const std::string get_ip() const;

  void set_port(int socket_port);
  void set_address(const std::string& socket_ip_address);
  // INFO socket_info(const *this), returns const *this (unchangeable).
public:
  std::string socket_ssl(const std::string& url);
  void terminate();
private:
  int m_socket_fd;
  int m_socket_port;
  std::string m_socket_address;
};

#endif
