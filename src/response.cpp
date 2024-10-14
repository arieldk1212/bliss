#include "../inc/response.h"

Response::Response(const std::string& response_data) { m_response = response_data; }

void Response::print_response() {
  std::cout << m_response;
}