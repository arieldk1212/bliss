#ifndef BASE_MANAGER_H
#define BASE_MANAGER_H

#include "base.h"

#include <memory>

class SocketManager {
public:
  void create_connection(int port = 443) {
    m_socket_connection = std::make_unique<Socket>(port); 
  }

  void release_connection() {
    if (m_socket_connection) {
      m_socket_connection.reset(); 
    }
  }

  const std::string get_ip() const { return m_socket_connection->get_ip(); }

  void set_socket_address(const std::string& socket_ip_address) {
    if (m_socket_connection) {
      m_socket_connection->set_address(socket_ip_address);
    }
  }

  std::string ssl_connect(const std::string& url) {
    return m_socket_connection ? std::move(m_socket_connection->socket_ssl(url)): "";
  }
private:
  std::unique_ptr<Socket> m_socket_connection;
};

#endif