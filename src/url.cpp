#include "../inc/url.h"

Url::Url(const std::string& full_url) {
  parse(full_url);
}

void Url::parse(const std::string& full_url) {
  size_t pos = full_url.find("//");
  size_t endpoint_pos = full_url.find("/", pos+2);
  m_host = full_url.substr(pos +2, endpoint_pos - (pos + 2));
  m_endpoint = full_url.substr(endpoint_pos);
  m_ip = host_to_ip(m_host);
}

void Url::change_url(const std::string& full_url) {
  m_url = full_url;
  parse(m_url);
  m_ip = host_to_ip(m_host);
}