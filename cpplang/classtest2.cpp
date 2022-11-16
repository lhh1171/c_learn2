#include<iostream>
using namespace std;
class CBox{
};
struct CBoxx{

};
class CBoxo{
public:
    CBoxo(){

    }
    CBoxo(CBoxo &a){
        this->a=a.a;
    }
    ~CBoxo(){

    }
    int a;
};
struct CBoxxo{
    int a;
};
int classtest2(){
    CBox boxobj;
//    CBox * cBox=(CBox *)malloc(sizeof(CBox));
//    free(cBox);
    CBox *cBox=new CBox;
    delete cBox;
    CBoxx cBoxx;
    CBoxo boxobjo;
    CBoxo boxobjo1=boxobjo;
    CBoxxo cBoxxo;
    cout<<sizeof(boxobjo)<<"\t"<<sizeof(cBoxxo)<<endl;//输出1
    return 0;
}
