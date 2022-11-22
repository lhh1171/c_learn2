
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;
int fputcget(void)
{
    FILE *fp;
    int ch;
    if ( (fp = fopen("/opt/xxx", "w+")) == NULL) {
        perror("Open file file2\n");
        exit(1);
    }
//    while ( (ch = fgetc(stdin)) != '0'){
    while ( (ch = getchar()) != '0'){
        fputc(ch, fp);
    }
    rewind(fp);
    while ( (ch = fgetc(fp)) != EOF) {
//        putchar(ch);
        fputc(ch,stdout);
    }
    int res=fclose(fp);
    if(res<0){
        perror("error!!!!!");
        cout<<strerror(errno)<<"\t"<<errno<<endl;
        exit(1);
    }
    cout<<"ok"<<endl;
    return 0;
}

