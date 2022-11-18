//
// Created by lqc on 2022/11/18.
//
class person{
    int id;
    int sex;
public:
    person():id(0),sex(0){}
    person(int id):id(id),sex(0){}
    person(int id,int sex):id(id),sex(sex){}
};
//class stu: public person{
//    int age;
//public:
//    stu():person(),age(0){}
//    stu(int id):person(id),age(0){}
//    stu(int id,int sex):person(id,sex),age(0){}
//    stu(int id,int sex,int age):person(id,sex),age(age){}
//};


//与上面的等同
class stu: public person{
    int age;
public:
    using person::person;
    stu(int id,int sex,int age):person(id,sex),age(age){}
};
