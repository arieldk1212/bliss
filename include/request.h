/*
:REQUEST EXAMPLE:
std::string path = "/reference/cassert/assert/";
std::string host = "cplusplus.com";
std::string request = "GET " + path + " HTTP/1.1\n";
request += "Accept: text/html\n";
request += "Connection: keep-alive\n";
request += "Host: " + host + "\n";
request += "User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/128.0.0.0 Safari/537.36\n";
request += "\n";
*/

// need to configure request size, ssl handshake, need to add Headers!!!!!

#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include "base.h"
#include "utils.h"
#include "response.h"

const std::string PROTOCOL_VERSION = "HTTP/1.1";

class Request {
public:
  Request();
  Request(std::string& url);
  Request(std::string& url, std::string& username, std::string& password); // need to fix ip_address, port.

  ~Request();

  std::string set_parse_host(std::string& url);
  std::string set_parse_path(std::string& url);

  void set_request_data(std::string& request_data);
  void set_basic_auth(std::string& username, std::string& password);
  void set_url_host();
  void set_url_path();

  Response get();
  Response post();
  Response put();
  Response patch();
  Response del();
  Response options();
  Response head();

private:
  Socket* m_client_socket;
  std::string m_request_data;
  std::string m_user_agent = generate_user_agent();
  std::string m_base_url;
  std::string m_url_host;
  std::string m_url_path;
  std::string m_url_ip; // need to figure out for the socket constructor.
  struct {
    std::string m_username;
    std::string m_password;
  } m_basic_auth;
};

#endif