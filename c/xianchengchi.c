#include<pthread.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>


//typedef void*(*FUNC)(void * arg);
typedef void*(*FUNC)(void* arg);  
typedef struct jobs{
    FUNC job;
    void * arg;
    struct jobs *next;
}jobs;

typedef struct pool{
    int max;
    int flag;
    pthread_t  *id;
    pthread_cond_t cond;
    pthread_mutex_t mutex;
    jobs *pointers;
}pool;

static pool *thpool=NULL;

void* arrange()
{
    jobs *work;
    while(1)
    {
        pthread_mutex_lock(&thpool->mutex);
       while((thpool->pointers==NULL)&&(thpool->flag==0))
       {
           pthread_cond_wait(&thpool->cond,&thpool->mutex);
       }
       if(thpool->flag!=0)
       {
            pthread_mutex_unlock(&thpool->mutex);
            pthread_exit(0);
       }
       work = thpool->pointers;                               
        thpool->pointers =thpool->pointers->next;         
        pthread_mutex_unlock(&thpool->mutex);
        work->job(work->arg);                                     
        free(work);
    }
}

void create(int max){
    int i;
    thpool=(pool *)malloc(sizeof(pool));

    if(!thpool)
    {
        printf("malloc thpool errno");
       pthread_exit(0);
    }
    thpool->flag=0;
    thpool->max=max;
    thpool->id=(pthread_t *)malloc(sizeof(pthread_t)*max);
    pthread_mutex_init(&thpool->mutex,NULL);
    pthread_cond_init(&thpool->cond,NULL);

    for(i=0;i<max;i++)
    {
        pthread_create(&thpool->id[i],NULL,arrange,NULL);
    }
}

void addtask(void*(*job)(void *),void *arg)
{
    jobs *work,*member;

    work=(jobs *)malloc(sizeof(jobs));
    work->job=job;
    work->arg=arg;
    work->next=NULL;
    pthread_mutex_lock(&thpool->mutex);
    member=thpool->pointers;
    if(!member)
    {
        thpool->pointers=work;
    }
    else
    {
        while(member->next!=NULL)
        {
            member=member->next;
        }
        member->next=work;
    }
    pthread_cond_signal(&thpool->cond);
    pthread_mutex_unlock(&thpool->mutex);
}

void destory()
{
    printf("正在销毁\n");

    int i;
    jobs *member;

    if(thpool->flag!=0)
    {
        return;
    }
    thpool->flag=1;
    pthread_mutex_lock(&thpool->mutex);
    pthread_cond_broadcast(&thpool->cond);
    pthread_mutex_unlock(&thpool->mutex);
    
    for(i=0;i<thpool->max;i++)
    {
        pthread_join(thpool->id[i],NULL);
    }
    free(thpool->id);
    while(thpool->pointers)
    {
        member=thpool->pointers;
        thpool->pointers=thpool->pointers->next;
        free(member);
    }
    pthread_mutex_destroy(&thpool->mutex);
    pthread_cond_destroy(&thpool->cond);
    free(thpool); 
    printf("销毁完成\n");
}

void* func1()
{
    printf("%lu is running\n",pthread_self());
    sleep(5);
}

int main()
{
    int i;
    create(5); //创建线程个数

    for(i=0;i<15;i++)
    {
        addtask(func1,NULL);
    }
    sleep(10);
    destory();
}

/*先创建线程池，在创建函数里，初始化线程池，
  再给每个线程分配任务，*/