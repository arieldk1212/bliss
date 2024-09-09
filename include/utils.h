#include <string>

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

std::string generate_user_agent() { return "BlissAgent/1.0 (" + get_os_info() + "; " + get_arch_info() + ")"; }