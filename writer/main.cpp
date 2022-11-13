// vhd磁盘写入工具.cpp : Defines the entry point for the console application.
#include <cstdio>
#include <cstdlib>
#include <cstring>

#pragma warning( disable : 4996 ) //屏蔽报不安全函数错误
bool writeVHD(char *vhdPath, char *binPath, int n);
bool inputPath();
bool isHaveVHD;
char bufferVHD[512];
int main(int argv,char *args[])
{
    //参数1(1):bin文件
    //参数2:开始扇区号 ,可以不提供默认为0

    int section = 0;//开始扇区
    FILE *fpVHD = fopen("config.txt", "r");
    if (fpVHD != NULL)
    {
        fgets(bufferVHD, 512, fpVHD);
        isHaveVHD = true;
    }
    else
    {
        isHaveVHD = false;
        inputPath();
        return 0;
    }
    if (argv < 2)
    {
        printf("参数不正确,请输入:\n");
        inputPath();
        return 0;
    }

    if (argv > 2)
    {
        section = atoi(args[2]);//把字符串转换为整数
    }
    printf("开始写入扇区:%d\n", section);
    writeVHD(bufferVHD, args[1], section);
    getchar();
    getchar();
    return 0;
}

/*
在vhd虚拟磁盘中,在指定扇区中写入指定二进制数据
vhdPath:vhd文件路径
binPath:bin文件路径
n:开始写入的扇区号
*/
bool writeVHD(char *vhdPath, char *binPath,int n)
{
    //如果报SDL安全错误,可以使用fopen_s打开(在VS中),或者关闭SDL安全检查
    FILE *fpVHD = fopen(vhdPath, "rb+");

    if (fpVHD == NULL)
    {
        printf("打开vhd文件失败\n");
        return false;
    }
    FILE *fpBIN = fopen(binPath, "rb");
    if (fpBIN == NULL)
    {
        printf("打开二进制文件失败\n");
        return false;
    }
    fseek(fpBIN, 0, SEEK_END);
    int file_size = ftell(fpBIN);
    printf("文件总大小：%d字节\n", file_size);
    rewind(fpBIN);
    int sum = 0;//记录写入的总扇区数

    //移动到指定扇区,返回0表示移动成功,否则移动失败
    rewind(fpVHD);
    if (fseek(fpVHD, 512 * n, SEEK_SET) != 0)
    {

        printf("定位扇区失败\n");
        return false;
    }
    char buffer[512];
    int b_size=512;
    //开始写入数据
    while (true)
    {
        if(file_size<512){
	    b_size=file_size;
	}
        memset(buffer, 0, 512);

        if (!fread(buffer, b_size, 1, fpBIN))
        {
            printf("读不到");
            break;
        }
        //开始写入扇区
        if (!fwrite(buffer, b_size, 1, fpVHD))
        {
            printf("中途写入失败:");
            break;

        }
        sum += 1;
	file_size=file_size-512;
        if(file_size<=0){
	    break;	
	}
	rewind(fpBIN);
        fseek(fpBIN, 512 * sum, SEEK_SET);
	if(file_size<512){
		b_size=file_size;	
	}
        printf("+++%d",b_size);     
    }
    fflush(fpVHD);
    fclose(fpVHD);
    fclose(fpBIN);
    printf("共写入了%d个扇区\n", sum);
    return true;

}
//让用户自己输入路径
bool inputPath()
{
    char bufVHD[512];
    char bufBIN[512];
    int section=0;
    memcpy(bufVHD, bufferVHD, 512);
    if (!isHaveVHD)
    {

        printf("VHD文件:");
        scanf("%s", bufVHD);
//        get(bufVHD);
    }

    printf("BIN文件:");
    scanf("%s", bufBIN);
//    gets(bufBIN);
    printf("开始扇区:");
    scanf("%d", &section);
    bool r=writeVHD(bufVHD, bufBIN, section);
    getchar();
    getchar();
    return r;
}
