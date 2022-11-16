#ifndef CONSTRUCTOR2_H_INCLUDED
#define CONSTRUCTOR2_H_INCLUDED
namespace mypack{
    class Time{
    public:
        Time();
        //对构造函数进行声明
        void set_time();
        static int get_time();
    private:
        int hour,minute,second;
    };
}

#endif // CONSTRUCTOR2_H_INCLUDED
