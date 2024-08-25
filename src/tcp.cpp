#include "../include/tcp.h"

Socket::Socket()
: m_socket_ip_address(DEFAULT_HOST), m_socket_port(DEFAULT_PORT), socket_fd(-1) {
  // socket initialization
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    std::cerr << "Failed to Create Socket." << "\n";
    exit(EXIT_SUCCESS);
  } std::cout << "Socket Created." << "\n";
}

Socket::Socket(const char* ip, uint16_t port)
: m_socket_ip_address(ip), m_socket_port(port), socket_fd(-1) {
  // socket initialization
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    std::cerr << "Failed to Create Socket." << "\n";
    exit(EXIT_SUCCESS);
  } std::cout << "Socket Created." << "\n";
}

Socket:: ~Socket() { close_socket(); std::cout << "Socket Deleted Successfully." << "\n"; }

void Socket::set_ip_address(const char* socket_ip_address) { m_socket_ip_address = socket_ip_address; }
void Socket::set_port(uint16_t socket_port) { m_socket_port = socket_port; }

const Socket& Socket::socket_info() const { 
  std::cout << "SOCKET INFO - IP: " << m_socket_ip_address << ", PORT: " << m_socket_port << ".\n"; 
  return *this;
}

void Socket::connect_socket() {
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(m_socket_port);

  if (inet_pton(AF_INET, m_socket_ip_address, &server_addr.sin_addr) <= 0) {
    perror("error");
  } else { std::cout << "Address OK." << "\n"; }

  if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
  } else { std::cout << "Connected Successfully." << "\n"; }
}

void Socket::close_socket() {
  if (socket_fd != -1) {
    close(socket_fd);
    std::cout << "Socket Closed Successfully." << "\n";
  }
}