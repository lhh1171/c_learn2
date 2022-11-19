cmake_minimum_required(VERSION 3.16)
project(mutiExtend)

set(CMAKE_CXX_STANDARD 11)


add_executable(mutiExtend main.cpp usingStruct.cpp override.cpp owner.cpp moveStruct.cpp funcPtr.cpp lamda.cpp const.cpp thread.cpp)
set(BOOST_ROOT "/usr/boost")
target_link_libraries(mutiExtend pthread boost_thread boost_system ncurses rt)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
