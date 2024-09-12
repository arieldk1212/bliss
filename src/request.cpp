#include "../include/request.h"

Request::Request() {
  m_client_socket = new Socket;
  m_client_socket->set_port(HTTPS_PORT);
}

Request::Request(const std::string& url) {
  m_client_socket = new Socket;
  m_client_socket->set_port(HTTPS_PORT);
  m_base_url = url;
  set_url_host();
  set_host_ip();
  m_client_socket->set_address(m_host_ip);
}

Request::Request(const std::string& url, const std::string& username, const std::string& password) {
  m_client_socket = new Socket;
  m_client_socket->set_port(HTTPS_PORT);
  m_base_url = url;
  set_url_host();
  set_host_ip();
  m_client_socket->set_address(m_host_ip);
  m_basic_auth.m_username = username;
  m_basic_auth.m_password = password;
}

Request::~Request() { delete m_client_socket; }

void Request::set_base_url(const std::string& url) {
  m_base_url = url;
  set_url_host();
  set_host_ip();
  m_client_socket->set_address(m_host_ip);
}
void Request::set_request_data(const std::string& request_data) { m_request_data = request_data; }
void Request::set_basic_auth(const std::string& username, const std::string& password) { m_basic_auth.m_username = username; m_basic_auth.m_password = password; }
void Request::set_url_host() { m_url_host = url_to_host(m_base_url); }
void Request::set_host_ip() { m_host_ip = host_to_ip(m_url_host); }

Response Request::get() {

}