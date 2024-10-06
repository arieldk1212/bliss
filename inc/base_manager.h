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

  void set_socket_address(const std::string& socket_ip_address) {
    if (m_socket_connection) {
      m_socket_connection->set_address(socket_ip_address);
    }
  }

  void connect() {
    m_socket_connection->connect_socket();
  }

  void send_data(const std::string& data) {
    m_socket_connection->send_socket(data);
  }

  std::string get_socket_response() {
    return m_socket_connection ? m_socket_connection->receive() : "";
  }

  std::string ssl(const std::string& url) { return m_socket_connection->ssl(url); }

  const std::string get_ip() const { return m_socket_connection->get_ip(); }

private:
  std::unique_ptr<Socket> m_socket_connection;
};

#endif