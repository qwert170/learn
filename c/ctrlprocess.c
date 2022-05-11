#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<string.h>
int main(int arg,char *argv[])
{
    int n;
   // char buf[1024];
    char *buf;
  
    while(1)
    {
        if((n=read(fileno(stdin),buf,1024))>0)
        {
            buf[n]='\0';
            printf("ctrlprocess receive:%s\n",buf);

            if(strcmp(buf,"exit")==0)
                exit(0);

            if(strcmp(buf,"getpid")==0)
            {
                printf("My pid :%d\n",getpid());
                sleep(3);
                exit(0);
            }
        }
    }
}