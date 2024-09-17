set(BASIC_TEST basic_test.cpp)

add_executable(basic_test ${BASIC_TEST})

target_link_libraries(basic_test
  PRIVATE
  src)

add_test(NAME basic_test COMMAND basic_test)