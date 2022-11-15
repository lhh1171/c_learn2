//
// Created by  on 16-10-31.
//
#pragma once

#ifndef ISPC
#define ISPC
//编译输出：Macro ISPC is defined
#pragma message("Macro ISPC is defined")
#endif

struct FOO
{
    int member;
};

#pragma data_seg("MyData")
//这个数据段中的全局变量可以被多个进程共享，共享数据必须初始化，
// 否则编译器会把没有初始化的数据放到.BSS段中，从而导致多个进程之间的共享行为失败
int g_Value=10;

#pragma data_seg()

#pragma pack(1)
struct S
{
    char a;
    int b;
};



