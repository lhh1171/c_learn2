cmake_minimum_required(VERSION 3.16)
project(tcp_ucp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_executable(tcp_ucp main.cpp)