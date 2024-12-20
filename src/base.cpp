#include "../inc/base.h"

Socket::Socket(int socket_port)
: m_socket_fd(-1), m_socket_port(socket_port) {
  m_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (m_socket_fd < 0) {
    throw std::runtime_error("socket creation error \n"); }
}
Socket::Socket(const std::string& socket_ip_address, int socket_port)
: m_socket_address(socket_ip_address), m_socket_port(socket_port), m_socket_fd(-1) {
  m_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socket_fd < 0) {
    throw std::runtime_error("socket creation error \n"); }
}

Socket::~Socket() { terminate(); }

Socket::Socket(Socket&& socket) noexcept {
  m_socket_address = std::move(socket.m_socket_address);
  m_socket_port = std::move(socket.m_socket_port);
  m_socket_fd = std::move(socket.m_socket_fd);
}

Socket& Socket::operator=(Socket&& socket) noexcept {
  if (this != &socket) {
    m_socket_address = std::move(socket.m_socket_address);
    m_socket_port = std::move(socket.m_socket_port);
    m_socket_fd = std::move(socket.m_socket_fd);
    socket.m_socket_fd = -1;
  }
  return *this;
}

const Socket& Socket::get_socket_info() const { return *this; }
const std::string Socket::get_ip() const { return m_socket_address; }

void Socket::set_port(int socket_port) { m_socket_port = socket_port; }
void Socket::set_address(const std::string& socket_ip_address) { m_socket_address = socket_ip_address; }

void Socket::terminate() { if (m_socket_fd) { close(m_socket_fd); }}

std::string Socket::socket_ssl(const std::string& request) {
  int err;
  char buf[BUFFER_LENGTH] = {0};

  struct sockaddr_in sa;
  memset(&sa, 0,sizeof(sa));
  sa.sin_family = AF_INET;
  sa.sin_addr.s_addr = inet_addr(m_socket_address.c_str());
  sa.sin_port = htons(m_socket_port);
  inet_pton(AF_INET, m_socket_address.c_str(), &sa.sin_addr);

  err = connect(m_socket_fd, (struct sockaddr*) &sa, sizeof(sa));
  if (err < 0) {
    throw std::runtime_error("failed to connect");
  }

  SSL_library_init();
  SSL_load_error_strings();
  OpenSSL_add_ssl_algorithms();

  SSL_CTX* ctx = SSL_CTX_new (TLS_method());
  if (ctx == nullptr) { throw std::runtime_error("ctx error"); }
  SSL* ssl = SSL_new(ctx);
  if (ssl == nullptr) { throw std::runtime_error("ssl error"); }
  SSL_set_fd(ssl, m_socket_fd);
  err = SSL_connect(ssl); if (err == -1) { throw std::runtime_error("SSL connect error"); }
  err = SSL_write (ssl, request.c_str(), strlen(request.c_str())); if (err == -1) { throw std::runtime_error("SSL write error"); }
  err = SSL_read(ssl, buf, sizeof(buf) - 1); if (err == -1) { throw std::runtime_error("SSL read error"); }

  std::string replay = buf;
  SSL_shutdown(ssl);
  SSL_free(ssl);
  SSL_CTX_free(ctx);
  close(m_socket_fd);

  return replay;
}