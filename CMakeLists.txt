cmake_minimum_required(VERSION 3.30)
project(Bliss)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE
  src/base.cpp
  src/request.cpp
  src/utils.cpp
  tests/test.cpp)

set(HEADERS
  include/base.h
  include/bliss.h
  include/headers.h
  include/request.h
  include/response.h
  include/utils.h)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})