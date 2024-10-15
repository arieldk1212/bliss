#ifndef RESPONSE_H
#define RESPONSE_H

#include "headers.h"

#include <map>
#include <iostream>

typedef std::map<std::string, int> Status;

// TODO: abstract the request data aka response from the user-agent, define functions like view, data, show, json

class Response {
public:
  explicit Response(const std::string& response_data);
  ~Response() = default;

  void print_response();

private:
  Headers m_headers;
  Status m_status_code;
  std::string m_response;
  std::string m_response_body;
};

#endif
