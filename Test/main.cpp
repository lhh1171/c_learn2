
//#include <stdio.h>
//int main(){
//    int x;//鸡
//    int y;//兔
//    for (x = 1; x <= 30; x++){
//        y = 30 - x;
//        if ((2*x)+(4*y)==90){
//            printf("%d %d", x, y);
//        }
//    }
//    return 0;
//}


//#include <stdio.h>
//int main(){
//    int a,b,c,sum=0;
//    printf("1元硬币有以下兑换方法:");
//    for(a=0;a<=100;a++){
//        for(b=0;b<=50;b++)
//            for(c=0;c<=20;c++)
//                if(a*1+b*2+c*5==100){
////                    printf("a,b,c");
//                    sum++;
//                }
//    }
//
//    printf("%d\n",sum);
//    return 0;
//}


#include <iostream>
using namespace std;
int main()
{
    int i,s;
    s=1;
    for(i=9;i>=1;i=i-1){
        s=(s+1)*2;

    }
    cout<<s<<" ";
    return 0;
}


//#include <stdio.h>
//int main(){
//    int n,a;
//    scanf("%d",&n);
//    a=n-1+n*(n-1)/2;
//    printf("%d\n",a);
//    return 0;
//}