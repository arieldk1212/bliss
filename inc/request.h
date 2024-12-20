#ifndef REQUEST_H
#define REQUEST_H

#include "url.h"
#include "headers.h"
#include "response.h"
#include "base_manager.h"

#include <chrono>
#include <string.h>
#include <thread>
#include <future>
#include <iostream>

class Request {
public:
  static std::string PROTOCOL_VERSION;
  enum class Method { GET, POST, PUT, PATCH, DELETE, OPTIONS, HEAD, TRACE };

  Request();
  ~Request();

  void set_url(const std::string& url_);

  void set_body(const std::string& body_);

  void add_header(std::string&& header_);

  void set_request_start_line(Method method);
  void build_headers();
public:
  std::string to_string(Method method);
  void active_middleware(std::string&& method);
  Response send_request(Method method, const std::string& url);

  Response get(const std::string& url, int timeout = 0);
  Response post(const std::string& url);
  Response put();
  Response patch();
  Response del();
  Response options();
  Response head();
  Response trace();
private:
  SocketManager m_client_socket;
  Url m_url;
  Headers m_header;
  std::string m_request_data; // INFO: request ready data
  std::string m_request_body; // INFO: For Active Methods (POST, PULL)
};

#endif
