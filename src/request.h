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

#include <string>

class Request {
public:
  Request();
  ~Request() = default;

  void get();
  void head();
  void post();
  void patch();
  void put();
  void options();
  void del();

private:
  std::string m_request_data;
  std::string m_base_url;
  std::string m_user_agent;
  struct {
    std::string username;
    std::string password;
  } m_basic_auth;
};

#endif