#include<iostream>
using namespace std;
struct bitdomain{//0110000 1--->0x61
    char a:1;
    char b:7;
}__attribute__((packed));

int stru4(){
   bitdomain bit;
   bit.a=0x01;
   bit.b=0x30;
   char *ptr=(char *)&bit;
//   printf("%x\n",ptr);
   cout<<*ptr<<endl;
    cout<<*(ptr+1)<<endl;
   return 0;
}
