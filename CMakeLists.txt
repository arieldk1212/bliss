cmake_minimum_required(VERSION 3.30)
project(Bliss LANGUAGES CXX
  DESCRIPTION "Bliss - HTTP Library"
  HOMEPAGE_URL "https://github.com/arieldk1212/bliss")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(inc)

add_subdirectory(src)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
target_link_libraries(src PRIVATE OpenSSL::SSL)

enable_testing()
add_subdirectory(test)