cmake_minimum_required(VERSION 3.16)
project(boostthread)

set(CMAKE_CXX_STANDARD 14)

add_executable(boostthread main.cpp
        mbstshm1.cpp mbstshm2.cpp mbstshm3.cpp mbstshm4.cpp mbstshm5.cpp mbstshm6.cpp
        bstmutex1.cpp bstmutex2.cpp bstmutex3.cpp bstmutex4.cpp
        bstshm1.cpp bstshm2.cpp bstshm3.cpp bstshm4.cpp)