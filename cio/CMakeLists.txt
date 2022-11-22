cmake_minimum_required(VERSION 3.16)
project(cio)

set(CMAKE_CXX_STANDARD 14)

add_executable(cio main.cpp
        io1.cpp fputcget.cpp fseek1.cpp fputsfgets.cpp freadfwrite.cpp
        sysstdio.cpp sysio.cpp sysio2.cpp fcntl.cpp fcntl2.cpp dup.cpp
        ioctl1.cpp inode1.cpp mmap.cpp madvise1.cpp zerocopy.cpp splice1.cpp tee1.cpp
        hole.cpp mlock1.cpp memalign1.cpp directopen1.cpp)