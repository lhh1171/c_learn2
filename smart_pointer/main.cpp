#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Mylist{
public:
    int nums[20];
    int index=1;

    Mylist(int n1,...){
        memset(nums,0,80);
        va_list p;
        this->nums[0]=n1;
        va_start(p, n1);
        while ((n1 = va_arg(p, int)) != 0){
           this-> nums[index]=n1;
            index++;
        }
        va_end(p);

    }

    void dis(){
        for (int i = 0; i < index; ++i) {
            cout<<this->nums[i];
        }
        cout<<endl;
    }

    ~Mylist(){
        cout<<"~ mylist"<<endl;
    }
};
class Ptr{
    Mylist *pMylist;
public:
    Ptr(Mylist *mylist){
        this->pMylist=mylist;
    }

    ~Ptr(){
        cout<<"~ptr"<<endl;
        delete this->pMylist;
    }

    Mylist *operator->(){
        return this->pMylist;
    }

    int operator[](int i){
        if (i>=this->pMylist->index || i < 0){
            perror("the index is illegal!!");
            exit(1);
        } else {
            return this->pMylist->nums[i];
        }
    }

    void operator+(int i){
        this->pMylist->nums[this->pMylist->index]=i;
        this->pMylist->index++;
    }

    void operator+(Ptr& p){
        for (int i = 0; i < p.pMylist->index; ++i) {
            this->operator+(p.pMylist->nums[i]);
        }
    }
};

int main(){
    Ptr ptr2(new Mylist(2,2,3,4,7,0));
    Ptr ptr1(new Mylist(2,2,3,4,7,0));
    ptr1->dis();
    cout<<ptr1[4]<<endl;
    ptr1+6;
    ptr1+ptr2;
    ptr1->dis();
//    ptr1[19];
}