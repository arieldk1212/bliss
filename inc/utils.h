#include <string>
#include <netdb.h>
#include <cstring>
#include <sys/types.h>
#include <arpa/inet.h>

std::string generate_user_agent();

std::string get_os_info();

std::string get_arch_info();

std::string host_to_ip(const std::string& host);