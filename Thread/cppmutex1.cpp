#include <future>
#include <mutex>
#include <iostream>
#include <string>

std::mutex printMutex;  // enable synchronized output with print()

void print (const std::string& s)
{
    std::lock_guard<std::mutex> l(printMutex);//把锁放到lock_guard中时，mutex自动上锁，lock_guard析构时，同时把mutex解锁
    for (char c : s) {
        std::cout.put(c);
    }
    std::cout << std::endl;
}

int cppmutex1()
{
    auto f1 = std::async (std::launch::async,
                          print, "Hello from a first thread");
    auto f2 = std::async (std::launch::async,
                          print, "Hello from a second thread");
    print("Hello from the main thread");
    return 0;
}
