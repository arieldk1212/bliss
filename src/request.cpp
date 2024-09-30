#include "../inc/request.h"

Request::Request() {
  m_client_socket = new Socket;
  m_client_socket->set_port(HTTPS_PORT);
}

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
void Request::set_basic_auth(const std::string& username, const std::string& password) { m_basic_auth.m_username = username; m_basic_auth.m_password = password; }
void Request::set_url_host() { m_url_host = url_to_host(m_base_url); }
void Request::set_host_ip() { m_host_ip = host_to_ip(m_url_host); }

void Request::set_request_start_line(std::string&& method) {
  std::string start_line = "";
  start_line += method + " "; // INFO: method isnt turned into capital, can be done with toupper.
  start_line += m_request_endpoint + " ";
  start_line += PROTOCOL_VERSION + "\n";
  m_request_start_line = start_line;
}
void Request::set_request_data() {
  // INFO: this function sets the class member to the fully loaded and structured request, ready to send!!
  // INFO: currentyl a simple request, need to further explore.
  // INFO: Start, User-Agent, Accept, Host.
  m_request_data += m_request_start_line;
  m_request_data += "User-Agent: " + m_user_agent + "\n";
  m_request_data += "Accept: */* \n";
  m_request_data += "Host: " + m_url_host + "\n";
}
void Request::expand_request_data(std::string&& data) {
  m_request_data += data + "\n";
}
void Request::reset_request_data() {
  m_request_data = "";
}
void Request::handle_method() {
  m_client_socket->connect_socket();
  m_client_socket->send_socket(m_request_data);
  m_request_response = m_client_socket->receive(); // INFO: data member gets initialized with the request data.
  // TODO: implement timeout finctionallity here.
}

std::string Request::get(const std::string& url) {
  /* GET */
  set_base_url(url);
  m_request_endpoint = url_to_endpoint(url);
  set_request_start_line("GET");
  // TODO: handle the headers in here before sending the request.
  set_request_data();
  handle_method();
  return m_request_response;
}