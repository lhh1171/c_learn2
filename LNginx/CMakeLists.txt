cmake_minimum_required(VERSION 3.16)

project(LNginx)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_executable(LNginx main.cpp socket.cpp server2.cpp LLMap.cpp epollServer.cpp)