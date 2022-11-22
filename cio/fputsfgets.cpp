
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int fputsfgets()
{
    FILE *fpSrc=NULL;
    FILE *fpDst=NULL;
    char str[11];
    if ((fpSrc=fopen("/opt/xxx1","r"))==NULL)
    {
        perror("error!!!");
        exit(0);
    }
    if ((fpDst=fopen("/opt/xxx1","w"))==NULL)
    {
        perror("error!!!");
        exit(0);
    }
    while(fgets(str,10,fpSrc)!=NULL)
    {
        fputs(str,fpDst);
    }
    if (fpSrc!=NULL)
    {
        fclose(fpSrc);
    }
    if (fpDst!=NULL)
    {
        fclose(fpDst);
    }
    cout<<"ok"<<endl;
    return 0;
}


