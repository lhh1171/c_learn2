#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <iostream>

using namespace std;
int zerocopy(){
    int infd = open( "/opt/xxx1", O_RDONLY );
    int outfd = open( "/opt/xxx2", O_WRONLY );
    struct stat stat_buf;
    fstat( infd, &stat_buf );
//    sendfile( outfd, infd, NULL, stat_buf.st_size );
    sendfile64( outfd, infd, NULL, stat_buf.st_size );//可传输大于2g的数据
    cout<<"ok!!"<<endl;
    return 0;
}
