#include "../inc/headers.h"

Headers& Headers::operator+(std::string&& full_header) {
  // INFO:: ACCEPTS RVALUE
  std::size_t loc = full_header.find(":");
  std::string temp_header_name = full_header.substr(0, loc);
  std::string temp_header_value = full_header.substr(loc + 2); 
  m_headers.insert({std::move(temp_header_name), std::move((temp_header_value))});
  return *this;
}

void Headers::serialize(std::string& request_data) {
  // INFO: refers to memory located request_data (m_request_data)
  // INFO: this function returns the fully prepered headers with \r\n and : values and space values.
  std::string data;
  for (const auto& header : m_headers) {
    request_data += header.first + ": " + header.second + "\r\n";
  }
  request_data += "\r\n";
}