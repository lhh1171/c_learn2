#include<iostream>
using namespace std;
class Animail{
public:
    virtual void GetColor()  = 0;
};
class Dog : public Animail{
public:
     virtual void GetColor() {cout <<"Yellow"<<endl;};
};
class Pig : public Animail{
public:
 virtual void GetColor() {cout <<"White"<<endl;};
};
int virtual5(){
//     Animail cAnimail;
     Animail *cAnimail=new Dog;
     cAnimail->GetColor();
     return 0;
}
