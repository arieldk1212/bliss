#include "../inc/base.h"

Socket::Socket()
: m_socket_fd(-1) {
  m_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (m_socket_fd == -1) {
    std::cerr << "socket creation error" << "\n";
    exit(EXIT_SUCCESS); }
}
Socket::Socket(const std::string& socket_ip_address, uint16_t socket_port)
: m_socket_address(socket_ip_address), m_socket_port(socket_port), m_socket_fd(-1) {
  m_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (m_socket_fd == -1) {
    std::cerr << "socket creation error" << "\n";
    exit(EXIT_SUCCESS); }
}

Socket:: ~Socket() { terminate(); }

const Socket& Socket::socket_info() const { return *this; }
void Socket::set_port(uint16_t socket_port) { m_socket_port = socket_port; }
void Socket::set_address(const std::string& socket_ip_address) { m_socket_address = socket_ip_address; }

void Socket::connect_socket() {
  struct sockaddr_in server_addr;
  server_addr.sin_addr.s_addr = inet_addr(m_socket_address.c_str());
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(m_socket_port);
  if (inet_pton(AF_INET, m_socket_address.c_str(), &server_addr.sin_addr) <= 0) {
    perror("inet_pton error"); }
  if (connect(m_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect"); }
}

void Socket::terminate() { close(m_socket_fd); } 

// TODO add dynamic memory allocation in the buffer ( int* x = malloc(n * sizeof(int)); ), correct this function when needed.
void Socket::send_socket(const std::string& request) {
  if (send(m_socket_fd, request.c_str(), strlen(request.c_str()), 0) < 0) {
    perror("send error: "); }
}

std::string Socket::receive() {
  char buffer[BUFFER_LENGTH];
  std::string replay;
  if (recv(m_socket_fd, buffer, sizeof(buffer), 0) < 0) {
    puts("recv failed");
  } replay = buffer;
  return replay;
}