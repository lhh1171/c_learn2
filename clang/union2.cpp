#include<iostream>
using namespace std;
union A{
   int a[5];
   char b;
   double c;
};
int un2(){
   cout<<sizeof(A)<<endl;
   return 0;
}
