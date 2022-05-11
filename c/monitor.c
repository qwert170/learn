#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/wait.h>

int main(int arg,char *argv[],char **environ)
{
    int fd[2];
    pid_t pid;
    int stat_val;
    void **argv1;
    argv1=(void **)argv;
    if(arg<2)
    {
        printf("wrong paramenters \n");
        exit(0);
    }

    if(pipe(fd)){
        perror("pipe failed");
        exit(1);
    }

    pid=fork();
    switch(pid)
    {
        case -1:
            perror("fork failed!\n");
            exit(1);
        case 0:
            close(0);
            dup(fd[0]);
            execve("ctrlprocess",argv1,environ);
            exit(0);
        default:
            close(fd[0]);
            write(fd[1],argv[1],strlen(argv[1]));
            break;
    }
    wait(&stat_val);
    exit(0);
}