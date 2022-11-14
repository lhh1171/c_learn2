
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sys/shm.h>
#define TEXT_SZ 2048
//这边写了那边能看见，那边写了这边能看见，同时写会竞争
struct shared_use_st {
    int written;
    char text[TEXT_SZ];
};

/*
 * 共享内存函数由shmget、shmat、shmdt、shmctl四个函数组成
 * shmget(得到一个共享内存标识符或创建一个共享内存对象)
 * shmat(把共享内存区对象映射到调用进程的地址空间)
 * shmdt(断开共享内存连接)
 * shmctl(共享内存管理)
 */
int producer(){
    int shmid;
    //获取到一个共享内存
    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
    if (shmid == -1){
        fprintf(stderr, "shmget failed\n");
        exit(EXIT_FAILURE);
    }
    void *shared_memory = (void *)0;
    shared_memory = shmat(shmid, (void *)0, 0);
    /*第二个参数：指定共享内存出现在进程内存地址的什么位置，
     * 直接指定为NULL让内核自己决定一个合适的地址位置
     * 第三个参数：只读模式/读写模式*/
    if (shared_memory == (void *)-1){
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %lX\n", (long)shared_memory);
    struct shared_use_st *shared_stuff;
    shared_stuff = (struct shared_use_st *)shared_memory;
    int running = 1;
    char buffer[BUFSIZ];
    while(running){
        while(shared_stuff->written == 1){
            sleep(1);
            printf("waiting for client...\n");
        }
        printf("Enter some text: ");
        fgets(buffer, BUFSIZ, stdin);
        strncpy(shared_stuff->text, buffer, TEXT_SZ);
        shared_stuff->written = 1;
        if (strncmp(buffer, "end", 3) == 0) {
            running = 0;
        }
    }
    if (shmdt(shared_memory) == -1) {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

int consumer(){
    int shmid;
    srand((unsigned int)getpid());
    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
    if (shmid == -1) {
        fprintf(stderr, "shmget failed\n");
        exit(EXIT_FAILURE);
    }
    void *shared_memory = (void *)0;
    shared_memory = shmat(shmid, (void *)0, 0);
    if (shared_memory == (void *)-1) {
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %lX\n", (long)shared_memory);
    struct shared_use_st *shared_stuff;
    shared_stuff = (struct shared_use_st *)shared_memory;
    shared_stuff->written = 0;
    int running = 1;
    while(running){
        if (shared_stuff->written){
            printf("You wrote: %s", shared_stuff->text);
            sleep( rand() % 4 );
            shared_stuff->written = 0;
            if (strncmp(shared_stuff->text, "end", 3) == 0) {
                running = 0;
            }
        }
    }
    if (shmdt(shared_memory) == -1){
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }
    if (shmctl(shmid, IPC_RMID, 0) == -1){
        /*第二个参数
         * IPC_STAT：得到共享内存的状态，把共享内存的shmid_ds结构复制到buf中
         * IPC_SET：改变共享内存的状态，把buf所指的shmid_ds结构中的uid、gid、mode复制到
         * 共享内存的shmid_ds结构内
         * IPC_RMID：删除这片共享内存
         * 第三个参数：共享内存管理结构体
                                         */
        fprintf(stderr, "shmctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

int shm1(){
    producer();
//    consumer();
}