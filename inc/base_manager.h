#ifndef BASE_MANAGER_H
#define BASE_MANAGER_H

#include "base.h"
#include <memory>

class SocketManager {
public:
  inline void m_create_connection() { m_socket_connection = std::make_unique<Socket>(443); }
  inline void m_release_connection() { m_socket_connection.reset(); }

  inline void set_socket_address(const std::string& socket_ip_address) { m_socket_connection->set_address(socket_ip_address); }
  inline void get_socket_connection() { m_socket_connection->connect_socket(); }
  inline void send_data(const std::string& data) { m_socket_connection->send_socket(data); }
  inline std::string get_socket_response() { return m_socket_connection->receive(); }

private:
  std::unique_ptr<Socket> m_socket_connection;
};

#endif