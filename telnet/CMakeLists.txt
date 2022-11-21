cmake_minimum_required(VERSION 3.16)
project(telnet C)

set(CMAKE_C_STANDARD 99)

add_executable(telnet main.c mt.h)