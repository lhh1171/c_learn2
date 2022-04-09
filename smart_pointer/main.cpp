#include<bits/stdc++.h>
#include <iostream>
using namespace std;
static int nums[20];
class Mylist{
public:
    int index=0;
    Mylist(int n1,...){
        va_list p;
        nums[0]=n1;
        va_start(p, n1);
        while (true){
            if (nums[index]==0){
                break;
            }
            index++;
        }
        while ((n1 = va_arg(p, int)) != 0){
            nums[index]=n1;
            index++;
        }
        va_end(p);
    }
    void dis(){
        for (int i = 0; i < index; ++i) {
            cout<<nums[i];
        }
        cout<<endl;
    }
};
class ptr{
    Mylist *mylist;
public:
    ptr(Mylist *mylist):mylist(mylist){

    }
    ~ptr(){
        delete mylist;
    }
    Mylist *operator->(){
        return this->mylist;
    }

    int operator[](int i){
        if (i>=this->mylist->index||i<0){
            perror("\"the index is illegal!!!");
            exit(0);
        } else{
            return nums[i];
        }
    }
    void operator+(int i){
        nums[this->mylist->index]=i;
        this->mylist->index++;
    }
};

int main(){
    memset(nums,0,20);
    ptr ptr(new Mylist(1,2,3,4,5,0));
    ptr->dis();
    cout<<ptr[4]<<endl;
    ptr+6;
    ptr->dis();
    ptr[9];
}