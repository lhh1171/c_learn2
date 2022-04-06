#include <iostream>
#include<bits/stdc++.h>
struct stu{
    int sid;
    char gender;
};
struct tea{
    char gender;
    int uid;
    int age;
};
void insert_stu(char *ptr, int sid, char gender) {
    char * temp=ptr;
    //Locate where the block of memory is available
    while (1){
        if (*temp=='x'){
            break;
        }
        temp++;
    }
    memset(temp,0,10);
    *(temp+0)='s';
    *(temp+1)=8;
    *(int *)(temp+2)=sid;
    *(temp+6)=gender;
};
void display(char * ptr){
    char * temp=ptr;
    //Locate where the block of memory is available
    while (1){
        if (*temp=='x'){
            break;
        }
        printf("%x\n",*temp);
        temp++;
    }
}
void insert_tea(char * ptr,char gender,int uid,int age){
    char * temp=ptr;
    //Locate where the block of memory is available
    while (1){
        if (*temp=='x'){
            break;
        }
        temp++;
    }
    memset(temp,0,14);
    memset(temp,0,10);
    *(temp+0)='t';
    *(temp+1)=12;
    *(temp+2)=gender;
    *(int *)(temp+6)=uid;
    *(int *)(temp+10)=age;
};
void get_TeaAndStu(char * ptr){
    char * temp=ptr;
    //Locate where the block of memory is available
    while (1){
        if (*temp=='x'){
            break;
        }
        if (*temp=='s'&&*(temp+1)==8){
            struct stu* s1=(struct stu*)(temp+2);
            printf("%c---%d\n",s1->gender,s1->sid);
            temp=temp+10;
            continue;
        }
        if (*temp=='t'&&*(temp+1)==12){
            struct tea* t1=(struct tea*)(temp+2);
            printf("%c---%d---%d\n",t1->gender,t1->uid,t1->age);
            temp=temp+14;
            continue;
        }
        temp++;
    }
}
int main() {
//    printf("%d---%d\n",sizeof(struct stu),sizeof(struct tea));
    char* ptr= (char *)malloc(40);
    memset(ptr,'x',40);
    insert_stu(ptr, 11, 'm');
    insert_tea(ptr,'w',88,33);
    get_TeaAndStu(ptr);
    return 0;
}
