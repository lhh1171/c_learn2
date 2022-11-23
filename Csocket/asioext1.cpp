
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <iostream>
using namespace std;
void handler1(const boost::system::error_code &ec)
{
    cout << "5 s." << endl;
}

void handler2(const boost::system::error_code &ec)
{
    cout << "5 s.." << endl;
}

boost::asio::io_service io_service;

void run()
{
    io_service.run();
}

int asioext1()
{
    boost::asio::deadline_timer timer1(io_service, boost::posix_time::seconds(5));
    timer1.async_wait(handler1);
    boost::asio::deadline_timer timer2(io_service, boost::posix_time::seconds(5));
    timer2.async_wait(handler2);
    boost::thread thread1(run);
    boost::thread thread2(run);
    thread1.detach();
    thread2.detach();
//    thread1.join();
//    thread2.join();

    int i;
    cin>>i;
    return 0;
}