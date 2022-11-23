
#include <boost/asio.hpp>
#include <iostream>
using namespace std;
void handler(const boost::system::error_code &ec)
{
    cout << "5 s." << endl;
}

int asio1()
{
    boost::asio::io_service io_service;
    boost::asio::deadline_timer timer(io_service, boost::posix_time::seconds(5));
    timer.async_wait(handler);
    io_service.run();
    return 0;
}
