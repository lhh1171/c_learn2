
#include <boost/asio.hpp>
#include <iostream>
using namespace std;
void handler1(const boost::system::error_code &ec)
{
    cout << "5 s." << endl;
}

void handler2(const boost::system::error_code &ec)
{
    cout << "10 s." << endl;
}

int asio2()
{
    boost::asio::io_service io_service;
    boost::asio::deadline_timer timer2(io_service, boost::posix_time::seconds(10));
    timer2.async_wait(handler2);

    boost::asio::deadline_timer timer1(io_service, boost::posix_time::seconds(5));
    timer1.async_wait(handler1);

    io_service.run();
    return 0;
}
