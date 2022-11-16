//
// Created by andilyliao on 16-10-28.
//
#include <iostream>
using namespace std;

class Television
{
    friend class TeleController;
public:
    Television(int volume, int chanel);
private:
    int volume_;
    int chanel_;
};
Television::Television(int volume, int chanel) : volume_(volume), chanel_(chanel)
{
}
class TeleController
{
public:
    void VolumeUp(Television &tv);
    void VolumeDown(Television &tv);
    void ChanelUp(Television &tv);
    void ChanelDown(Television &tv);
};
void TeleController::VolumeUp(Television &tv)
{
    tv.volume_ += 1;
}
void TeleController::VolumeDown(Television &tv)
{
    tv.volume_ -= 1;
}
void TeleController::ChanelUp(Television &tv)
{
    tv.chanel_ += 1;
}
void TeleController::ChanelDown(Television &tv)
{
    tv.volume_ -= 1;
}

int friend2()
{
    Television tv(1, 1);
    TeleController tc;
    tc.VolumeUp(tv);
    return 0;
}