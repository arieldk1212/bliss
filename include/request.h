/*
:REQUEST EXAMPLE:
std::string path = "/reference/cassert/assert/";
std::string request = "GET /refrence/cassert/asset HTTP/1.1\n";
request += "Host: cplusplus.com\n";
request += "User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/128.0.0.0 Safari/537.36\n";
request += "Accept: star/star\n";
request += "Connection: keep-alive\n";
request += "\n";
*/

// TODO need to configure request size, ssl handshake, need to add Headers!!!!! header class, response class, http .h that includes all the lib header files.

#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include "base.h"
#include "utils.h"
#include "response.h"

class Request {
public:
  Request();
  // INFO set to const due to rvalue we are when passing string that isnt allocated, ref to manage mem allo.
  // (std::string&& x) -> only rvalue accepted | (const std::string& x) -> rvalue and lvalue accepted | (std::string& x) -> only lvalue accepted.
  // (std::string x) -> every thing.
  // can also overload it in a ctor -> most pref!
  // lvalue - storage, rvalue - temp.
  Request(const std::string& url);
  Request(const std::string& url, const std::string& username, const std::string& password);

  ~Request();

  const std::string PROTOCOL_VERSION = "HTTP/1.1";

  void set_base_url(const std::string& url);
  void set_request_data(const std::string& request_data);
  void set_basic_auth(const std::string& username, const std::string& password);
  void set_url_host();
  void set_host_ip();


  Response get();
  Response post();
  Response put();
  Response patch();
  Response del();
  Response options();
  Response head();

private:
  Socket* m_client_socket;
  const uint16_t HTTPS_PORT = 443; // TODO rethink that initialization.

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