////
//// Created by andilyliao on 17-9-9.
////
//#include <iostream>
//#include <stdarg.h>
//#include <cstring>
//#include <linux/kernel.h>
//using namespace std;
////零长度和变量长度数组
//int gnuext1(){
//    struct line {
//        int length;//4
//        char contents[0];//4
//    };
//
//    int this_length=3;
//    line *thisline = (line *)malloc (sizeof (line) + this_length);
//    thisline->length = this_length;
//    thisline->contents[0]='a';
//    thisline->contents[1]='b';
//    thisline->contents[2]='c';
//    cout<<thisline->length <<"\t"<<thisline->contents<<endl;
//    int n=0;
//    cin>>n;
//    char array[n];
//    cout<<sizeof(array)<<endl;
//    return 0;
//}
////========================================================================================
////case范围以及多参数传递
//void printStrings(const int, ...);
//int gnuext2(){
//    printStrings(4, "My", "name", "is", "Macro!!!!!");
//    return 0;
//}
//
//
//    /**
//     *  va_list是用于存放参数列表的数据结构。
//        va_start函数根据初始化last来初始化参数列表。
//        va_arg函数用于从参数列表中取出一个参数，参数类型由type指定。
//        va_end函数执行清理参数列表的工作。
//     */
//void printStrings(const int cnt, ...) {
//
//        switch (cnt){
//            case 1 ... 9:
//                cout<<"1-9"<<endl;
//                break;
//            case 10 ... 20:
//                cout<<"10-20"<<endl;
//                break;
//            default:
//                break;
//        }
//
//
//        __builtin_va_list vaptr;//定义一个指针型变量
//        __builtin_va_start(vaptr, cnt);//将变量赋值
//        for (int i = 0; i < cnt; i++) {
//            cout<<__builtin_va_arg(vaptr, char *)<<endl;//指针指向的数据转换成指定数据类型
//        }
//        __builtin_va_end(vaptr);//指针归零
//}
////========================================================================================
////语句表达式 以及typeof 关键字
////可变参数宏
//
//
//int gnuext3(){
//#define min_t(type,x,y) ({ type __x = (x); type __y = (y); __x < __y ? __x: __y; })
//    cout<<min_t(int,1,2)<<endl;
//
//    //c++11中将typeof改成了decltype 晕死
//#define min(x,y) ({\
//    const decltype(x) _x = (x); \
//    const decltype(y) _y = (y);\
//    (void) (&_x == &_y);_x < _y ? _x : _y; \
//})
//
//    int c=min(1,2);
//    cout<<c<<endl;
//
//#define pr_debug(fmt,arg...) printf(fmt,##arg)
//
//    pr_debug("%s:%d","aaa",12);
//    return 0;
//}
////========================================================================================
////特殊属性声明
//
////GNU C 支持noreturn、format、section、aligned、packed等十个属性
////__attribute__可以设置函数属性（Function Attribute）、变量属性（Variable Attribute）和类型属性（Type Attribute）。
////__attribute__语法格式为：
////__attribute__ ((attribute-list))
////同时使用多个属性:extern void xxx(const char *format, ...) __attribute__((noreturn)) __attribute__((format(printf, 1, 2)));
//
////noreturn属性用于函数，表示该函数从不返回。
//// 这可以让编译器生成稍微优化的代码，最重要的是可以消除不必要的警告信息比如未初使化的变量。
//extern int myexit() __attribute__((noreturn));
//int gnuext4()
//{
//    int n=0;
//    cin>>n;
//    if ( n > 10)
//        myexit();
//    else
//        return 0;
//}
//
//int myexit(){
//    cout<<"adadfadf"<<endl;
//    while(true);
//    return 0;
//}
//
////========================================================================================
////__attribute__ format 属性告诉编译器，按照printf, scanf, strftime或strfmon的参数表格式规则对该函数的参数进行检查。
////用法：
////__attribute__((format(printf,m,n)))
////__attribute__((format(scanf,m,n)))
////其中参数m与n的含义为：
////m 格式化字符串（format string）的位置（顺序从1开始）；
////n 参数“…”的位置（顺序从1开始）；
//extern void myLog(const char *tag,const char *format,...) __attribute__((format(printf,2,3)));
//int gnuext5()
//{
//    myLog("abc","%s,%s\n","aaa","bbb");
//    return 0;
//}
//void myLog(const char *tag,const char *format,...) {
//    __builtin_va_list vaptr;//定义一个指针型变量
//    __builtin_va_start(vaptr, format);//将变量赋值
//    char *(ptr[2]);
//    for (int i = 0; i < 2; i++) {
//        char *ptr1=__builtin_va_arg(vaptr, char *);//指针指向的数据转换成指定数据类型
//        ptr[i]= (char *) malloc(strlen((const char *)ptr1));
//        ptr[i]=ptr1;
//    }
//    __builtin_va_end(vaptr);//指针归零
//    printf("TAG:%s Message:%s %s",tag,ptr[0],ptr[1]);
//}
////========================================================================================
////__attribute__ const当重复调用带有数值参数的函数时，
//// 由于返回值是相同的，所以此时编译器可以进行优化处理，除第一次需要运算外，
//// 其它只需要返回第一次的结果就可以了，进而可以提高效率。
////用法：
////__attribute__((const))
//int  __attribute__((const)) add(int x)
//{
//    printf("%s(%d)\n", __FUNCTION__, x);
//    return x + 1;
//}
//int gnuext6(){
//    cout<<add(10)<<endl;
//    cout<<add(2)<<endl;
//    return 0;
//}
////========================================================================================
////deprecated 使IDE把过时代码划线。
//#ifdef __GNUC__
//#    define GCC_VERSION_AT_LEAST(x,y) (__GNUC__ > (x) || __GNUC__ == (x) && __GNUC_MINOR__ >= (y))
//#else
//#    define GCC_VERSION_AT_LEAST(x,y) 0
//#endif
//
//#if GCC_VERSION_AT_LEAST(3,1)
//#    define attribute_deprecated __attribute__((deprecated))
//#elif defined(_MSC_VER)
//#    define attribute_deprecated __declspec(deprecated)
//#else
//#    define attribute_deprecated
//#endif
///* 用在属性上 */
//attribute_deprecated int  variable_old = 0;
///* 用在函数上 */
//attribute_deprecated void function_old(void);
//
//void function_old(void)
//{
//    printf("old function.\n");
//    return;
//}
//
//int gnuext7()
//{
//    variable_old++;
//    function_old();
//    return 0;
//}
////========================================================================================
////cleanup离开作用域之后执行指定的方法。实际应用中可以在作用域结束之后做一些特定的工作，比如清理。
////用法 ：__attribute__((cleanup(...)))
//void destroy_string(char **str) {
//    printf("final str : %s\n", *str);
//    free(*str);
//}
//
//int gnuext8() {
//
//    char *str __attribute__ ((__cleanup__(destroy_string))) = NULL;
//    str = (char*)malloc((sizeof(char)) * 100);
//    strcpy(str, "hello world!");
//    printf("current str : %s\n", str);
//    return 0;
//}
//
////========================================================================================
////nonnull编译器对函数参数进行NULL的检查
////用法：__attribute__((nonnull(...)))
//char *strcpy11 (char *__volatile __dest, __const char *__restrict __src) __attribute__((nonnull (1, 2)));
//
//int gnuext9() {
//    char *ptr=(char *)malloc(10);
//    strcpy11(ptr, NULL);
//    return 0;
//}
//char * strcpy11(char * dest,const char *src)
//{
//    char *tmp = dest;
//    while ((*dest++ = *src++) != '\0')
//        /* nothing */;
//    return tmp;
//}
////========================================================================================
////constructor与destructor
////
////作用：__attribute__((constructor)) 在main函数之前执行,
////__attribute__((destructor)) 在main函数之后执行。
////__attribute__((constructor(PRIORITY)))和__attribute__((destructor(PRIORITY)))按优先级执行。（可用于动态库注入的Hook）
////
////用法：
////__attribute__((constructor))
////
////__attribute__((destructor))
////
////__attribute__((constructor(PRIORITY)))
////
////__attribute__((destructor(PRIORITY)))
//
//__attribute__((constructor(10))) void before_main1() {
//    printf("before main 1\n");
//}
//__attribute__((constructor(5))) void before_main2() {
//    printf("before main 2\n");
//}
//__attribute__((destructor)) void after_main() {
//    printf("after main\n");
//}
//
//int gnuext10() {
//    printf("in gnuext10\n");
//    return 0;
//}
////========================================================================================
////aligned (alignment) 该属性规定变量或结构体成员的最小的对齐格式，以字节为单位。
////aligned没有参数，表示“让编译器根据目标机制采用最大最有益的方式对齐"
////packed 使用该属性可以使得变量或者结构体成员使用最小的对齐方式，即对变量是一字节对齐，对域（field）是位对齐。
//struct A{
//    char a;          //1B
//                     //3B
//    int b;           //4B   //由于这4个字节不能被拆成高低两部分 所以他连同上面的是8个 下面的c自己是8个
//    unsigned short c;//2B
//                     //6B
//    long d;          //8B
//    unsigned long long e; //8B
//    char f;               //1B
//                          //7B
//};
//
//struct B{
//    char a;//8个
//    int b;//8个
//    unsigned short c;//8个
//    long d;//8个
//    unsigned long long e;//8个
//    char f;//8个
//}__attribute__((aligned));
//
//struct C{
//    char a;//1
//    int b;//4
//    unsigned short c;//2
//    long d;//8
//    unsigned long long e;//8
//    char f;//1
//}__attribute__((aligned(1)));//不过并未如愿，仍然采用了默认4个字节的对齐方式。
//
//
//struct D{
//    char a;//4
//    int b;//4
//    unsigned short c;//4
//                    //4由于下面的8个不能拆开高低字节
//    long d;//8
//    unsigned long long e;//8
//    char f;//4
//            //其实还是需要补齐4个的，所以感觉没有啥用
//}__attribute__((aligned(4)));
//
//struct E{
//    char a;
//    int b;
//    unsigned short c;
//    long d;
//    unsigned long long e;
//    char f;
//}__attribute__((aligned(8)));//其实就是默认的
//
//struct F{
//    char a;
//    int b;
//    unsigned short c;
//    long d;
//    unsigned long long e;
//    char f;
//}__attribute__((packed));//1字节对齐
//
//int gnuext11(){
//    printf("A = %d, B = %d, C = %d, D = %d, E = %d, F = %d\n",
//           sizeof(A), sizeof(B), sizeof(C), sizeof(D), sizeof(E), sizeof(F));
//    return 0;
//}
//
////========================================================================================
////__builtin_expect 是GCC的内置函数，用来对选择语句的判断条件进行优化，
////常用于一个判断条件经常成立（如likely）或经常不成立（如unlikely）的情况。
////
////__builtin_expect的函数原型为long  __builtin_expect (long exp, long c)，
////返回值为完整表达式exp的值，它的作用是期望表达式exp的值等于c
////（注意，如果exp == c条件成立的机会占绝大多数，那么性能将会得到提升，否则性能反而会下降）。
//
////__builtin_constant_p也是GCC的内置函数，函数原型为int
////__builtin_constant_p(exp)，用于判断表达式exp在编译时是否是一个常量，如果是则函数的值为整数1
//
//#define likely(x)    __builtin_expect(!!(x), 1)
//#define unlikely(x)  __builtin_expect(!!(x), 0)
//
//int gnuext12()
//{
//    int a;
//    a = atoi ("2");
//    if (likely (a == 2))
//        a++;
//    else
//        a--;
//    printf ("%d\n", a);
//
//
//    char *ptr = NULL;
//    int num, count;
//
//    ptr = (char *)malloc(20);
//    num = __builtin_constant_p(ptr) ? 20 : 20 + 10;
//    count = __builtin_constant_p(20) ? 20 : 20 + 10;
//    printf("num = %d %d\n", num,count);
//    free(ptr);
//
//    return 0;
//}