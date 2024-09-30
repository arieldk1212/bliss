#include "../inc/response.h"

Response::Response(const std::string& response_data)
  : m_response_raw_data(response_data) {
    // TODO: STATUS_CODE["${STATUS}"] = <int>CODE;

  }

void Response::view_data() {
  std::cout << m_response_raw_data;
}