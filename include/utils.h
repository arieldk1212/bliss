#include <string>
#include <regex>
#include <netdb.h>
#include <cstring>
#include <sys/types.h>
#include "base.h"

inline std::string generate_user_agent() { return "BlissAgent/1.0 (" + get_os_info() + "; " + get_arch_info() + ")"; }

std::string get_os_info();

std::string get_arch_info();

std::string url_to_host(const std::string& url);

std::string host_to_ip(const std::string& host);