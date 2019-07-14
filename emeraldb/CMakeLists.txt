cmake_minimum_required(VERSION 3.14)
project(emeralddb C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

enable_testing()

include_directories(src)
include_directories(test)
include(cmake/dependencies.cmake)

add_library(edb_test_lib STATIC
        src/include/core.h src/include/ossSocket.h src/oss/ossSocket.cpp test/test_oss_socket.cpp test/test_oss_socket.h)

add_dependencies(edb_test_lib gtest)
target_link_libraries(edb_test_lib gtest_main)
add_executable(oss_socket_unit_test test/test_oss_socket.cpp)
target_link_libraries(oss_socket_unit_test gtest_main edb_test_lib)
add_test(NAME oss_socket_unit_test COMMAND oss_socket_test)
