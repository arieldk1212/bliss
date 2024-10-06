#ifndef RESPONSE_H
#define RESPONSE_H

#include "headers.h"

#include <map>
#include <string>

typedef std::map<std::string, int> STATUS_CODE;

// TODO: abstract the request data aka response from the user-agent, define functions like view, data, show, etc..

class Response {
public:
  explicit Response(const std::string& response_data);
  ~Response() = default;


private:
  std::string m_response_raw_data;
  std::string m_response_body;
  STATUS_CODE m_status;
  Headers m_headers; // TOOD: include date here.
};

#endif