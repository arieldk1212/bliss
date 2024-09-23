#include "../inc/request.h"

Request::Request() {
  m_client_socket = new Socket;
  m_client_socket->set_port(HTTPS_PORT);
}

/* TODO: delete these implementations.
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
*/

Request::~Request() { delete m_client_socket; }

void Request::request_info() {
  std::cout << "URL: " << m_base_url << "\n" <<
  "Host: " << m_url_host << "\n" << "IP: " << m_host_ip << "\n" <<
  "User-Agent: " << m_user_agent << "\n";
}
const std::string Request::get_host() const { return m_url_host; }

void Request::set_timeout(int timeout) { m_timeout = timeout; }
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

std::string&& Request::handle_method(std::string&& safe_method) {
 // TODO: handles the socket connection, sending, recieveing -> the generic stuff between all the methods.
}

Response Request::get(const std::string& url, std::optional<int> timeout) {
  set_base_url(url);
  m_request_endpoint = url_to_endpoint(url);
  // try {
  //   m_client_socket->connect_socket();
  // } catch (...) {
  //   perror("error");
  // } try {
  //   m_client_socket->send_socket(request);
  // }
}