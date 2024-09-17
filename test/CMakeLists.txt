set(BASIC_TEST basic_test.cpp)
set(SOCKET_TEST socket_test.cpp)

add_executable(basic_test ${BASIC_TEST})
add_executable(socket_test ${SOCKET_TEST})

target_link_libraries(basic_test src)
target_link_libraries(socket_test src)

add_test(NAME basic_test COMMAND basic_test)
add_test(NAME socket_test COMMAND socket_test)