#ifndef REQUEST_H
#define REQUEST_H

#include "base.h"
#include "utils.h"
#include "response.h"
#include "headers.h"
#include <string>
#include <memory>
#include <optional>

const std::string PROTOCOL_VERSION = "HTTP/1.1";
constexpr uint16_t HTTPS_PORT = 443;

// TODO: change the ctor of request to not accept url, do it in the http method itself, OR  call the ctor of request inside the http method function.
// TODO: need to handle the referer -> direction in case the url isnt provided correctly, status code 304. (in case a / is missing..),
//       in this case we need to call the request twice, in the first one the response returns a location header value, if yes the request url will be 
//       turned into it, and the next request will have a referer header value with the previous url, but the new request url will be the 
//       the value that was in the location header (in the response in the first request). status code 301.
class Request {
public:
  Request();
  // Request(const std::string& url);
  // Request(const std::string& url, const std::string& username, const std::string& password);

  ~Request();

  void request_info();
  const std::string get_host() const;

  void set_timeout(int timeout);
  void set_base_url(const std::string& url);
  void set_request_data(const std::string& request_data);
  void set_basic_auth(const std::string& username, const std::string& password);

  void handle_method(std::string&& safe_method);

  // TODO: add timeout.
  Response get(const std::string& url, std::optional<int> timeout); // INFO: should debug -> only above c++17.
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
  std::string m_request_data;
  std::string m_user_agent = generate_user_agent();
  struct {
    std::string m_username;
    std::string m_password;
  } m_basic_auth;
};

#endif