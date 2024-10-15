#include "response.h"
#include <future>
#include <stdexcept>
#include "../inc/request.h"

Request::Request() { m_client_socket.create_connection(); }

Request::~Request() { m_client_socket.release_connection(); }

void Request::set_url(const std::string& url_) { m_url.parse(url_); }

void Request::set_body(const std::string& body_) { m_request_body = body_; }

void Request::add_header(std::string&& header_) { m_header + std::move(header_); }

void Request::set_request_start_line(Method method) {
  std::string start_line = to_string(method) + " ";
  start_line += m_url.get_endpoint() + " ";
  start_line += PROTOCOL_VERSION + "\r\n";
  m_request_data = std::move(start_line);
}

void Request::build_headers() {
  m_header + ("User-Agent: " + generate_user_agent());
  m_header + "Accept: */*";
  m_header + ("Host: " + m_url.get_host());
  m_header + "Accept-Encoding: gzip";
  m_header + "Connection: keep-alive";
}

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

template<typename F, typename... Args>
auto timeout(F&& f, std::chrono::milliseconds timeout, Args&&... args) {
  auto task = std::packaged_task<decltype(f(args...))()> (
    std::bind(std::forward<F>(f), std::forward<Args>(args)...)
  );
  auto future = task.get_future();
  std::thread(std::move(task)).detach();
  if (future.wait_for(timeout) == std::future_status::ready) { return future.get(); }
  else { throw std::runtime_error("request timed out"); }
}

Response Request::send_request(Method method, const std::string& url) {
  m_url.parse(url); // INFO: inits the IP, Host, Endpoint
  set_request_start_line(method); // INFO: Creates the start line in m_request_data
  build_headers(); // INFO: builds the headers
  m_header.serialize(m_request_data); // INFO: sets the headers in m_request_data
  m_client_socket.set_socket_address(m_url.get_ip());
  // std::string response = m_client_socket.ssl_connect(url);
  std::string response = timeout(m_client_socket.ssl_connect(url), std::chrono::milliseconds(3000));

  return Response(std::move(response));
}

Response Request::get(const std::string& url, int timeout) {
  return send_request(Method::GET, url);
}

Response Request::post(const std::string& url) {
  return send_request(Method::POST, url);
}