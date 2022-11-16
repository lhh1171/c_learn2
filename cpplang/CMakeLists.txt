cmake_minimum_required(VERSION 3.16)
project(cpplang)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpplang main.cpp
        classtest.cpp classtest.h classtest2.cpp classtest3.cpp classtest4.cpp classtest5.cpp classtest6.cpp
        constructor.cpp constructor2.cpp constructor2.h constructor3.cpp constructor4.cpp
        extends.cpp extendsdiscon.cpp extendsdiscon2.cpp member.cpp staticmember.cpp
        discon.cpp discon2.cpp discon3.cpp delete.cpp
        virtual1.cpp virtual2.cpp virtual3.cpp virtual4.cpp virtual5.cpp virbase.cpp virbase2.cpp
        templateopt.cpp tmplate11.cpp singleton.cpp strint.cpp namespacetest.cpp
        exceptiontest1.cpp exceptiontest2.cpp bad_allocExp.cpp friend1.cpp friend2.cpp inline1.cpp
        opt1.cpp opt2.cpp opt3.cpp opt4.cpp opt5.cpp opt6.cpp opt7.cpp opt8.cpp
        )