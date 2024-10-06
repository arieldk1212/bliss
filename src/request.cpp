#include "../inc/request.h"

Request::Request() { m_client_socket.create_connection(); }

Request::~Request() { m_client_socket.release_connection(); }

void Request::set_request_start_line(Method method) {
  std::string start_line = "";
  start_line += to_string(method) + " ";
  start_line += m_url.get_endpoint() + " ";
  start_line += PROTOCOL_VERSION + "\r\n";
  m_request_start_line = start_line;
}

void Request::set_request_data() {
  m_request_data += m_request_start_line;
  m_request_data += "User-Agent: " + m_user_agent + "\r\n";
  m_request_data += "Accept: */*\r\n";
  m_request_data += "Host: " + m_url.get_host() + "\r\n";
  m_request_data += "Connection: keep-alive\r\n";
  m_request_data += "\r\n"; 
}

void Request::expand_request_data(std::string &&data) {
  m_request_data += data + "\n";
}

void Request::reset_request_data() { m_request_data.clear(); }

std::string Request::to_string(Method method) {
  switch (method) {
    case Method::GET: return "GET";
    case Method::POST: return "POST";
    case Method::PUT: return "PUT";
    case Method::PATCH: return "PATCH";
    case Method::DELETE: return "DELETE";
    case Method::OPTIONS: return "OPTIONS";
    case Method::HEAD: return "HEAD";
    case Method::TRACE: return "TRACE";
  }
}

std::string Request::send_request(Method method, const std::string& url) {
  m_url.parse(url);
  set_request_start_line(method);
  set_request_data();
  m_client_socket.set_socket_address(m_url.get_ip());
  m_request_response = m_client_socket.socket_ssl(url);
  return m_request_response;
}

std::string Request::get(const std::string& url, int timeout) {
  // TODO: implement timeout finctionallity here.
  return send_request(Method::GET, url);
}