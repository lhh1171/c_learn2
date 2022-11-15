cmake_minimum_required(VERSION 3.16)
project(clang)

set(CMAKE_CXX_STANDARD 14)

add_executable(clang main.cpp
        define1.cpp define2.cpp define3.cpp define4.cpp define5.cpp define6.cpp
        define7.cpp define8.cpp define9.cpp define10.cpp define10.h define11.cpp define12.cpp
        enum.cpp externc.cpp
        struts.cpp struts2.cpp struts3.cpp struts4.cpp)