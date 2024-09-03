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

#ifndef REQUEST_H
#define REQUEST_H

#include "base.h"
#include "response.h"
#include <string>

const std::string PROTOCOL_VERSION = "HTTP/1.1";

class Request {
public:
  Request();
  ~Request() = default;

  // need to declare all the http actions here, consider the return value.

private:
  std::string m_request_data;
  std::string m_base_url; // need to divide into host, path.
  std::string m_user_agent;
  struct { // optional
    std::string username;
    std::string password;
  } m_basic_auth;
};

#endif