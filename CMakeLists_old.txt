cmake_minimum_required(VERSION 3.30)
project(Bliss)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE
  src/base.cpp
  src/request.cpp
  src/utils.cpp
  test/test.cpp)

set(HEADERS
  inc/base.h
  inc/bliss.h
  inc/headers.h
  inc/request.h
  inc/response.h
  inc/utils.h)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})