#ifndef URL_H
#define URL_H

#include "utils.h"

#include <string>

class Url {
public:
  Url() = default;
  Url(const std::string& full_url);
  ~Url() = default;

  const std::string get_url() const { return m_url; }
  const std::string get_host() const { return m_host; }
  const std::string get_endpoint() const { return m_endpoint; }
  const std::string get_ip() const { return m_ip; }

  void parse(const std::string& url); // INFO: not sure about the way, will try.
  void change_url(const std::string& full_url);

private:
  std::string m_url;
  std::string m_host;
  std::string m_endpoint;
  std::string m_ip;
};

#endif