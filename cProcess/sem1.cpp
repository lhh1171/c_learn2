#include <cstdio>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

union payload{
    int val;
};
void wait(int id){
    struct sembuf set;
    set.sem_num = 0;
    set.sem_op = -1;
    set.sem_flg = SEM_UNDO;
    semop(id,&set,1);
}

void post(int id){
    struct sembuf set;
    set.sem_num = 0;
    set.sem_op = 1;
    set.sem_flg = SEM_UNDO;
    semop(id,&set,1);
}

int sem1(){
    int semid=semget(1234,1,IPC_CREAT|0600);
    union payload initsem;
    initsem.val = 1;
    semctl(semid,0,SETVAL,initsem);
    pid_t pid;
    pid=fork();
    if(pid>0){
        wait(semid);
        printf("a get\n");
        sleep(1);
        post(semid);
        semctl(semid,0,IPC_RMID);
        printf("a return\n");
    }
    if(pid==0){
        wait(semid);
        printf("b get\n");
        post(semid);
        printf("b retrun\n");
    }
    return 0;
}
