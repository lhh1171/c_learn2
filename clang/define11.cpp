
#include <iostream>
#pragma hdrstop

/*
a 假定没有别名。
g 允许全局优化。
p 增强浮点一致性。
s 或 t 指定更短或者更快的机器代码序列。
w 假定在函数调用中没有别名。
y 在程序堆栈中生成框架指针。
#pragma optimize( "[optimization-list]", {on | off} )
 */
#pragma optimize( "", on )

//在这之前只能是#include 它的作用是
//让编译器在不需要的情况下不重新编译前面的.h文件
//默认情况下,函数被存放在.text节中
void func1() {                  // stored in .text
}

//将函数存放在.my_data1节中
#pragma code_seg(".my_data1")
void func2() {                  // stored in my_data1
}

//r1为标识符,将函数放入.my_data2节中
#pragma code_seg(push, r1, ".my_data2")
void func3() {                  // stored in my_data2
}


using namespace std;
int define11()
{
//    该指令能够控制编译器发出警告的方式，其用法举例如：#pragma warning(disable : 4507 34; once : 4385; error : 164)
//    这个指令有三部分组成，其中disable部分表示忽略编号为4507和34的警告信息，once部分表示编号为4385的警告信息只显示一次，error部分表示把编号为164的警告信息当做错误。
//    另外，其还有两个用法

//#pragma warning(push [, n])：保存所有警告信息的现有的警告状态，后面n是可选的，表示把全局警告等级设为n。
//#pragma warning(pop)：弹出最后一个警告信息，取消在入栈和出栈之间所作的一切改动。

#pragma warning(push) //保存编译器警告状态
#pragma warning(disable:4305) //取消4305的警告
    bool a=10; //无警告信息
#pragma warning(pop) //恢复之前的警告转改
    bool b=10;
    return 0;
}
