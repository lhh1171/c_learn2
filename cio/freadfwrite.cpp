
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct record {
    char name[10];
    int age;
};
int freadfwrite()
{
    struct record array[2] = {{"Ken", 24}, {"Knuth", 28}};
    FILE *fp = fopen("/opt/xxx", "w");
    if (fp == NULL) {
        perror("Open file recfile");
        exit(1);
    }
    fwrite(array, sizeof(struct record), 2, fp);
    fclose(fp);

    struct record array1[2];
    FILE *fp1 = fopen("/opt/xxx", "r");
    if (fp1 == NULL) {
        perror("Open file recfile");
        exit(1);
    }
    fread(array1, sizeof(struct record), 2, fp1);
    cout<<"Name1: "<<array1[0].name<<" Age1: "<<array1[0].age<<endl;
    cout<<"Name2: "<<array1[1].name<<" Age2: "<<array1[1].age<<endl;
    fclose(fp1);

    return 0;
}
