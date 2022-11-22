
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAX_PATH 1024
/* dirwalk:  apply fcn to all files in dir */
void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[MAX_PATH];
    struct dirent *dp;
    DIR *dfd;
    if ((dfd = opendir(dir)) == NULL) {
        cout<<"dirwalk: can't open "<<dir<<endl;
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0
               || strcmp(dp->d_name, "..") == 0) {
            continue;    /* skip self and parent */
        }
        if (strlen(dir)+strlen(dp->d_name)+2 > sizeof(name)) {
            cout<<"dirwalk: name "<<dir<<"\t"<<dp->d_name<<" too long"<<endl;
        }else {
//            sprintf(name, "%s/%s", dir, dp->d_name);
            string dirtmp=dir;
            string d_nametmp=dp->d_name;
            strcpy(name,(dirtmp+"/"+dp->d_name).c_str());
            (*fcn)(name);
        }
    }
    closedir(dfd);
}
/* fsize:  print the size and name of file "name" */
void fsize(char *name)
{
    struct stat stbuf;
    if (stat(name, &stbuf) == -1) {
        cout<<"fsize: can't access "<< name<<endl;
        return;
    }
//    switch (sb.st_mode & S_IFMT) {//S_IFMT文件类型的位掩码
//        case S_IFBLK: printf("block device\n"); break;
//        case S_IFCHR: printf("character device\n"); break;
//        case S_IFDIR: printf("directory\n"); break;
//        case S_IFIFO: printf("FIFO/pipe\n"); break;
//        case S_IFLNK: printf("symlink\n"); break;
//        case S_IFREG: printf("regular file\n"); break;
//        case S_IFSOCK: printf("socket\n"); break;
//        default: printf("unknown?\n"); break;
//    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
        dirwalk(name, fsize);
    }
    cout<<stbuf.st_size<<"\t\t"<<name<<endl;
}
int inode1()
{
    fsize("/opt/aaaa");
    return 0;
}

