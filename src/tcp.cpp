#include "../include/tcp.h"

#define DEFAULT_PORT 8080
#define DEFAULT_HOST "127.0.0.1"
#define BUFFERLENGTH 80 * 1024

Socket::Socket()
: m_socket_ip_address(DEFAULT_HOST), m_socket_port(DEFAULT_PORT), socket_fd(-1) {
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    std::cerr << "Failed to Create Socket." << "\n";
    exit(EXIT_SUCCESS);
  }
}

Socket::Socket(const char* ip, uint16_t port)
: m_socket_ip_address(ip), m_socket_port(port), socket_fd(-1) {
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    std::cerr << "Failed to Create Socket." << "\n";
    exit(EXIT_SUCCESS);
  }
}

Socket:: ~Socket() { close_socket(); }

const Socket& Socket::socket_info() const { return *this; }

void Socket::set_ip_address(const char* socket_ip_address) { m_socket_ip_address = socket_ip_address; }
void Socket::set_port(uint16_t socket_port) { m_socket_port = socket_port; }

void Socket::connect_socket() {
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_addr.s_addr = inet_addr(m_socket_ip_address);
  server_addr.sin_port = htons(m_socket_port);

  if (inet_pton(AF_INET, m_socket_ip_address, &server_addr.sin_addr) <= 0) {
    perror("error");
  } else {}

  if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
  } else {}
}

void Socket::send_socket() {
  std::string path = "/authors.txt";
  std::string host = "data.pr4e.org";
  std::string request = "GET " + path + " HTTP/1.1\n";
  request += "Host: " + host + "\n";
  request += "User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/128.0.0.0 Safari/537.36\n";
  request += "\n";
  std::cout << request << "\n";
  int bytes = send(socket_fd, request.c_str(), request.length(), 0);
}

void Socket::close_socket() {
  if (socket_fd != -1) {
    close(socket_fd);
  }
}