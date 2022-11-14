
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <fcntl.h>
#include <cstring>
#include <sys/wait.h>
#include <sys/mman.h>

#define COUNT 100
#define SHMPATH "shm"

int do_child(char * shmpath)
{
    int interval, shmfd, ret;
    int *shm_p;
    // 使用shm_open访问一个已经创建的POSIX共享内存
    shmfd = shm_open(shmpath, O_RDWR, 0600);
    if (shmfd < 0) {
        perror("shm_open()");
        exit(1);
    }

    // 用mmap将对应的tmpfs文件映射到本进程内存 */
    shm_p = (int *)mmap(NULL, sizeof(int), PROT_WRITE|PROT_READ, MAP_SHARED, shmfd, 0);
    if (MAP_FAILED == shm_p) {
        perror("mmap()");
        exit(1);
    }
    /* critical section */
    interval = *shm_p;
    interval++;
    usleep(1);
    *shm_p = interval;
    /* critical section */

    munmap(shm_p, sizeof(int));
    close(shmfd);

    exit(0);
}

int shm2()
{
    pid_t pid;
    int count, shmfd, ret;
    int *shm_p;

    /* 创建一个POSIX共享内存 */
    shmfd = shm_open(SHMPATH, O_RDWR|O_CREAT|O_TRUNC, 0600);
    if (shmfd < 0) {
        perror("shm_open()");
        exit(1);
    }
    /* 使用ftruncate设置共享内存段大小 */
    ret = ftruncate(shmfd, sizeof(int));
    if (ret < 0) {
        perror("ftruncate()");
        exit(1);
    }
    /* 使用mmap将对应的tmpfs文件映射到本进程内存 */
    shm_p = (int *)mmap(NULL, sizeof(int), PROT_WRITE|PROT_READ, MAP_SHARED, shmfd, 0);
    if (MAP_FAILED == shm_p) {
        perror("mmap()");
        exit(1);
    }
    *shm_p = 0;

    for (count=0;count<COUNT;count++) {
        pid = fork();
        if (pid < 0) {
            perror("fork()");
            exit(1);
        }

        if (pid == 0) {
            do_child(SHMPATH);
        }
    }

    for (count=0;count<COUNT;count++) {
        wait(NULL);
    }

    printf("shm_p: %d\n", *shm_p);
    munmap(shm_p, sizeof(int));
    close(shmfd);
    shm_unlink(SHMPATH);
    exit(0);
}
