#include "../inc/base.h"


Socket::Socket(int socket_port)
: m_socket_fd(-1), m_socket_port(socket_port) {
  m_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (m_socket_fd == -1) {
    throw std::runtime_error("socket creation error \n");
    exit(EXIT_SUCCESS); }
}
Socket::Socket(const std::string& socket_ip_address, int socket_port)
: m_socket_address(socket_ip_address), m_socket_port(socket_port), m_socket_fd(-1) {
  m_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socket_fd == -1) {
    throw std::runtime_error("socket creation error \n");
    exit(EXIT_SUCCESS); }
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

const Socket& Socket::socket_info() const { return *this; }
const std::string Socket::get_ip() const { return m_socket_address; }

void Socket::set_port(int socket_port) { m_socket_port = socket_port; }
void Socket::set_address(const std::string& socket_ip_address) { m_socket_address = socket_ip_address; }

void Socket::connect_socket() {
  struct sockaddr_in server_addr;
  server_addr.sin_addr.s_addr = inet_addr(m_socket_address.c_str());
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(m_socket_port);
  if (inet_pton(AF_INET, m_socket_address.c_str(), &server_addr.sin_addr) <= 0) {
    throw std::runtime_error("inet_pton error"); }
  if (connect(m_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    throw std::runtime_error("connect error"); }
}

void Socket::terminate() { if (m_socket_fd) { close(m_socket_fd); }}

void Socket::send_socket(const std::string& request) {
  if (send(m_socket_fd, request.c_str(), strlen(request.c_str()), 0) < 0) {
    throw std::runtime_error("send error"); }
}

std::string Socket::receive() {
  char buffer[BUFFER_LENGTH];
  std::string replay;
  if (recv(m_socket_fd, buffer, sizeof(buffer), 0) < 0) {
    throw std::runtime_error("recv failed");
  } replay = buffer;
  return replay;
}

std::string Socket::ssl(const std::string& request) {
  int err;
  int sd;
  struct sockaddr_in sa;
  SSL_CTX* ctx;
  SSL*     ssl;
  X509*    server_cert;
  char*    str;
  char     buf [4096];
  const SSL_METHOD *meth;

  OpenSSL_add_ssl_algorithms();
  meth = TLS_client_method();
  SSL_load_error_strings();
  ctx = SSL_CTX_new (meth);
  memset(&sa, 0, sizeof(sa));
  sa.sin_family      = AF_INET;
  sa.sin_addr.s_addr = inet_addr (m_socket_address.c_str());   /* Server IP */
  sa.sin_port        = htons     (m_socket_port);
  err = connect(m_socket_fd, (struct sockaddr*) &sa,
  sizeof(sa));
  ssl = SSL_new (ctx);
  SSL_set_fd(ssl, m_socket_fd);
  err = SSL_connect(ssl);
  err = SSL_write (ssl, request.c_str(), strlen(request.c_str()));
  err = SSL_read(ssl, buf, sizeof(buf) - 1);
  std::string replay = buf;
  buf[err] = '\0';
  SSL_shutdown(ssl);
  close(m_socket_fd);
  SSL_free(ssl);
  SSL_CTX_free(ctx);
  return replay;
}