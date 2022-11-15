#include<iostream>
using namespace std;
typedef union{   //24
    long i;   //8
    int k[5];  //8 8 8
    char c;   //1
} UDATE;
struct data{    //40
    int cat;    //8
    UDATE cow;  //8 8 8
    double dog; //8
}too;
//typedef struct xxx{
//    int cat;
//    UDATE cow;
//    double dog;
//}XXX;
UDATE temp;
int un3(){
    cout<<sizeof(UDATE)<<"\t"<<sizeof(struct data)<<endl;
    return 0;
}
