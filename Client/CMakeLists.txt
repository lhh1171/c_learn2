cmake_minimum_required(VERSION 3.16)
project(Client)

set(CMAKE_CXX_STANDARD 11)

add_executable(Client main.cpp client.cpp UdpClient.cpp Lclient.cpp epollServer.cpp)