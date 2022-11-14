cmake_minimum_required(VERSION 3.16)
project(cProcess)

set(CMAKE_CXX_STANDARD 11)


add_executable(cProcess
        forkshare.cpp fork1.cpp
        execve1.cpp exitecho.cpp
        wait1.cpp wait2.cpp wait3.cpp
        kill1.cpp signal1.cpp signal2.cpp signal3.cpp signal4.cpp
        daemon1.cpp
        pipe1.cpp pipe2.cpp
        shm1.cpp shm2.cpp
        msg1.cpp msg2.cpp
        sem1.cpp sem2.cpp
        main.cpp)
target_link_libraries(cProcess pthread rt)
