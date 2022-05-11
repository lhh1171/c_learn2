cmake_minimum_required(VERSION 3.16)

project(pp)

set(CMAKE_CXX_STANDARD 11)

add_executable(pp main.cpp test.cpp)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} libpcap.so.1 libpcap.so)



