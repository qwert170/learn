#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<limits.h>
#include<dirent.h>
#include<grp.h>
#include<pwd.h>
#include<errno.h>
#include<fcntl.h>
#include<signal.h>  
//1,2,4,3,5,6,7,8,
#define PARAM_NONE 0
#define PARAM_A 1
#define PARAM_L 2
#define PARAM_R 4
#define PARAM_r 8
#define PARAM_i 16
#define PARAM_s 32
#define MAXROWLEN 80
#define FILEPATH_MAX (80) 

char *PATH;
char *PATH1;

int g_leave_len=MAXROWLEN;
int g_maxlen;
int clour;

void display_double(char *name,int flag);
void my_strcpy(char *p,char *q);
char *my_strcat(char *p,char *q);
void getclour(char name[]);
void display_inode(struct stat buf,char *name);
void display_size(struct stat buf,char *name);

/*错误处理函数，行数和错误信息*/
void my_err(const char *err_string,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}

void getclour(char name[]){
    struct stat buf;
    lstat(name,&buf);
    if(S_ISREG(buf.st_mode)){
        clour = 37;
        if((buf.st_mode&S_IXOTH)||(buf.st_mode&S_IXGRP)||(buf.st_mode&S_IXUSR)){
            clour = 32;
        }
    }
    else if(S_ISDIR(buf.st_mode)){
        clour = 34;
    }
    else if(S_ISCHR(buf.st_mode)){
        clour = 33;
    }
    else if(S_ISBLK(buf.st_mode)){
        clour = 33;
    }
    else if(S_ISFIFO(buf.st_mode)){
        clour = 35;
    }
    else if(S_ISLNK(buf.st_mode)){
        clour = 36;
    }
    else if(S_ISSOCK(buf.st_mode)){
        clour = 36;
    }
  
}


//输出属性
void display_attribute(struct stat buf,char *name)
{
    char buf_time[32];
    struct passwd *psd;//用户名
    struct group *grp;//组名
/*文件属性*/
     if(S_ISLNK(buf.st_mode)){
        printf("l");
     }else if(S_ISREG(buf.st_mode)){
        printf("-");
     }else if(S_ISDIR(buf.st_mode)){
        printf("d");      
     }else if(S_ISCHR(buf.st_mode)){
        printf("c");
     }else if(S_ISBLK(buf.st_mode)){
        printf("b");
     }else if(S_ISFIFO(buf.st_mode)){
        printf("f");
    }else if(S_ISSOCK(buf.st_mode)){
        printf("s");
    }

//文件所有者权限
    if(buf.st_mode & S_IRUSR){
        printf("r");
    }else {
        printf("-");
    }
    if(buf.st_mode &S_IWUSR){
        printf("w");
    }else {
        printf("-");
    }
    if(buf.st_mode & S_IXUSR){
        printf("x");
    }else {
        printf("-");
    }
//同组用户权限
    if(buf.st_mode &S_IRGRP){
        printf("r");
    }else{
        printf("-");
    }
    if(buf.st_mode &S_IWGRP){
        printf("w");
    }else{
        printf("-");
    }
    if(buf.st_mode &S_IXGRP){
        printf("x");
    }else{
        printf("-");
    }
//其他用户权限
    if(buf.st_mode &S_IROTH){
        printf("r");
     }else{
        printf("-");
     }
    if(buf.st_mode &S_IWOTH){
        printf("w");
     }else{
        printf("-");
     }
     if(buf.st_mode &S_IXOTH){
        printf("x");
     }else{
        printf("-");
     }
    
     printf("    ");
//uid gid用户名 组名
     psd=getpwuid(buf.st_uid);
     grp=getgrgid(buf.st_gid);
     printf("%4ld ",buf.st_nlink);
     printf("%-8s",psd->pw_name);
     printf("%-8s",grp->gr_name);

     printf("%6ld",buf.st_size);
     strcpy(buf_time,ctime(&buf.st_mtime));
     buf_time[strlen(buf_time)-1]='\0';
     printf(" %s",buf_time);
}

//不使用l 上下对齐
void display_single(char  *name)
{
    int i,len1;

    if(g_leave_len< g_maxlen){
        printf("\n");
        g_leave_len=MAXROWLEN;
    }

    len1=strlen(name);
    len1= g_maxlen -len1;
     printf("\033[%dm%s\033[0m",clour,name);

    for(i=0;i<len1;i++){
        printf(" ");
    }
    printf("  ");
    g_leave_len-=(g_maxlen+2);

}

//-a -l -R -r -i -s的使用
void display(int flag,char *pathname){
    int i,j,len=strlen(pathname);
    struct stat buf;
    char name[len];

    getclour(pathname);
  
    for(i=0,j=0;i<strlen(pathname);i++){
        if(pathname[i]=='/'){
            j=0;
            continue;
        }
        name[j++]=pathname[i];
    }
    name[j]='\0';
   
    if(lstat(pathname,&buf)==-1){
        my_err("stat",__LINE__);
    }
  
    switch(flag){
        case PARAM_NONE:
            if(name[0]!='.'){
                display_single(name);
            }
            break;
        case PARAM_i://i
            if(name[0]!='.'){
                display_inode(buf,name);
            }
            break;
        case PARAM_s://s
            if(name[0]!='.'){
               display_size(buf,name);
            }
            break;
        case PARAM_A://a
            display_single(name);
            break;
        case PARAM_L://l
            if(name[0]!='.'){
                display_attribute(buf,name);
                 printf(" \033[%dm%s\033[0m\n",clour,name);
            }
                break;
        case PARAM_R://R
             if(name[0]!='.'){
                display_double(name,flag);
             }
                break;
        case PARAM_r://r
            if(name[0]!='.'){
                display_single(name);
            }                               
            break;
         case PARAM_R+PARAM_r://Rr
             if(name[0]!='.'){
                display_double(name,flag);
             }
                break;
        case PARAM_A+PARAM_L://al
                display_attribute(buf,name);
                 printf(" \033[%dm%s\033[0m\n",clour,name);
                break;
        case PARAM_r+PARAM_L://rl
            if(name[0]!='.'){
                display_attribute(buf,name);
                 printf(" \033[%dm%s\033[0m\n",clour,name);
            }
                break;
        case PARAM_A+PARAM_r://ar
                display_single(name);
                break;
        case PARAM_A+PARAM_R://aR
                display_double(name,flag);
                break;
        case PARAM_L+PARAM_R://lR
                if(name[0]!='.'){
                display_attribute(buf,name);
                 printf(" \033[%dm%s\033[0m\n",clour,name);
                display_double(name,flag);
                }
                break;
        case PARAM_L+PARAM_R+PARAM_r://lRr
                if(name[0]!='.'){
                display_attribute(buf,name);
                 printf(" \033[%dm%s\033[0m\n",clour,name);
                display_double(name,flag);
                }
                break;
        case PARAM_A+PARAM_L+PARAM_r://alr
                display_attribute(buf,name);
                 printf(" \033[%dm%s\033[0m\n",clour,name);
                break;
        case PARAM_A+PARAM_R+PARAM_r://aRr
                display_double(name,flag);
                break;
        case PARAM_L+PARAM_R+PARAM_A://laR
                display_attribute(buf,name);
                 printf(" \033[%dm%s\033[0m\n",clour,name);
                display_double(name,flag);
                break;
        case PARAM_L+PARAM_R+PARAM_A+PARAM_r://laRr
                display_attribute(buf,name);
                 printf(" \033[%dm%s\033[0m\n",clour,name);
                display_double(name,flag);
                break;
        default:
               break;
    }
}

void display_inode(struct stat buf,char *name){
     int i,len1;

    if(g_leave_len< g_maxlen){
        printf("\n");
        g_leave_len=MAXROWLEN;
    }

    len1=strlen(name);
    len1= g_maxlen -len1;
    printf("%ld ",buf.st_ino);
    printf("\033[%dm%s\033[0m",clour,name);

    for(i=0;i<len1;i++){
        printf(" ");
    }
    printf("  ");
    g_leave_len-=(g_maxlen+2);
}

void display_size(struct stat buf,char *name){
     int i,len1;

    if(g_leave_len< g_maxlen){
        printf("\n");
        g_leave_len=MAXROWLEN;
    }

    long x=buf.st_blocks;
    int t=0;
    if(x==0) t=1;
    while(x){
        t++;
        x/=10;
    }
    x=4;
    t=x-t;
     
    for(i=0;i<t;i++){
        printf(" ");
    } 
    printf("%-ld ",buf.st_blocks);
    len1=strlen(name);
    len1= g_maxlen -len1;
    printf("\033[%dm%s\033[0m",clour,name);

    for(i=0;i<len1;i++){
        printf(" ");
    }
    printf("  ");
    g_leave_len-=(g_maxlen+2);
}

//打开文件
void display_dir(int flag_param,char *path){
    DIR *dir;//即打开文件目录，返回的就是指向DIR结构体的指针
    struct dirent *ptr;//dirent不仅仅指向目录，还指向目录中的具体文件
    int count=0;
    char temp[1024];//TODO
    int len1=strlen(PATH);
    int flag=0;
    char *path1;
    char *p=PATH1;
    char *q=path;
    int a=1;

    path1=PATH;
   
    if(p==NULL||q==NULL){
         my_err("pointer",__LINE__);
    }

    while(*p||*q){
        if(*p!=*q){
            a=0;
            break;    
        }
        p++;q++;
    }

    if(a==0) flag=0;
    else flag=1;

    if((flag_param & PARAM_R) != 0) //有-R --- 格式
    {
        int len = strlen(path);
        if(len>0)
        {
            if(path[len-1] != '/'){
                path[len] = '/';
                path[len+1]='\0';
            }
        }
       
        if(flag==1){
            PATH=path;
        }
        else if(path=="." || path[0] == '/'||PATH[len1-1]=='/')
        {
            PATH=my_strcat(PATH,path);
        }
        else
        {   
            PATH=my_strcat(PATH,path);
        }
    
        len=strlen(PATH);
        char r[len];
        strcpy(r,PATH);
        printf("%s:\n",r);
    }
   
   int len=strlen(PATH);
   char r[len+1];
   strcpy(r,PATH);
   r[len]='\0';
    dir=opendir(r);
  
    if(dir==NULL){
        my_err("opendir",__LINE__);
    }
    while((ptr=readdir(dir))!=NULL){
        if(g_maxlen<strlen(ptr->d_name))
            g_maxlen=strlen(ptr->d_name);
        count++;
    }
    closedir(dir);

    char filenames[count][1024];
    int i,j;
    len=strlen(r);//2
    dir=opendir(r);//1

    for(i=0;i<count;i++){
        ptr=readdir(dir);
        if(ptr==NULL){
            my_err("readdir",__LINE__);
        }
            
            strncpy(filenames[i],r,len);
            filenames[i][len]='\0';
           
            strcat(filenames[i],ptr->d_name);
            filenames[i][len+strlen(ptr->d_name)]='\0';
           
    }

    for(i=0;i<count-1;i++){
            for(j=0;j<count-1-i;j++){
                if((flag_param & PARAM_r) != 0){
                    if(strcmp(filenames[j],filenames[j+1])<0){
                        strcpy(temp,filenames[j+1]);
                        temp[strlen(filenames[j+1])]='\0';
                        strcpy(filenames[j+1],filenames[j]);
                        filenames[j+1][strlen(filenames[j])]='\0';
                        strcpy(filenames[j],temp);
                        filenames[j][strlen(temp)]='\0';
                        }
                }else{
                    if(strcmp(filenames[j],filenames[j+1])>0){
                        strcpy(temp,filenames[j+1]);
                        temp[strlen(filenames[j+1])]='\0';
                        strcpy(filenames[j+1],filenames[j]);
                        filenames[j+1][strlen(filenames[j])]='\0';
                        strcpy(filenames[j],temp);
                        filenames[j][strlen(temp)]='\0';
                        }
                }
            }
    }
 
       if(((flag_param & PARAM_R) != 0)&&((flag_param & PARAM_A)!=0)&&((flag_param & PARAM_L)==0)){//Ra
        for(int k=0;k<count;k++){
            int len1=strlen(filenames[k]);
            char name[len1];
            for(i=0,j=0;i<strlen(filenames[k]);i++){
                if(filenames[k][i]=='/'){
                j=0;
                continue;
                }
            name[j++]=filenames[k][i];
            }
            name[j]='\0';
           getclour(filenames[k]);
           display_single(name);
        }
    printf("\n");
    }else if(((flag_param & PARAM_R) != 0)&&((flag_param & PARAM_A)==0)&&((flag_param & PARAM_L)==0)){//R
         for(int k=0;k<count;k++){
            int len1=strlen(filenames[k]);
            char name[len1];
            for(i=0,j=0;i<strlen(filenames[k]);i++){
                if(filenames[k][i]=='/'){
                j=0;
                continue;
                }
            name[j++]=filenames[k][i];
            }
            name[j]='\0';
        if(name[0]!='.'){
            getclour(filenames[k]);
           display_single(name);
          }
        }
    printf("\n");
    }
  
    for(i=0;i<count;i++){
        PATH=r;
        display(flag_param,filenames[i]);
        if((flag_param & PARAM_R) != 0&&i==count-1){
            PATH=path1;
            if(PATH==PATH1)  return;
        }
    }
    closedir(dir);

    if((flag_param & PARAM_L)==0)
         printf("\n");
}

void display_double(char *name,int flag){
      DIR *dir;
      struct stat buf;
      int len1=strlen(PATH);
      int len2=strlen(name);

      name[len2]='\0';
      char r[len1+1];
      strcpy(r,PATH);

      char path1[len1+len2+1];
      strcpy(path1,r);
      path1[len1+len2]='\0';
      strcat(path1,name);
      path1[len1+len2]='\0';
   
     if(lstat(path1,&buf)==-1){
            my_err("stat",__LINE__);
      }

       if(S_ISDIR(buf.st_mode)){
           if((buf.st_mode & S_IRGRP) == 0 && (buf.st_mode & S_IROTH) == 0){
            printf("权限不足!\n");
            return;
        }else ;
       }else {
           return;
       }
    int t=0;
    if(strcmp(name,".")==0){
        t=1;
        return;
    }else if(strcmp(name,"..")==0){
        t=1;
        return;
    }
    printf("\n");
    if(t!=1)
    display_dir(flag,name);
    printf("\n");
    return;
}

char *my_strcat(char *p,char *q){
    int len1=strlen(p);
    int len2=strlen(q);
    char r[len1+len2+1];
    strcpy(r,p);
    strcat(r,q);
    r[len1+len2]='\0';
    p=r;
    return p;
}

void signal1(){
    signal(SIGINT, SIG_IGN);
}

int main(int argc,char **argv){
    int i,j,k,num;

    char param[32];   //命令行参数 不包括目标文件名 目录名
    int flag_param=PARAM_NONE;//参数种类
    struct stat buf;

    j=0;
    num=0;
    signal1();
    //获取属性
    for(i=1;i<argc;i++){
        if(argv[i][0]=='-'){
            for(k=1;k<strlen(argv[i]);k++,j++){
                param[j]=argv[i][k];
            }
            num++;
        }
    }

    for(i=0;i<j;i++){
        if(param[i]=='a'){
            flag_param |=PARAM_A;
            continue;
        }else if(param[i]=='l'){
            flag_param |=PARAM_L;
            continue;
        }else if(param[i]=='R'){
            flag_param |=PARAM_R;
            continue;
        }else if(param[i]=='r'){
            flag_param |=PARAM_r;
            continue;
        }else if(param[i]=='i'){
            flag_param |=PARAM_i;
            continue;
        }else if(param[i]=='s'){
            flag_param |=PARAM_s;
            continue;
        }else{
            printf("my_ls:invalied option -%c\n",param[i]);
            exit(1);
        }
    }
    param[j]='\0';
    
    if((num+1)==argc){
        PATH="./";
        PATH1=PATH;
        display_dir(flag_param,PATH);
        return 0;
    }

    char p[2]="./";
    i=1;
    do{
        if(argv[i][0]=='-'){
            i++;
            continue;
        }else{
            if(argv[i][0]=='.'&&argv[i][1]=='/'){
                PATH=argv[i];
            }else{
               my_strcat(p,argv[i]);
               PATH=p;
            }

            if(stat(PATH,&buf)==-1){
                my_err("stat",__LINE__);
            }
            
            if(S_ISDIR(buf.st_mode)){
                if(PATH[strlen(PATH)-1]!='/'){
                    char *q=PATH;
                    while(*q) q++;
                    *q='/';*q++;*q='\0';
                }else{
                    char *q=PATH;
                    while(*q) q++;
                    *q='\0';
                }
                    PATH1=PATH;
                    display_dir(flag_param,PATH);
                    i++;
            }else{
                display(flag_param,PATH);
                i++;
            }
        }
    }while(i<argc);
    return 0;
}