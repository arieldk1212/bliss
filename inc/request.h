#ifndef REQUEST_H
#define REQUEST_H

#include "url.h"
#include "response.h"
#include "base_manager.h"

#include <iostream>

class Request {
public:
  const static inline std::string PROTOCOL_VERSION = "HTTP/1.1";
  enum class Method { GET, POST, PUT, PATCH, DELETE, OPTIONS, HEAD, TRACE };

  Request();
  ~Request();

  void set_request_start_line(Method method);
  void set_request_data();
  void expend_request_data(std::string&& data);
  void reset_request_data();
public:
  std::string to_string(Method method);
  std::string send_request(Method method, const std::string& url);

  std::string get(const std::string& url, int timeout = 0);
  Response post(const std::string& url, const std::string& object);
  Response put();
  Response patch();
  Response del();
  Response options();
  Response head();
  Response trace();
private:
  SocketManager m_client_socket;
  Url m_url;
  std::string m_request_response; // INFO: raw data from the request.
  std::string m_request_data; // INFO: request ready data.
  std::string m_request_start_line;
  std::string m_user_agent = generate_user_agent();
  struct {
    std::string m_username;
    std::string m_password;
  } m_basic_auth;
};

#endif
