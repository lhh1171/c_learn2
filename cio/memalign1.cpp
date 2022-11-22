#include <errno.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
//对齐内存
int memalign1()
{
    char* buf;
    int ret;
    int align = 4096;
    uintptr_t align2 = 4096;
    int alc_size = 17;
    char* buf2 = (char*)malloc(alc_size);
    //申请对齐内存
    ret = posix_memalign((void**)&buf, align, alc_size);
    if(ret){
        errno = ret;
        perror("posix_memalign");
        return -1;
    }
    printf("%p %llx\n", buf, (unsigned long long)buf);
    printf("%llu %llu\n", (unsigned long long)buf % align, (unsigned long long)buf2 % align);
    printf("%08" PRIdPTR ":" "%08" PRIdPTR "\n", (uintptr_t)buf % align2, (uintptr_t)buf2 % align2);

    free(buf);
    free(buf2);
    return 0;
}