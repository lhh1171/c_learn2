cmake_minimum_required(VERSION 3.16)
project(for_cluster)

set(CMAKE_CXX_STANDARD 11)

add_executable(for_cluster main.cpp Lserver.cpp)