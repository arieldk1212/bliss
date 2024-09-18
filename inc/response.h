#ifndef RESPONSE_H
#define RESPONSE_H

#include "headers.h"
#include <map>
#include <string>

typedef std::map<std::string, int> STATUS_CODE_MAP;

class Response {
public:
  Response(const std::string& data);
  ~Response() = default;

private:
  std::string m_data;
  STATUS_CODE_MAP m_status;
  Headers m_headers; // TOOD: include date here.
};

#endif