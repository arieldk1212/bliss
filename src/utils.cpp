#include "../include/utils.h"

std::string get_os_info() {
  #if defined(_WIN32)
    return "Windows";
  #elif defined(__linux__)
    return "Linux";
  #elif defined(__APPLE__)
    return "macOS";
  #else
    return "Unknown OS";
  #endif
}

std::string get_arch_info() {
  #if defined(__x86_64__) || defined(_M_X64)
    return "x86_64";
  #elif defined(__i386) || defined(_M_IX86)
    return "x86";
  #elif defined(__aarch64__)
    return "ARM64";
  #elif defined(__arm__)
    return "ARM";
  #else
    return "Unknown Architecture";
  #endif
}

std::string url_to_host(const std::string& url) {
  const std::regex host_regex(R"((?:https?://)?([^/]+))");
  std::smatch match;
  if (std::regex_search(url, match, host_regex)) {
    std::string host = match[1];
    size_t pos = host.find("/");
    if (pos != std::string::npos) {
      host = host.substr(0, pos);
    } return host;
  } return "";
}

std::string host_to_ip(const std::string& host) {
  struct addrinfo hints, *res;
  char ipstr[INET_ADDRSTRLEN];

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  int status = getaddrinfo(host.c_str(), nullptr, &hints, &res);

  struct sockaddr_in* ipv4 = (struct sockaddr_in*)res->ai_addr;
  void* addr = &(ipv4->sin_addr);

  inet_ntop(res->ai_family, addr, ipstr, sizeof ipstr);
  freeaddrinfo(res);

  return std::string(ipstr);
}