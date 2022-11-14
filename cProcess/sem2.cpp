
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

using namespace std;

#define SEM_NAME "/sem_name"

//这个例子类似于java的信号量
void semTest(int flag)
{
    sem_t *pSem;
    pSem = sem_open(SEM_NAME, O_CREAT, 0666, 2);//打开信号量，初始值为2,只有两个进程可以进入

    sem_wait(pSem);//信号量减1,如果小于0则阻塞

    ofstream fileStream("/opt/testio-cpp/testfile/testdddd.txt", ios_base::app);

    for (int i = 0; i < 5; ++i)
    {
        sleep(1);

        fileStream<<flag;
        fileStream<<" "<<flush;
    }

    sem_post(pSem);//信号量加1
    sem_close(pSem);//关闭信号量
}

int sem2()
{
    for (int i = 1; i <= 3; ++i)
    {
        if (fork() == 0)
        {
            semTest(i);

            sleep(1);
            exit(0);
        }
    }
}
