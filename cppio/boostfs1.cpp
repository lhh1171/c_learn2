
//g++ boostfs1.cpp -o hello.o -lboost_system
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <iostream>
#include <boost/foreach.hpp>
using namespace std;
using namespace boost;
using namespace filesystem;
int boostfs1()
{
    path p1("/opt/xxx");
    path p2("/opt/xxx1");
    path p3("/opt/xxx2");
    cout << p1.string() <<endl;
    cout << p1.filename() << endl;
    cout << p1.root_directory() << endl;
    cout << p1.stem() << endl;
    cout << p1.extension() << endl;

    cout<<"=============1================"<<endl;
    BOOST_FOREACH(auto &x,p3){
        cout<<x<<endl;
    }
    cout<<"==============2==============="<<endl;
//    for (path::iterator it = p3.begin(); it != p3.end(); ++it) {
//        cout << *it << endl;
//    }
//    cout<<"============================="<<endl;
    std::pair<directory_iterator,directory_iterator> dr(directory_iterator("/opt/WeChat"),directory_iterator());
    BOOST_FOREACH(auto &x,dr){
                    cout<<x<<endl;
                }
    cout<<"==============3==============="<<endl;
//    directory_iterator end;
//    for(directory_iterator pos(p3);pos!=end;++pos){
//        cout<<*pos<<endl;
//    }
//    cout<<"============================="<<endl;
    path p("/opt");
    p /= "aaa/bbb";
    cout << p.string() << endl;
    cout<<"===============4=============="<<endl;
    try
    {
        file_status s = status(p3);
        file_status s1 = status(p1);
        cout<<boolalpha << is_directory(s) << endl;
        cout<<boolalpha << is_directory(s1) << endl;
        cout<<file_size(p1)<<endl;

        time_t t = last_write_time(p1);
        cout << ctime(&t) << endl;

        space_info s2 = space("/disk");//du df
        cout << s2.capacity/(1024*1024*1024) << endl;
        cout << s2.free/(1024*1024*1024) << endl;
        cout << s2.available/(1024*1024*1024) << endl;
    }
    catch (filesystem_error &e)
    {
        cerr << e.what() << endl;
    }
    cout<<"==============5==============="<<endl;

    path p4("/opt/testboostdir");
    try
    {
        if (create_directory(p4))
        {
            rename(p4, "/opt/testboostdir1");
            remove("/opt/testboostdir2");
        }
        cout << complete("readme.txt") << endl;
        cout << complete("readme.txt","/opt") << endl;

        cout << current_path() << endl;
        chdir("/opt");
        cout << current_path() << endl;
    }
    catch (filesystem_error &e)
    {
        cerr << e.what() << endl;
    }
    cout<<"==============6==============="<<endl;
    path p5("/opt/xxx");
    boost::filesystem::ofstream ofs(p5);
    ofs << "Hello, world! @@" << endl;
    boost::filesystem::ifstream ifs(p5);
    string str1;
    getline(ifs,str1);
    cout<<str1<<endl;
    return 0;
}