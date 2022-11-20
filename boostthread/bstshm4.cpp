
#include <boost/interprocess/shared_memory_object.hpp>
#include <iostream>
#include <boost/interprocess/mapped_region.hpp>
using namespace std;
using namespace boost::interprocess;

int bstshm4()
{
    bool removed = shared_memory_object::remove("Highscore");
    cout << removed << endl;
    return 0;
}
