cmake_minimum_required(VERSION 3.16)
project(Client)

set(CMAKE_CXX_STANDARD 11)

add_executable(Client client.cpp Lclient.cpp epollServer.cpp)