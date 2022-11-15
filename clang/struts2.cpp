#include<iostream>
using namespace std;
struct B{
  char a;
  double b;
  int c;
}test_struct_b;

int stru2(){
   cout<<sizeof(test_struct_b)<<endl;
   return 0;
}
