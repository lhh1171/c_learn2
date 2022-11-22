
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;
/*
SEEK_SET 从文件开头移动ffset个字节
SEEK_CUR 从当前位置移动offset个字节
SEEK_END 从文件末尾移动offset个字节
offset可正可负,负值表示向前(向文件开头的方向)移动,正值表示向后(向文件末尾的
方向)移动,如果向前移动的字节数超过了文件开头则出错返回,如果向后移动的字节数超
过了文件末尾,再次写入时将增大文件尺寸,从原来的文件末尾到fseek移动之后的读写位
置之间的字节都是0
 */
int fseek1()
{
    FILE* fp;
    if ( (fp = fopen("/opt/xxx","r+")) == NULL) {
        perror("Open file textfile");
        exit(1);
    }
    if (fseek(fp, 10, SEEK_SET)<0) {
        perror("Seek file textfile");
        exit(1);
    }
    fputc('K', fp);
    int res=fclose(fp);
    if(res<0){
        perror("error!!!!!");
        cout<<strerror(errno)<<"\t"<<errno<<endl;
        exit(1);
    }
    return 0;
}
