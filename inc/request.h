#ifndef REQUEST_H
#define REQUEST_H

#include "base.h"
#include "utils.h"
#include "response.h"
#include "headers.h"

#include <string>
#include <memory>
#include <optional>
#include <cctype>

const std::string PROTOCOL_VERSION = "HTTP/1.1";
constexpr uint16_t HTTPS_PORT = 443;

class Request {
public:
  Request();
  ~Request();

  void request_info();
  const std::string get_host() const;

  void set_timeout(int timeout);
  void set_base_url(const std::string& url);
  void set_basic_auth(const std::string& username, const std::string& password);

  void set_request_start_line(std::string&& method);
  void set_request_data();
  void handle_method();
  void expand_request_data(std::string&& data);
  void reset_request_data();

  std::string get(const std::string& url); // INFO: should debug -> only above c++17.
  Response post(const std::string& url, const std::string& object);
  Response put();
  Response patch();
  Response del();
  Response options();
  Response head();
  Response trace();

private:
  void set_url_host();
  void set_host_ip();
private:
  Socket* m_client_socket = nullptr;
  Headers m_headers;
  int m_timeout;
  std::string m_base_url;
  std::string m_url_host;
  std::string m_request_endpoint; // INFO: initialized inside the method functions.
  std::string m_host_ip;
  std::string m_request_response; // INFO: raw data from the request.
  std::string m_request_data; // INFO: raw data from the request.
  std::string m_request_start_line;
  std::string m_user_agent = generate_user_agent();
  struct {
    std::string m_username;
    std::string m_password;
  } m_basic_auth;
};

#endif