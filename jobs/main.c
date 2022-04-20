#include<stdio.h>
#include<string.h>

struct job
{
    char name[10];      //作业的名字
    int starttime;      //作业到达系统时间
    int needtime;       //作业服务时间
    int runtime;        //作业周转时间
    int endtime;        //作业结束时间
    double dqzz_time;    //带权周转时间

};
void fcfs(struct job jobs[50],int n);
void sjf(struct job jobs[50],int n);
void print(struct job jobs[50],int n);


int main()
{
    struct job jobs[50];
    int n,i; //n个作业
    int flag;
    printf("请选择调度算法，1：先来先服务 2:短作业优先:");
    scanf("%d",&flag);
    printf("请输入作业个数:");
    scanf("%d",&n);
    printf("请输入各作业的信息(格式：作业名 到达时间 服务时间)：\n");
    for(i=0;i<n;i++)
    {
        scanf("%s",jobs[i].name); //作业名
        scanf("%d",&jobs[i].starttime);//到达时间
        scanf("%d",&jobs[i].needtime);//运行（服务时间）时间
    }
    printf("\n");

    if(flag==1)
    {
        fcfs(jobs,n);
        printf("先来先服务（FCFS）算法运行结果：\n");
        print(jobs,n);
    }

    else
    {
        sjf(jobs,n);
        printf("最短作业优先算法（SJF）运行结果：\n");
        print(jobs,n);
    }
}
void fcfs(struct job jobs[50],int n)
{
    int i=0,j=0;
    char t_name[10];
    int t_time;
    for(i=0;i<n;i++) //按作业到达系统时间进行排序，最早到达的排在最前面
    {
        for(j=i;j<n;j++) //按作业到达系统时间进行排序，最早到达的排在最前面
        {
            if(jobs[j].starttime<jobs[i].starttime)
            {   //把到达时间早的赋值到t_time
                t_time=jobs[j].starttime;
                jobs[j].starttime=jobs[i].starttime;
                jobs[i].starttime=t_time;

                //把到达时间早的赋值到t_time
                t_time=jobs[j].needtime;
                jobs[j].needtime=jobs[i].needtime;
                jobs[i].needtime=t_time;

                strcpy(t_name,jobs[j].name);
                strcpy(jobs[j].name,jobs[i].name);
                strcpy(jobs[i].name,t_name);//在t_name数组中排序
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(i==0)
        {      //第一个进程
            jobs[i].runtime=jobs[i].needtime;          //周转时间=服务时间
            jobs[i].endtime=jobs[i].starttime+jobs[i].needtime;     //结束时间=到达时间+服务时间
        }
        else if(jobs[i].starttime>jobs[i-1].endtime)
        {  //第i个进程到达系统时，第i-1个进程已运行完毕
            jobs[i].runtime=jobs[i].needtime;
            jobs[i].endtime=jobs[i].starttime+jobs[i].needtime;
        }
        else
        {                              //第i个进程到达系统时，第i-1个进程未运行完毕
            jobs[i].runtime=jobs[i].needtime+jobs[i-1].endtime-jobs[i].starttime;
            //周转时间=服务时间+前一个的结束时间-到达时间
            jobs[i].endtime=jobs[i].starttime+jobs[i].runtime;  //结束时间=到达时间+周转时间
        }
        jobs[i].dqzz_time=jobs[i].runtime*1.0/jobs[i].needtime;//带权周转时间=周转时间/服务时间
    }
}
void sjf(struct job jobs[50],int n)
{
    int i=0,j=0;
    char t_name[10];
    int t_time;
    for(i=0;i<n;i++) //按作业到达系统时间进行排序，最早到达的排在最前面
    {
        for(j=i;j<n;j++) //按作业到达系统时间进行排序，最早到达的排在最前面
        {
            if(jobs[j].starttime<jobs[i].starttime)
            {
                //把到达时间早的赋值到t_time
                t_time=jobs[j].starttime;
                jobs[j].starttime=jobs[i].starttime;
                jobs[i].starttime=t_time;

                //把到达时间早的赋值到t_time
                t_time=jobs[j].needtime;
                jobs[j].needtime=jobs[i].needtime;
                jobs[i].needtime=t_time;

                strcpy(t_name,jobs[j].name);
                strcpy(jobs[j].name,jobs[i].name);
                strcpy(jobs[i].name,t_name);//在t_name数组中排序
            }
        }
    }

    jobs[0].endtime=jobs[0].starttime+jobs[0].needtime;//结束时间=到达时间+服务时间
    jobs[0].runtime=jobs[0].needtime;//周转时间=服务时间
    jobs[0].dqzz_time=jobs[0].runtime*1.0/jobs[0].needtime;//带权周转时间=周转时间/服务时间


    for(i=1;i<n;i++)
    {
        for(j=i;j<n;j++)
        {

            if(jobs[i-1].endtime>jobs[j].starttime&&jobs[j].needtime<jobs[i].needtime)
            {
                t_time=jobs[i].starttime;
                jobs[i].starttime=jobs[j].starttime;
                jobs[j].starttime=t_time;

                t_time=jobs[i].needtime;
                jobs[i].needtime=jobs[j].needtime;
                jobs[j].needtime=t_time;

                strcpy(t_name,jobs[i].name);   //将第二个参数的值复制给第一个参数，返回第一个参数
                strcpy(jobs[i].name,jobs[j].name);
                strcpy(jobs[j].name,t_name);
            }                 //按最短运行时间排序
        }
        if(jobs[i].starttime>jobs[i-1].endtime)
        {                                      //第i个进程到达系统时，第i-1个进程已运行完毕
            jobs[i].endtime=jobs[i].starttime+jobs[i].needtime;
            jobs[i].runtime=jobs[i].needtime;
        }
        else
        {
            jobs[i].endtime=jobs[i-1].endtime+jobs[i].needtime;
            jobs[i].runtime=jobs[i].endtime-jobs[i].starttime;
        }
        jobs[i].dqzz_time=jobs[i].runtime*1.0/jobs[i].needtime;
    }
}
void print(struct job jobs[50],int n)
{
    int i;
    double avertime;
    double dqzz_avertime;
    int sum_runtime=0;
    double  sum_time=0.00;
    printf("作业名  到达时间 运行时间 完成时间 周转时间 带权周转时间\n");
    for(i=0;i<n;i++)
    {
        printf("%s       %2d        %2d        %2d        %2d        %.2f\n",jobs[i].name,jobs[i].starttime,jobs[i].needtime,jobs[i].endtime,jobs[i].runtime,jobs[i].dqzz_time);
        sum_runtime=sum_runtime+jobs[i].runtime;
        sum_time=sum_time+jobs[i].dqzz_time;
    }
    avertime=sum_runtime*1.0/n;
    dqzz_avertime=sum_time*1.000/n;
    printf("平均周转时间:%.2f \n",avertime);
    printf("平均带权周转时间:%.3f \n",dqzz_avertime);
    printf("\n");
}
