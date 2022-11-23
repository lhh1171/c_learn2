
#include <iostream>
#include <boost/asio.hpp>
using namespace std;
using namespace boost::asio;

int asioserver()
{
    // 所有asio类都需要io_service对象
    io_service iosev;
    ip::tcp::acceptor acceptor(iosev, ip::tcp::endpoint(ip::tcp::v4(), 9999));
    for(;;)
    {
        // socket对象
        ip::tcp::socket socket(iosev);
        // 等待直到客户端连接进来
        acceptor.accept(socket);
        // 显示连接进来的客户端
        cout << socket.remote_endpoint().address() << endl;
        // 向客户端发送hello world!
        boost::system::error_code ec;
        socket.write_some(buffer((string)"hello world!"), ec);

        // 如果出错，打印出错信息
        if(ec)
        {
            cout << boost::system::system_error(ec).what() << endl;
            break;
        }
        // 与当前客户交互完成后循环继续等待下一客户连接
    }
    return 0;
}

//==========================================================================================================

int asioclient()
{
    // 所有asio类都需要io_service对象
    io_service iosev;
    // socket对象
    ip::tcp::socket socket(iosev);
    // 连接端点，这里使用了本机连接，可以修改IP地址测试远程连接
    ip::tcp::endpoint ep(ip::address_v4::from_string("127.0.0.1"), 9999);
    // 连接服务器
    boost::system::error_code ec;
    socket.connect(ep,ec);
    // 如果出错，打印出错信息
    if(ec)
    {
        cout << boost::system::system_error(ec).what() << endl;
        return -1;
    }
    // 接收数据
    char buf[100];
    size_t len=socket.read_some(buffer(buf), ec);
    std::cout.write(buf, len);

    return 0;
}
