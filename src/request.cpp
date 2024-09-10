#include "../include/request.h"

Request::Request() {
  m_client_socket = new Socket;
  m_client_socket->set_port(443);
}

Request::Request(std::string& url) {
  m_client_socket = new Socket;
  m_client_socket->set_port(443);
  m_base_url = url;
}

Request::Request(std::string& url, std::string& username, std::string& password) {
  m_client_socket = new Socket;
  m_client_socket->set_port(443);
  m_base_url = url;
  m_basic_auth.m_username = username;
  m_basic_auth.m_password = password;
}

Request::~Request() { delete m_client_socket; }

void Request::set_request_data(std::string& request_data) { m_request_data = request_data; }
void Request::set_basic_auth(std::string& username, std::string& password) { m_basic_auth.m_username = username; m_basic_auth.m_password = password; }