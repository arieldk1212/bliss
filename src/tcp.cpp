#include "../include/tcp.h"

Socket::Socket()
: socket_fd(-1) {
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    std::cerr << "Failed to Create Socket." << "\n";
    exit(EXIT_SUCCESS);
  }
}

Socket::Socket(std::string ip, uint16_t port)
: m_socket_address(ip), m_socket_port(port), socket_fd(-1) {
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    std::cerr << "Failed to Create Socket." << "\n";
    exit(EXIT_SUCCESS);
  }
}

Socket:: ~Socket() { close_socket(); }

const Socket& Socket::socket_info() const { return *this; }

void Socket::set_address(std::string socket_ip_address) { m_socket_address = socket_ip_address; }
void Socket::set_port(uint16_t socket_port) { m_socket_port = socket_port; }
std::string Socket::get_ip_address() { return m_socket_address; }
uint16_t Socket::get_port() { return m_socket_port; }

void Socket::connect_socket() {
  struct sockaddr_in server_addr;
  server_addr.sin_addr.s_addr = inet_addr(m_socket_address.c_str());
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(m_socket_port);
  if (inet_pton(AF_INET, m_socket_address.c_str(), &server_addr.sin_addr) <= 0) {
    perror("inet_pton error");
  }

  if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
  }
}

void Socket::send_socket() {
  std::string path = "/reference/cassert/assert/";
  std::string host = "cplusplus.com";
  std::string request = "GET " + path + " HTTP/1.1\n";
  request += "Accept: text/html\n";
  request += "Connection: keep-alive\n";
  request += "Host: " + host + "\n";
  request += "User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/128.0.0.0 Safari/537.36\n";
  request += "Accept: */*\n";
  request += "\n";

  if (send(socket_fd, request.c_str(), strlen(request.c_str()), 0) < 0) {
    perror("send error: ");
  } std::cout << "**data sent**" << "\n";
}

std::string Socket::receive() {
  char buffer[BUFFER_LENGTH];
  std::string replay;
  if (recv(socket_fd, buffer, sizeof(buffer), 0) < 0) {
    puts("recv failed");
  } replay = buffer; return replay;
}

void Socket::close_socket() {
  close(socket_fd);
  std::cout << "**closed**" << "\n";
} 