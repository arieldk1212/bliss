#include "../inc/request.h"

Request::Request() { m_client_socket.create_connection(); }

Request::~Request() { m_client_socket.release_connection(); }

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
void Request::expand_request_data(std::string &&data) {
  m_request_data += data + "\n";
}
void Request::reset_request_data() {
  m_request_data = "";
}
void Request::handle_method() {
  m_client_socket.connect();
  m_client_socket.send_data(m_request_data);
  m_request_response = m_client_socket.get_socket_response(); // INFO: data member gets initialized with the request data.
  // TODO: implement timeout finctionallity here.
}

std::string Request::get(const std::string& url) {
  Url request_url(url);
  set_request_start_line("GET");
  // TODO: handle the headers in here before sending the request.
  set_request_data();
  handle_method();
  return m_request_response;
}