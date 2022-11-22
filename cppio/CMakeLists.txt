cmake_minimum_required(VERSION 3.16)
project(cppio)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppio main.cpp
        byteio1.cpp byteio2.cpp byteio3.cpp byteio4.cpp byteio5.cpp byteio6.cpp byteio7.cpp byteio8.cpp
        io1.cpp io2.cpp io3.cpp io4.cpp io5.cpp boostfs1.cpp)
target_link_libraries(cppio pthread boost_thread boost_system pthread boost_filesystem)