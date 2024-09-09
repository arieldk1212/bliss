#include "../include/request.h"

Request::Request() {

}

Request::Request(std::string& url, std::string& username, std::string& password) {
  m_base_url = url;
  m_basic_auth.m_username = username;
  m_basic_auth.m_password = password;
}

void Request::set_request_data(std::string& request_data) { m_request_data = request_data; }
void Request::set_basic_auth(std::string& username, std::string& password) { m_basic_auth.m_username = username; m_basic_auth.m_password = password; }
void Request::set_user_agent(std::string& user_agent) { m_user_agent = user_agent;}