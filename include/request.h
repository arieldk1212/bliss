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

// need to configure request size, ssl handshake, user-agent (from utils.h), need to add Headers!!!!!

#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include "base.h"
#include "utils.h"
#include "response.h"

const std::string PROTOCOL_VERSION = "HTTP/1.1";

class Request {
public:
  Request(); // here i can initialize the socket creation.. and wait for further commands.
  Request(std::string& url, std::string& username, std::string& password);

  ~Request() = default; // here i need to delete the socket ptr

  std::string set_parse_host(std::string& url);
  std::string set_parse_path(std::string& url);

  void set_request_data(std::string& request_data);
  void set_basic_auth(std::string& username, std::string& password);
  void set_user_agent(std::string& user_agent);
  void set_url_host();
  void set_url_path();

  Response get(); // in here we need to construct it with the base.h file ( socket configuration ), using unique_ptr
  Response post();
  Response put();
  Response patch();
  Response del();
  Response options();
  Response head();

private:
  std::string m_request_data;
  std::string m_user_agent;
  struct {
    std::string m_username;
    std::string m_password;
  } m_basic_auth;
  std::string m_base_url;
  std::string m_url_host;
  std::string m_url_path;
private:
};

#endif