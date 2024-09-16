#ifndef REQUEST_H
#define REQUEST_H

#include "base.h"
#include "utils.h"
#include "response.h"
#include <string>

const std::string PROTOCOL_VERSION = "HTTP/1.1";
constexpr uint16_t HTTPS_PORT = 443;

class Request {
public:
  Request();
  Request(const std::string& url);
  Request(const std::string& url, const std::string& username, const std::string& password);

  ~Request();

  void request_info();
  void set_timeout(int timeout);
  void set_base_url(const std::string& url);
  void set_request_data(const std::string& request_data);
  void set_basic_auth(const std::string& username, const std::string& password);

  Response get();
  Response post();
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
  Socket* m_client_socket;
  int m_timeout;
  std::string m_base_url;
  std::string m_url_host;
  std::string m_host_ip;
  std::string m_request_data;
  std::string m_user_agent = generate_user_agent();
  struct {
    std::string m_username;
    std::string m_password;
  } m_basic_auth;
};

#endif