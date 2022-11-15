#include<iostream>
using namespace std;

#define myplusB(a,b) myplusA(a,b)

int myplusA(int a,int b){
   return a+b;
}

int define12(){
   int c=myplusB(1,2);

   cout<<c<<endl;
   return 0;
}
