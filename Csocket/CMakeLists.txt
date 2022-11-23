cmake_minimum_required(VERSION 3.16)
project(Csocket)

set(CMAKE_CXX_STANDARD 11)

add_executable(Csocket main.cpp
        cs1.cpp propercs1.cpp bufcs1.cpp stringcs1.cpp structcs1.cpp pfpacket1.cpp synflood.cpp
        udp0.cpp udp1.cpp udp2.cpp domaincs1cs1cli.cpp
        domaincs1server.cpp sctpcs1cli.cpp domaincs1server.cpp
        select1.cpp select2.cpp select3.cpp poll1.cpp epoll1.cpp epollet.cpp iouring1.cpp)
target_link_libraries(Csocket sctp uring)