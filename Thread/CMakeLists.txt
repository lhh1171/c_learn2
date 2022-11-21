cmake_minimum_required(VERSION 3.16)
project(Thread)

set(CMAKE_CXX_STANDARD 14)

add_executable(Thread main.cpp
        thread1.cpp thread2.cpp thread3.cpp thread4.cpp thread5.cpp
        sync1.cpp sync2.cpp sync3.cpp sync4.cpp sync5.cpp sync6.cpp sync7.cpp sync8.cpp
        threadlocal1.cpp threadlocal2.cpp volitaletest.cpp
        attr2.cpp attr.cpp atomic1.cpp affinity1.cpp affinity2.cpp
        cppasync1.cpp cppasync2.cpp cppasync3.cpp cpppromise1.cpp
        cppsharedfuture1.cpp  cppthread1.cpp cppcondvar1.cpp cppasync2.cpp
        cppmutex1.cpp cppatomics1.cpp timer1.cpp timer2.cpp)