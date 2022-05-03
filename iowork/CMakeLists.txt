cmake_minimum_required(VERSION 3.16)
project(iowork)

set(CMAKE_CXX_STANDARD 14)

add_executable(iowork main.cpp mutiThread.cpp file.cpp file2.cpp)
#set(BOOST_ROOT "/usr/boost")
target_link_libraries(${PROJECT_NAME} libmysqlclient.so boost_thread boost_system rt)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")