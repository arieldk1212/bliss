#ifndef REQUEST_H
#define REQUEST_H

#include "url.h"
#include "response.h"
#include "base_manager.h"

class Request {
public:

  enum class Method { GET, POST, PUT, PATCH, DELETE, OPTIONS, HEAD, TRACE };
  inline static std::string PROTOCOL_VERSION = "HTTP/1.1";

  Request();
  ~Request();

  void set_request_start_line(std::string&& method);
  void set_request_data();
  void expand_request_data(std::string&& data);
  void reset_request_data();

public:
  std::string get(const std::string& url);
  Response post(const std::string& url, const std::string& object);
  Response put();
  Response patch();
  Response del();
  Response options();
  Response head();
  Response trace();
  void handle_method();

private:
  SocketManager m_client_socket;
  // int m_timeout; // TODO: just make it inside the methods..
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