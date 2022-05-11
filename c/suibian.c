/*第一题   密码
#include<stdio.h>
#include<string.h>
int main(){
    int n,i;
    char a[50];
    scanf("%d",&n);
    scanf("%s",a);
    for(i=0;i<strlen(a);i++){
        a[i]=(a[i]-'a'+n)%26+'a';
    }
    printf("%s\n",a);
}
*/

/*第二题   孪生素数
#include<stdio.h>
int judge(int n);
int main(){
    int m,n;
    int i,cnt;
    cnt=0;
    scanf("%d%d",&m,&n);
    for(i=m;i<=n;i++){
        if(judge(i)==1&&judge(i+2)==1&&i+2<=n){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}

int judge(int n){
      int i;
      if(n==1)  return 0;
      else{
      for(i=2;i<n;i++){
          if(n%i==0){
              return 0;
          }
      }
    return 1;
      }
}
*/


/*
#include<stdio.h>
int main(){
    int n,i,j,t,cnt,k;
    cnt=0;
    int a[10]={6,2,5,5,4,5,6,3,7,6};
    scanf("%d",&n);
    t=n-4;
   for(i=0;;i++){
       for(j=0;;j++){
           if(i>9)
       }
   }
    printf("%d\n",cnt);
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
//void Print( List L ); /* 细节在此不表 */
/*
List Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}
*/
/* 你的代码将被嵌在这里 */
/*List Insert( List L, ElementType X ){
    PtrToNode p,r;
    for(p=L;p;p=p->Next){
         r=p->Next;
         if(X>=p->Data&&X<r->Data){
                PtrToNode q;
                q=(PtrToNode)malloc(sizeof(struct Node));
                q->Data=X;
                q->Next=r;
                p->Next=q;
         }
    }
    return (L);
}*/


/*
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {

   char a[10000];
   gets(a);
   int i=0;
   int count=0;
   int flag=0;
   for(i=0;i<strlen(a);i++){	  
   	  if(a[i]!=32){
   	  	 count++;   //记录一个单词由多少个字母组成
   	  }
	  else{
	  	if(count!=0){//将首个字母转换成大写  	
			if(a[i-count]>='a'&&a[i-count]<='z') a[i-count]-= 32;
		  	count=0;
	  	    }
	  }   	 	  
   }
   if(count>0) {    //最后一个单词
   	  if(a[i-count]>='a'&&a[i-count]<='z') a[i-count]-= 32;
   } 
   for(i=0;i<strlen(a);i++){
   		printf("%c",a[i]);
   } 
	return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
void func(char *a){
    printf("%lu\n",sizeof(a));
    printf("%lu\n",strlen(a));
}
int main(){
    char a[]="hello world";
    char *b="hello world";
    printf("%s",b);
    func(a);
    printf("%lu\n",sizeof(a));
    printf("%lu\n",strlen(a));
    return 0;
}*/

/*
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t  mutex;
pthread_cond_t  cond;

void *thread1(void *arg){

    pthread_cleanup_push(pthread_mutex_unlock,&mutex);

    while(1){
        printf("thread1 is running\n");
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond,&mutex);
        printf("thread1 applied the condition\n");
        pthread_mutex_unlock(&mutex);
        sleep(4);
    }

   pthread_cleanup_pop(0);
}


void *thread2(void *arg){
    while(1){
        printf("thread2 is running\n");
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond,&mutex);
        printf("thread1 applied the condition\n");
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}


int main(void){
    pthread_t tid1,tid2;

    printf("condition variable study!\n");
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    pthread_create(&tid1,NULL,(void *)thread1,NULL);
    pthread_create(&tid2,NULL,(void *)thread2,NULL);

    do{
        pthread_cond_signal(&cond);
    }while(1);

    sleep(50);
    pthread_exit(0);
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(){
    FILE *stream;
    char *filename="test";

    errno=0;

    stream=fopen(filename,"r");
    if(stream==NULL){
        printf("open file %s failed,errno is %d\n",filename,errno);

    }else{
        printf("open file %s successfully",filename);
    }
}*/

/*
#include<stdio.h>
#include<signal.h>

void handler_sigint(int signo){
    printf("recv SIGINT\n");
}

int main(){
    signal(SIGINT,handler_sigint);
    while(1)
    ;
    return 0;
}*/
/*
#include<stdio.h>
#include<string.h>
char *PATH;
char * my_strcat(char *p,char *q){
    printf("%s\n",p);
    printf("%s\n",q);
    int len1=strlen(p);
    int len2=strlen(q);
    char r[len1+len2+1];
    strcpy(r,p);
    strcat(r,q);
    r[len1+len2]='\0';
    p=r;
    printf("%s\n",r);
    printf("%s\n",p);
    return p;
    //while(*p) p++;
    //printf("1\n");
    //printf("%s\n",p);
    //printf("%s\n",q);
    //while((*p++=*q++)!='\0');
}

int main(){
    char *PATH,*path;
    PATH="./";
    path="666";
    PATH=my_strcat(PATH,path);
    printf("%s\n",PATH);
    printf("%s\n",path);
    return 0;
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
#define M 3
#define N 3
float* MeanStuFun(int p[M][N]);
int main()
{
    int stu[M][N];
    float* arr;
    float* MeanStuFun(int p[M][N]);
    int i,j;
    for(i=0;i<M;i++)
    {
        printf("please input the scores of NO.%d\n",i+1);
        for(j=0;j<N;j++)
            scanf("%d",&stu[i][j]);
    }
    arr=MeanStuFun(stu);
printf("\nevery student's mean score is:\n");
    for(i=0;i<M;i++)
        printf("%8.2f",*(arr+i));
    return 0;
}

float* MeanStuFun(int p[M][N])
{
    int i,j;
    float arr[M];
    float mean=0;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
            mean=mean+p[i][j];
        arr[i]=1.0*mean/N;
        mean=0;
    }
    return arr;
}*/

/*
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define true 1

void * One(void * no) 
{
    while (true)
    {
    printf("NUAACS1\n");
    sleep(1);
    }
}

void * Two(void * no) 
{
    while (true)
    {
    printf("NUAACS2\n");
    sleep(1);
    }
}

void Stop(int signo) 
{
    printf("oops! stop!!!\n");
    _exit(0);
}

int main()
{
    int res;
    pthread_t A, B;

    signal(SIGINT, Stop); 
    res = pthread_create(&A, NULL, One, NULL);
    res = pthread_create(&B, NULL, Two, NULL);
    res = pthread_join(A, NULL);
    res = pthread_join(B, NULL);

    return 0;
}*/

/*
#include<stdio.h>
#include<signal.h>
void handle_sigint(int signo){
    printf("recv SIGINT\n");
}
int main(){
    signal(SIGINT,handle_sigint);
    while(1);
    return 0;
}*/
/*
#include<signal.h>    
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){    
    printf("123\n");
   
    printf("23455");
    pause();
    for(int i=0;i<100;i++){
        printf("2345555555\n");
        for(int j=0;j<100;j++){
            printf("2222222223\n");
            for(int k=0;k<100;k++){
                printf("234\n");
            }
        }
    }
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_TREE_SIZE 100

typedef struct BiTNode{
    char  data;
    struct BiTNode *lchild,*rchild;
}BiNode,*BiTree;

void createbitree(BiTree *T){
    char  ch;
    scanf("%c",&ch);
    if(ch=='#')
     *T=NULL;
     else{
         *T=(BiTree)malloc(sizeof(BiNode));
         if(!*T)
            exit(-1);
        (*T)->data=ch;
        createbitree(&(*T)->lchild);
        createbitree(&(*T)->rchild);
     }
}

void PreOrderTraverse(BiTree T)//二叉树的先序遍历
{
    if(T==NULL)
        return ;
    printf("%c ",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T){
    if(T==NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c ",T->data);
    InOrderTraverse(T->rchild);
}

int main(){
    BiTree T;
    createbitree(&T);
    PreOrderTraverse(T);
    printf("\n");
    InOrderTraverse(T);
}*/


/*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
    int i;
    srand(time(0));
    for(i=0;i<10;i++){
        printf("%d\n",rand()%100+1);
    }
    return 0;
}*/

/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 20

typedef struct {
    int data;
    int cur;
}Component,s[MAXSIZE];

int ListLength(s L){
    int j=0;
    int i=L[MAXSIZE-1].cur;
    while(i){
        i=L[i].cur;
        j++;
    }
    return j;
}

int InitList(s space){
    int i;
    srand(time(0));
    for(i=0;i<MAXSIZE-1;i++){
        space[i].data=rand()%100+1;
        space[i].cur=i+1;
    }
    space[MAXSIZE-1].cur=0;
    for(i=0;i<20;i=space[i].cur){
        printf("%d ",space[i].data);
    }
    return 1;
}

int MALLOC_SLL(s space){
    int i=space[0].cur;

    if(space[0].cur)
        space[0].cur=space[i].cur;

    return i;
}

int ListInsert(s L,int i,int e){//插入e
    int j,k,l;
    k=MAXSIZE-1;
    if(i<1||i>ListLength(L)+1)  return 0;
    j=MALLOC_SLL(L);

    if(j){
        L[j].data=e;
        for(l=1;l<=i-1;l++){
            k=L[k].cur;
        }
        L[j].cur=L[k].cur;
        L[k].cur=j;
        return 1;
    }
    return 0;
}

void FREE_SSL(s space,int k){
    space[k].cur=space[0].cur;
    space[0].cur=k;
}

int ListDelete(s L,int i){
    int j,k;
    if(i<1||i>ListLength(L)){
        return 0;
    }
    k=MAXSIZE-1;
    for(j=1;j<=i-1;j++){
        k=L[k].cur;
    }
    j=L[k].cur;
    L[k].cur=L[j].cur;
    FREE_SSL(L,j);
    return 1;
}

int main(){
    s space;
    InitList(space);
    int i,e,t;
    for(i=0;i<ListLength(space);i=space[i].cur){
        printf("%d ",space[i].data);
    }
    scanf("%d%d",&t,&e);
    ListInsert(space,t,e);
    for(i=0;i<ListLength(space);i=space[i].cur){
        printf("%d ",space[i].data);
    }
    scanf("%d",&t);
    ListDelete(space,t);
    for(i=0;i<ListLength(space);i=space[i].cur){
        printf("%d ",space[i].data);
    }
    return 0;
}*/
//无项网图
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 10
#define INFINTIY 65535

typedef struct{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes,numEdges;
}MGraph;

void CreateMGraph(MGraph *G){
    int i,j,k,w;
    printf("输入顶点数和边数：\n");
    scanf("%d%d",&G->numVertexes,&G->numEdges);
    getchar();
    for(i=0;i<G->numVertexes;i++){
        //scanf(&G->vexs[i]);
       G->vexs[i]=getchar();
    }

    for(i=0;i<G->numVertexes;i++){
       for(j=0;j<G->numVertexes;j++){
           G->arc[i][j]=INFINTIY;
       }
    }

    for(k=0;k<G->numEdges;k++){
        printf("输入边上的下标i，下标j和权w：\n");
        scanf("%d%d%d",&i,&j,&w);
        G->arc[i][j]=w;
        G->arc[j][i]=G->arc[i][j];
    }

    for(i=0;i<G->numVertexes;i++){
        for(j=0;j<G->numVertexes;j++){
            printf("%5d ",G->arc[i][j]);
        }
        printf("\n");
    }

}
int main(){
    MGraph G;
    CreateMGraph(&G);
    return 0;
}*/
//邻接表
/*
#include<stdio.h>
#include<stdlib.h>

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 10

typedef struct dgeNode{
    int adjvex;
    EdgeType weight;
    struct dgeNode *next;
}EdgeNode;

typedef struct VertexNode{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct{
    AdjList adjList;
    int numVertexes,numedges;
}GraphAdjList;

void CreateALGraph(GraphAdjList *G){
    int i,j,k;
    EdgeNode *e;
    printf("输入顶点数和边数：\n");
    scanf("%d%d",&G->numVertexes,&G->numedges);
    printf("输入顶点信息：\n");

    for(i=0;i<G->numVertexes;i++){
        getchar();
        G->adjList[i].data=getchar();
        G->adjList[i].firstedge=NULL;
    }

    for(k=0;k<G->numedges;k++){
        printf("输入顶点i,j上的顶点序号:\n");
        scanf("%d%d",&i,&j);
        e=(EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex=j;
        e->next=G->adjList[i].firstedge;
        G->adjList[i].firstedge=e;

        e=(EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex=i;
        e->next=G->adjList[j].firstedge;
        G->adjList[j].firstedge=e;
    }
    
    for(i=0;i<G->numVertexes;i++){
        printf("%c->",G->adjList[i].data);  
        while(1)  
        {             
			if(G->adjList[i].firstedge==NULL)
            {
            	printf("^");
				break;	
			}
            printf("%d->",G->adjList[i].firstedge->adjvex);
            G->adjList[i].firstedge=G->adjList[i].firstedge->next;  
        }  
        printf("\n");  
    }  
    
}

int main(){
    GraphAdjList G;
    CreateALGraph(&G);
}*/

//DFS  BFS 邻接矩阵
/*
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20
#define MAX 20
#define True 1
#define Flase 0
typedef int boolean;
boolean visited[MAX];

typedef struct{
    char vex[MAX];
    int arc[MAX][MAX];
    int nums,points;
}MGraph;

typedef struct{
    int data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

void InitQueue(SqQueue *Q){
    Q->front=0;
    Q->rear=0;
}

int EnQueue(SqQueue *Q,int e){
    if((Q->rear+1)%MAXSIZE==Q->front)
        return -1;
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return 0;
}

int DeQueue(SqQueue *Q,int *e){
    if(Q->front==Q->rear)
        return -1;
    *e=Q->data[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return 0;
}

void CreateMgraph(MGraph *G){
    int i,j,k;
    printf("输入顶点数和边数：\n");
    scanf("%d%d",&G->points,&G->nums);
    printf("输入顶点信息：\n");

    for(i=0;i<G->points;i++){
        getchar();
        G->vex[i]=getchar();
    }

    for(i=0;i<G->points;i++){
        for(j=0;j<G->points;j++){
            G->arc[i][j]=0;
        }
    }

    for(k=0;k<G->nums;k++){
        printf("输入连接的两点\n");
        scanf("%d%d",&i,&j);
        G->arc[i][j]=1;
        G->arc[j][i]=G->arc[i][j];
    }

    for(i=0;i<G->points;i++){
        for(j=0;j<G->points;j++){
            printf("%3d ",G->arc[i][j]);
        }
        printf("\n");
    }
}

void DFS(MGraph *G,int i){
    int j;
    visited[i]=True;
    printf("%c ",G->vex[i]);
    for(j=0;j<G->points;j++){
        if(G->arc[i][j]==1&&!visited[j])
            DFS(G,j);
    }
}

void DFSTraverse(MGraph *G){
    int i;
    for(i=0;i<G->points;i++){
        visited[i]=Flase;
    }
    i=0;
   // for(i=0;i<G->points;i++){
        if(!visited[i]) DFS(G,i);
   // }
}

int QueueEmpty(SqQueue Q){
    if(Q.front==Q.rear)
    return 1;
    else 
    return 0;
}

void BFSTraverse(MGraph *G){
    int i,j;
    SqQueue Q;

    for(i=0;i<G->points;i++)
        visited[i]=Flase;

    InitQueue(&Q);

    for(i=0;i<G->points;i++){
        if(!visited[i]){
            visited[i]=True;
            printf("%c ",G->vex[i]);
            EnQueue(&Q,i);
            while(!QueueEmpty(Q)){
                DeQueue(&Q,&i);
                for(j=0;j<G->points;j++){
                    if(G->arc[i][j]==1&&!visited[j]){
                        visited[j]=True;
                        printf("%c ",G->vex[j]);
                        EnQueue(&Q,j);
                    }
                }
            }
        }
    }
}

int main(){
    MGraph G;
    CreateMgraph(&G);
    DFSTraverse(&G);
    printf("\n");
    BFSTraverse(&G);
    return 0;
}
*/
//队列
/*
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20
typedef struct{
    int data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

int InitQueue(SqQueue *Q){
    Q->front=0;
    Q->rear=0;
    return 0;
}

int QueueLength(SqQueue Q){
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

int EnQueue(SqQueue *Q,int e){
    if((Q->rear+1)%MAXSIZE==Q->front)
    return -1;
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return 0;
}

int DeQueue(SqQueue *Q){
    if(Q->front==Q->rear)
    return -1;
    //*e=Q->data[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;

    return 0;
}
int main(){
    SqQueue Q;
    int e,i;
    int t;
   
    InitQueue(&Q);
    while(1){
        printf("输入添加的数：\n");
        scanf("%d",&e);
        if(e==0)  break;
        EnQueue(&Q,e);
    }

    for(i=Q.front;i<Q.rear;i++){
        printf("%d ",Q.data[i]);
    }
    printf("\n");
    DeQueue(&Q);
    for(i=Q.front;i<Q.rear;i++){
        printf("%d ",Q.data[i]);
    }
    printf("\n");
    //printf("%d ",t);
}*/

//prim kruskal Dijkstra Floyd
/*
#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 9
typedef int Pathmatirx[MAXVEX];
typedef int ShortPathTable[MAXVEX];
typedef int Pathmatirx1[MAXVEX][MAXVEX];
typedef int ShortPathTable1[MAXVEX][MAXVEX];

#define max 9
#define INFINITY 65525
#define MAXEDGE 9

typedef struct{
    char vex[max];
    int arc[max][max];
    int nums,points;
}MGraph;

typedef struct {
    int begin;
    int end;
    int weight;
}Edge;

void createMGraph(MGraph *G){
    int i,j,k,w;
    printf("输入顶点数和边数：\n");
    scanf("%d%d",&G->points,&G->nums);

    printf("输入顶点信息：\n");
    for(i=0;i<G->points;i++){
        getchar();
        G->vex[i]=getchar();
    }

    for(i=0;i<G->points;i++){
        for(j=0;j<G->points;j++){
            if(i==j) G->arc[i][j]=0;
            else
            G->arc[i][j]=INFINITY;
        }
    }

    for(k=0;k<G->nums;k++){
        printf("输入边的顶点下标：\n");
        scanf("%d%d",&i,&j);
        printf("输入数值：\n");
        scanf("%d",&w);
        G->arc[i][j]=w;
        G->arc[j][i]=G->arc[i][j];
    }

     for(i=0;i<G->points;i++){
        for(j=0;j<G->points;j++){
            printf("%6d ",G->arc[i][j]);
        }
        printf("\n");
    }
}

int Find(int *parent,int f)
{
   //printf("%d \n",f);
    //printf("%d\n",parent[f]);
    while(parent[f]>0)   f=parent[f];

    return f;
}

void get_bian(MGraph *G,Edge *edges)
{
    int i,j,k;
    k=0;
    for(i=0;i<G->points;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(G->arc[i][j]!=0&&G->arc[i][j]<INFINITY)
            {
                edges[k].begin=i;
                edges[k].end=j;
                edges[k].weight=G->arc[i][j];
                k++;
            }
        }
    }
}

void sort(Edge *edges,int k)
{
    int i,j;
    Edge t;
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(edges[i].weight>edges[j].weight)
            {
                t=edges[i];
                edges[i]=edges[j];
                edges[j]=t;
            }
        }
    }
}

void MIniSpanTree_Kruskal(MGraph *G){
    int i,n,m;
    Edge *edges;
    int parent[max];
    edges=(Edge *)malloc(sizeof(Edge)*max);
    get_bian(G,edges);
    sort(edges,G->nums);

    for(i=0;i<G->points;i++)
        parent[i]=0;

    for(i=0;i<G->nums;i++)
    {
        n=Find(parent,edges[i].begin);
        m=Find(parent,edges[i].end);
        if(n!=m)
        {
            parent[n]=m;
            printf(" (%d,%d) %d ",edges[i].begin,edges[i].end,edges[i].weight);
        }
    }
    free(edges);
}

void MiniSpanTree_Prim(MGraph *G){
    int min,i,j,k;
    int adjvex[max];
    int lowcost[max];
    lowcost[0]=0;
    adjvex[0]=0;

    for(i=1;i<G->points;i++){
        lowcost[i]=G->arc[0][i];
        adjvex[i]=0;
    }

    for(i=1;i<G->points;i++){
        min=INFINITY;
        j=1;k=0;

        while(j<G->points){
            if(lowcost[j]!=0&&lowcost[j]<min){
                min=lowcost[j];
                k=j;
            }
            j++;
        }

        printf("(%d,%d)",adjvex[k],k);
        lowcost[k]=0;

        for(j=1;j<G->points;j++){
            if(lowcost[j]!=0&&G->arc[k][j]<lowcost[j]){
                lowcost[j]=G->arc[k][j];
                adjvex[j]=k;
            }
        }

    }
}

void ShorttestPath_Dijkstra(MGraph *G,int v0,Pathmatirx *P,ShortPathTable *D)
{//p最短路径 d带权长度
    int v,w,k,min;
    int final[MAXVEX];

    for(v=0;v<G->points;v++){
        final[v]=0;
        (*D)[v]=G->arc[v0][v];
        (*P)[v]=0;
    }
    (*D)[v0]=0;
    final[v0]=1;

    for(v=1;v<G->points;v++)
    {
        min=INFINITY;
        for(w=0;w<G->points;w++)
        {
            if(!final[w]&&(*D)[w]<min)
            {
                k=w;
                min=(*D)[w];
            }
        }
        final[k]=1;
        for(w=0;w<G->points;w++)
        {
            if(!final[w]&&(min+G->arc[k][w]<(*D)[w]))
            {
                (*D)[w]=min+G->arc[k][w];
                (*P)[w]=k;
            }
        }
    }
    
}

void ShorttestPath_Floyd(MGraph *G, Pathmatirx1 *p,ShortPathTable1 *D)
{
    int v,w,k;
    for(v=0;v<G->points;v++)
    {
        for(w=0;w<G->points;w++)
        {
            (*D)[v][w]=G->arc[v][w];
            (*p)[v][w]=w;
        }
    }

    for(k=0;k<G->points;k++)
    {
        for(v=0;v<G->points;v++)
        {
            for(w=0;w<G->points;w++)
            {
                if((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
                {
                    (*D)[v][w]=(*D)[v][k]+(*D)[k][w];
                    (*p)[v][w]=(*p)[v][k];
                }
            }
        }
    }

    for(v=0;v<G->points;v++)
    {
        for(w=v+1;w<G->points;w++)
        {
            printf("v%d-v%d weight: %d ",v,w,(*D)[v][w]);
            k=(*p)[v][w];
            printf(" path: %d ",v);
            while(k!=w)
            {
                printf("-> %d ",k);
                k=(*p)[k][w];
            }
            printf("-> %d \n",w);
        }
        printf("\n");
    }
}
int main(){
    MGraph G;
    Pathmatirx P;
    ShortPathTable D;//不能加* 二维数组
    Pathmatirx1 E;
    ShortPathTable1 F;//不能加* 二维数组
    createMGraph(&G);
    printf("\n\n\n");
    MiniSpanTree_Prim(&G);
    printf("\n\n\n");
    MIniSpanTree_Kruskal(&G);
    printf("\n\n\n");
    ShorttestPath_Dijkstra(&G,0,&P,&D);
     for(int i=0;i<G.points;i++){
        printf("%d %d\n",P[i],D[i]);
    }
    printf("\n\n\n");
    ShorttestPath_Floyd(&G, &E,&F);
    //for(int i=0;i<G.points;i++){
      //  for(int j=0;j<G.points;j++)
       // {
         //   printf("%d,%d  ",E[i][j],F[i][j]);
        //}
        //printf("\n");
    //}
    return 0;
}
*/

//topo
/*
#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30

typedef struct EdgeNode{
    int adjvex;
    int weight;
    struct EdgeNode *next;
}EdgeNode;

typedef struct{
    int in;
    char data;
    EdgeNode *firstedge;
}AdjList[MAXVEX];

typedef struct {
    AdjList adjlist;
    int pointers,nums;
}MGraph;
int *etv,*ltv;
int *stack2;
int top2;
void display(MGraph *G);

void creategraph(MGraph *G)
{
    int i,j,k,t;
    EdgeNode *e;
    
    printf("输入点数和边数：\n");
    scanf("%d%d",&G->pointers,&G->nums);
    
    printf("输入顶点信息：\n");
    for(i=0;i<G->pointers;i++)
    {
        getchar();
        G->adjlist[i].data=getchar();
        G->adjlist[i].in=0;
        G->adjlist[i].firstedge=NULL;
    }

    for(k=0;k<G->nums;k++)
    {
        printf("输入顶点序号：\n");
        scanf("%d%d",&i,&j);
        e=(EdgeNode *)malloc(sizeof(EdgeNode));
        printf("输入权重：\n");
        scanf("%d",&t);
        e->weight=t;
        e->adjvex=j;
        e->next=G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=e;

        G->adjlist[j].in++;
    }
}

void display(MGraph *G)
{
    int i;
    for(i=0;i<G->pointers;i++)
    {
        printf("in:%d   ",G->adjlist[i].in);
        printf("%c-> ",G->adjlist[i].data);
        while(1)
        {
            if(G->adjlist[i].firstedge==NULL)
            {
                printf("^");
                break;
            }
            printf("%d-> ",G->adjlist[i].firstedge->adjvex);
            G->adjlist[i].firstedge=G->adjlist[i].firstedge->next;
        }
        printf("\n");
    }
}

int TopologicalSort(MGraph *G)
{
    EdgeNode *e;
    int i,k,gettop;
    int top=0;
    int count=0;
    int *stack;
    stack=(int *)malloc(G->pointers*sizeof(int));

    for(i=0;i<G->pointers;i++)
    {
        if(G->adjlist[i].in==0)
        {
             stack[top]=i;
             top++;
        }
           
    }
   
    while(top!=0)
    {
        top--;
        gettop=stack[top];
       
        printf("%c->",G->adjlist[gettop].data);
        count++;
        for(e=G->adjlist[gettop].firstedge;e;e=e->next)
        {
            k=e->adjvex;
            G->adjlist[k].in--;
            if(G->adjlist[k].in==0)
            {
                stack[top]=k;
                top++;
            }
        }
    }
   // printf("\b\b");
    //printf("\n%d\n",count);
    if(count<G->pointers)
        return -1;
    else{
       return 0;
    }
}

int TopologicalSort1(MGraph *G)
{
    EdgeNode *e;
    int i,k,gettop;
    int top=0;
    int count=0;
    int *stack;
    stack=(int *)malloc(G->pointers*sizeof(int));
    for(i=0;i<G->pointers;i++)
    {
        if(G->adjlist[i].in==0)
        {
            stack[top]=i;
            top++;
        }
    }
    top2=0;
    etv=(int *)malloc(G->pointers*sizeof(int));
    for(i=0;i<G->pointers;i++)
    {
        etv[i]=0;
    }
    stack2=(int *)malloc(G->pointers*sizeof(int));
    while(top!=0)
    {
        top--;
        gettop=stack[top];
        count++;

        stack2[top2]=gettop;
        top2++;
        for(e=G->adjlist[gettop].firstedge;e;e=e->next)
        {
            k=e->adjvex;
            G->adjlist[k].in--;
            if(G->adjlist[k].in==0)
            {
                stack[top]=k;
                top++;
            }
            if((etv[gettop]+e->weight)>etv[k])
                etv[k]=etv[gettop]+e->weight;
        }
    }
    if(count<G->nums) return -1;
    else return 0;
}

void CriticalPath(MGraph *G)
{
    EdgeNode *e;
    int i,j,k,gettop;
    int ete,lte;
    TopologicalSort1(G);
    ltv=(int *)malloc(G->pointers*sizeof(int));
    for(i=0;i<G->pointers;i++)
        ltv[i]=etv[G->pointers-1];
    
    while(top2!=0)
    {
        top2--;
        gettop=stack2[top2];
        for(e=G->adjlist[gettop].firstedge;e;e=e->next)
        {
            k=e->adjvex;
            if(ltv[k]-e->weight<ltv[gettop])
            {
                ltv[gettop]=ltv[k]-e->weight;
            }
        }
    }
    
    for(j=0;j<G->pointers;j++)
    {
        for(e=G->adjlist[j].firstedge;e;e=e->next)
        {
            k=e->adjvex;
            ete=etv[j];
            lte=ltv[k]-e->weight;
            if(ete=lte)
            printf("<v%c,v%c>length:%d\n",G->adjlist[j].data,G->adjlist[k].data,e->weight);
        }
    }
}
int main()
{
    MGraph G;
    creategraph(&G);
    //display(&G);
    //TopologicalSort(&G);
    // TopologicalSort1(&G);
     CriticalPath(&G);
    return 0;
}*/
//kmp
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char String[20];

void get_next(String T,int *next)
{
    int i,j;
    i=1;j=0;
    next[1]=0;
    while(i<T[0])
    {
        if(j==0||T[i]==T[j])
        {
            i++;j++;
            next[i]=j;
        }
        else 
            j=next[j];
    }
}

void get_nextval(String T,int *nextval)
{
    int i,j;
    i=1;j=0;
    nextval[1]=0;
    while(i<T[0])
    {
        if(j==0||T[i]==T[j])
        {
            i++;j++;
            if(T[i]!=T[j])
            {
                nextval[i]=j;
            }else{
                nextval[i]=nextval[j];
            }
        }else
            j=nextval[j];
    }
  
}

int Index_KMP(String S,String T,int pos)
{
    int i=pos;
    int j=1;
    //int next[255];
     int nextval[255];
    //get_next(T,next);
    get_nextval(T,nextval);
    while(i<=S[0]&&j<=T[0])
    {
        if(j==0||S[i]==T[j])
        {
            j++;i++;
        }else{
            //j=next[j];
            j=nextval[j];
        }
    }
    if(j>T[0])  return i-T[0];
    else return 0;
}

int main()
{
    char S[20]="aaaabcde";
    char T[20]="bcde";
    int t;
    t=9;
    t=Index_KMP(S,T,1);
    printf("%d ",t);
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
   // char a[]="7aasdf";
    //int b;
    //b=atoi(a);
    //printf("%d",b);
  char a[4][5]={"cd","-l",">","a"};
  char *b[5];
  int i;
  int flag=0;
  for(i=0;i<4;i++)
  {
      b[i]=(char *)a[i];
  }
  b[i]=NULL;
  for(i=0;b[i]!=NULL;i++)
  {
      if(strncmp(b[i],"cd",2)==0)
      {
          printf("123\n");
          flag=1;
      }else

      if(strncmp(b[i],">",1)==0){
          printf("456\n");
          flag=1;
      }

      if(flag==0){
          printf("wrong\n");
      }
  }
   return 0;
}*/
/*
#include<stdlib.h>
#include<stdio.h>
int main()
{
char *p;
if((p = getenv("USER")));
printf("USER =%s\n",p);
putenv("USER=test");
printf("USER=%s\n",getenv("USER"));
}*/
//#include <stdio.h>
//带有宏定义函数的头文件
//#include <ctrlcur.h>
/*
 #include <stdio.h>
 #include <unistd.h>
//清屏
#define CLEAR() printf("\033[2J")
 
// 上移光标
#define MOVEUP(x) printf("\033[%dA", (x))
 
// 下移光标
#define MOVEDOWN(x) printf("\033[%dB", (x))
 
// 左移光标
#define MOVELEFT(y) printf("\033[%dD", (y))
 
// 右移光标
#define MOVERIGHT(y) printf("\033[%dC",(y))
 
// 定位光标
#define MOVETO(x,y) printf("\033[%d;%dH", (x), (y))
 
// 光标复位
#define RESET_CURSOR() printf("\033[H")
// 隐藏光标
#define HIDE_CURSOR() printf("\033[?25l")
 
// 显示光标
#define SHOW_CURSOR() printf("\033[?25h")
 
//清除从光标到行尾的内容
#define CLEAR_LINE() printf("\033[K")
//反显
#define HIGHT_LIGHT() printf("\033[7m")
#define UN_HIGHT_LIGHT() printf("\033[27m")
 
//设置颜色
#define SET_FRONT_COLOR(color) printf("\033[%dm",(color))
#define SET_BACKGROUND_COLOR(color) printf("\033[%dm",(color))
//前景色
#define FRONT_BLACK 30
#define FRONT_RED 31
#define FRONT_GREEN 32
#define FRONT_YELLOW 33
#define FRONT_BLUE 34
#define FRONT_PURPLE 35
#define FRONT_DEEP_GREEN 36
#define FRONT_WHITE 37
 
//背景色
#define BACKGROUND_BLACK 40
#define BACKGROUND_RED 41
#define BACKGROUND_GREEN 42
#define BACKGROUND_YELLOW 43
#define BACKGROUND_BLUE 44
#define BACKGROUND_PURPLE 45
#define BACKGROUND_DEEP_GREEN 46
#define BACKGROUND_WHITE 47
int main(int argc,char **argv)
{
        //利用宏定义函数
        SET_BACKGROUND_COLOR(BACKGROUND_RED);
        printf("前白后红");
        sleep(3);
        SET_FRONT_COLOR(FRONT_BLUE);
        printf("前蓝后红");
        sleep(3);
        SET_BACKGROUND_COLOR(BACKGROUND_BLACK);
        SET_FRONT_COLOR(FRONT_WHITE);
        printf("开始测试光标移动:");
        sleep(3);
        MOVEDOWN(5);
        printf("下移5格后打印的结果");
        sleep(3);
        MOVEUP(3);
        printf("再上移3格后打印的结果");
        sleep(3);
        MOVETO(12,12);
        printf("移动到12,12后打印的结果");
        sleep(3);
        
        //直接使用控制语句
        printf("\033[31mThe color,%s!\033[1m\n"," 1");
        printf("\033[31mThe color,%s!\033[4m\n"," 2");
        printf("\033[31mThe color,%s!\033[5m\n"," 3");
        printf("\033[31mThe color,%s!\033[7m\n"," 4");
        printf("\033[31mThe color,%s!\033[8m\n"," 5");
        printf("\033[31mThe color,%s!\033[0m\n"," 6");
        printf("\033[47;31mThe color,%s!\033[0m\n"," 7");
        printf("\033[47mThe color,%s!\033[0m\n"," 8");
        sleep(2);
        printf("\033[45m%s!\033[5A\n","up 5");
        sleep(2);
        printf("\033[44m%s!\033[9B\n","down 9");
        sleep(2);
        printf("\033[43m%s!\033[19C\n","right 19");
        printf("right19");
        sleep(2);
        printf("\033[46m%s!\033[10D\n","left 10");
        printf("left 10");
        sleep(2);
        printf("\033[44m%s!\033[50;20H\n","move to y:50,x 20");
        printf("y50 x 20");
        sleep(2);
        printf("\033[44m%s!\033[?25l\n","hide cursor");
        sleep(2);
        printf("\033[40m%s!\033[?25h\n","sow cursor");
        sleep(2);
        //printf("\033[47m%s!\033[2J\n","clear scleen");
        sleep(2);
        return 0;
}*/

/*
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

typedef void*(*FUNC)(void* arg);                //指向函数的指针，用来指向我的线程函数。
typedef struct _thpool_jobqueue                 //任务队列
{
    FUNC                     routine;           //定义指向线程函数的指针routine
    void*                    arg;               //传向线程函数的参数
    struct _thpool_jobqueue  *next;
}thpool_jobqueue;
typedef struct _thpool_t                        //线程池
{
    int               max_thr_num;              //线程池的尺寸
    int               flag;                     //是否销毁的标志
    pthread_t         *thr_id;                  //线程ID指针
    pthread_cond_t    jobqueue_cond;            //条件变量
    pthread_mutex_t   jobqueue_mutex;           //互斥锁
    thpool_jobqueue   *jobqueue_head;           //指向任务队列的指针
}thpool_t;
static thpool_t * thpool = NULL;                //全局变量，指向线程池的指针
*/
/*建议：为了结构更清晰，请从main函数开始，然后线程创建函数--->任务添加函数--->线程函数*/

/*
void *thread_routine()                          //线程函数
{
    thpool_jobqueue *work;                        
    while(1)
    {
        pthread_mutex_lock(&thpool->jobqueue_mutex);              
        while((thpool->jobqueue_head == NULL) &&( thpool->flag == 0)) //如果此时没有任务，并且不打算销毁线程池
        {
            pthread_cond_wait(&thpool->jobqueue_cond,&thpool->jobqueue_mutex);//       就让抢到锁的在此等待，其他线程在锁的外边阻塞
        }
        if(thpool->flag != 0)                                         //每次可以执行的时候都判断下线程池是否要销毁
        {
            pthread_mutex_unlock(&thpool->jobqueue_mutex);
            pthread_exit(0);
        }
        work = thpool->jobqueue_head;                                 //若不销毁，则将任务添加到任务队列
        thpool->jobqueue_head = thpool->jobqueue_head->next;          //让任务指针指向下一个
        pthread_mutex_unlock(&thpool->jobqueue_mutex);
        work->routine(work->arg);                                     //work->routine = routine = func1
        free(work);
    }
}

void thpool_add_task(void*(*routine)(void *),void* arg)        //任务添加函数
{
    thpool_jobqueue  *work,*member;

    work = (thpool_jobqueue*)malloc(sizeof(thpool_jobqueue));  //准备任务，将添加到任务队列
    work->routine = routine;
    work->arg = arg;
    work->next = NULL;
    pthread_mutex_lock(&thpool->jobqueue_mutex);               //对任务队列操作必须保证只有一个线程
    member = thpool->jobqueue_head;
    if(!member)
    {
        thpool->jobqueue_head = work;                          //如果此任务是第一个任务
    }
    else
    {
        while(member->next != NULL)                            //如果不是第一个任务就添加到最后
            member = member->next;
        member->next = work;
    }
    pthread_cond_signal(&thpool->jobqueue_cond);
    pthread_mutex_unlock(&thpool->jobqueue_mutex);
}

void thpool_create(int max_thr_num)                   //线程创建函数
{
    int i;   
    thpool = (thpool_t *)malloc(sizeof(thpool_t));    
    if(!thpool)
    {
        perror("malloc thpool error");
    }
    thpool->flag = 0;                                 //初始化的过程
    thpool->max_thr_num = max_thr_num;                
    thpool->thr_id = (pthread_t*)malloc(max_thr_num*sizeof(pthread_t));
    thpool->jobqueue_head = NULL;
    pthread_mutex_init(&thpool->jobqueue_mutex,NULL);
    pthread_cond_init(&thpool->jobqueue_cond,NULL);
    for(i = 0;i < max_thr_num;i++)
    {
        pthread_create(&thpool->thr_id[i],NULL,thread_routine,NULL);  //创建线程的过程
    }
}

void thpool_destroy()                            //销毁线程池
{
    printf("线程池正在销毁\n");
    int i;
    thpool_jobqueue *member;  
    if(thpool->flag != 0)                        //先判断一下销毁标志是否已经销毁
    {
        return;
    }
    thpool->flag = 1;                            //将销毁标志至为1，即需要销毁
    pthread_mutex_lock(&thpool->jobqueue_mutex); 
    pthread_cond_broadcast(&thpool->jobqueue_cond);  //广播所有线程要销毁的通知
    pthread_mutex_unlock(&thpool->jobqueue_mutex);   
    for(i = 0;i < thpool->max_thr_num;i++)          
    {
        pthread_join(thpool->thr_id[i],NULL);     //等待所有线程都结束
    }
        free(thpool->thr_id);                      //将所有线程ID释放
    while(thpool->jobqueue_head)
    {
        member = thpool->jobqueue_head;
        thpool->jobqueue_head = thpool->jobqueue_head->next;
        free(member);                              //释放每一个任务
    }
    pthread_mutex_destroy(&thpool->jobqueue_mutex);//销毁锁
    pthread_cond_destroy(&thpool->jobqueue_cond);  //销毁条件变量
    free(thpool);                                  //销毁指向线程池的指针
    printf("销毁完成\n");

}

void *func1()
{
    printf("thread %lu is running\n",pthread_self());
    sleep(3);                                     //让别的线程有机会抢锁
}

int main(int argc,char *argv[])
{
    int i;

    thpool_create(5);                             //在线程池里创建5个线程
    for(i = 0;i < 10;i++)
    {
        thpool_add_task(func1,NULL);
    }
    sleep(10);
    thpool_destroy();
}
*/

/*
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
int main(void)
{
    time_t current = time(NULL);
    char* string;
 */
    /*把日期和时间转为字符串*/
    /*
    string = ctime(&current);
    if (current == (time_t)-1)
    {
        printf("Fail to get the current time!\n");
    }
 
    printf("The current time is %s", string);
    printf("(%ld seconds since the Epoch)\n",current);
}*/



/*
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>

sem_t chopstick[6] ;

void *eat_think(void *arg)
{
	char phi = *(char *)arg;
	int left,right;
	switch (phi){
		case 'A':
			left = 5;
			right = 1;
			break;
		case 'B':
			left = 1;
			right = 2;
			break;
		case 'C':
			left = 2;
			right = 3;
			break;
		case 'D':
			left = 3;
			right = 4;
			break;
		case 'E':
			left = 4;
			right = 5;
			break;
	}

	int i;
	for(;;) {
            usleep(3);
            sem_wait(&chopstick[left]);
            printf("Philosopher %c fetches chopstick %d\n", phi, left);
            if (sem_trywait(&chopstick[right]) < 0) {	
                sem_post(&chopstick[left]); 
                continue;
            }
            printf("Philosopher %c fetches chopstick %d\n", phi, right);
            printf("Philosopher %c is eating.\n",phi);
            usleep(3);
            sem_post(&chopstick[left]); 
            printf("Philosopher %c release chopstick %d\n", phi, left);
            sem_post(&chopstick[right]);
            printf("Philosopher %c release chopstick %d\n", phi, right);
	}
}

int main()
{
	pthread_t A,B,C,D,E;

	int i;
	for (i = 0; i < 5; i++)
		sem_init(&chopstick[i],0,1);
	pthread_create(&A, NULL, eat_think, "A");
	pthread_create(&B, NULL, eat_think, "B");
	pthread_create(&C, NULL, eat_think, "C");
	pthread_create(&D, NULL, eat_think, "D");
	pthread_create(&E, NULL, eat_think, "E");

	pthread_join(A, NULL);
	pthread_join(B, NULL);
	pthread_join(C, NULL);
	pthread_join(D, NULL);
	pthread_join(E, NULL);
	return 0;
}
*/
/*

#include <stdio.h>  
#include <stdlib.h>  
#include "mysql.h"

int main (int argc, char *argv[])
 {  

    MYSQL *conn;  

    // 步骤1： 初始化连接句柄  
    conn = mysql_init(NULL);  

    if (conn == NULL) { // 如果返回NULl说明初始化失败  
        printf("mysql_init failed!\n");   
        return EXIT_FAILURE;  
    }  

    // 步骤2：实际进行连接  
    // 参数分别为，conn连接句柄，host是MySQL所在主机或地址，user用户名，password密码，database_name数据库名，后面的都是默认  
    conn = mysql_real_connect(conn, "localhost", "root", "hh123456789", "dev2", 0, NULL, 0);  

    if (conn) { // 连接成功  
        printf("Connection success!\n");      
    } else {  
        printf("Connection failed!\n");   
    }  

    // 步骤3： 退出前关闭连接  
    mysql_close(conn);  

    return 0;  
} 
*/

/*

#include <stdio.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1024 /*监听上限*/
/*
#define BUFLEN  4096    /*缓存区大小*/
/*
#define SERV_PORT 6666  /*端口号*/

/*
void recvdata(int fd,int events,void *arg);
void senddata(int fd,int events,void *arg);
*/
/*描述就绪文件描述符的相关信息*/
/*
struct myevent_s
{
    int fd;             //要监听的文件描述符
    int events;         //对应的监听事件，EPOLLIN和EPLLOUT
    void *arg;          //指向自己结构体指针
    void (*call_back)(int fd,int events,void *arg); //回调函数
    int status;         //是否在监听:1->在红黑树上(监听), 0->不在(不监听)
    char buf[BUFLEN];   
    int len;
    long last_active;   //记录每次加入红黑树 g_efd 的时间值
};

int g_efd;      //全局变量，作为红黑树根
struct myevent_s g_events[MAX_EVENTS+1];    //自定义结构体类型数组. +1-->listen fd
*/

/*
 * 封装一个自定义事件，包括fd，这个fd的回调函数，还有一个额外的参数项
 * 注意：在封装这个事件的时候，为这个事件指明了回调函数，一般来说，一个fd只对一个特定的事件
 * 感兴趣，当这个事件发生的时候，就调用这个回调函数
 */
/*
void eventset(struct myevent_s *ev, int fd, void (*call_back)(int fd,int events,void *arg), void *arg)
{
    ev->fd = fd;
    ev->call_back = call_back;
    ev->events = 0;
    ev->arg = arg;
    ev->status = 0;
    if(ev->len <= 0)
    {
        memset(ev->buf, 0, sizeof(ev->buf));
        ev->len = 0;
    }
    ev->last_active = time(NULL); //调用eventset函数的时间
    return;
}
*/
/* 向 epoll监听的红黑树 添加一个文件描述符 */
/*
void eventadd(int efd, int events, struct myevent_s *ev)
{
    struct epoll_event epv={0, {0}};
    int op = 0;
    epv.data.ptr = ev; // ptr指向一个结构体（之前的epoll模型红黑树上挂载的是文件描述符cfd和lfd，现在是ptr指针）
    epv.events = ev->events = events; //EPOLLIN 或 EPOLLOUT
    if(ev->status == 0)       //status 说明文件描述符是否在红黑树上 0不在，1 在
    {
        op = EPOLL_CTL_ADD; //将其加入红黑树 g_efd, 并将status置1
        ev->status = 1;
    }
    if(epoll_ctl(efd, op, ev->fd, &epv) < 0) // 添加一个节点
        printf("event add failed [fd=%d],events[%d]\n", ev->fd, events);
    else
        printf("event add OK [fd=%d],events[%0X]\n", ev->fd, events);
    return;
}
*/
/* 从epoll 监听的 红黑树中删除一个文件描述符*/
/*
void eventdel(int efd,struct myevent_s *ev)
{
    struct epoll_event epv = {0, {0}};
    if(ev->status != 1) //如果fd没有添加到监听树上，就不用删除，直接返回
        return;
    epv.data.ptr = NULL;
    ev->status = 0;
    epoll_ctl(efd, EPOLL_CTL_DEL, ev->fd, &epv);
    return;
}
*/
/*  当有文件描述符就绪, epoll返回, 调用该函数与客户端建立链接 */
/*
void acceptconn(int lfd,int events,void *arg)
{
    struct sockaddr_in cin;
    socklen_t len = sizeof(cin);
    int cfd, i;
    if((cfd = accept(lfd, (struct sockaddr *)&cin, &len)) == -1)
    {
        if(errno != EAGAIN && errno != EINTR)
        {
            sleep(1);
        }
        printf("%s:accept,%s\n",__func__, strerror(errno));
        return;
    }
    do
    {
        for(i = 0; i < MAX_EVENTS; i++) //从全局数组g_events中找一个空闲元素，类似于select中找值为-1的元素
        {
            if(g_events[i].status ==0)
                break;
        }
        if(i == MAX_EVENTS) // 超出连接数上限
        {
            printf("%s: max connect limit[%d]\n", __func__, MAX_EVENTS);
            break;
        }
        int flag = 0;
        if((flag = fcntl(cfd, F_SETFL, O_NONBLOCK)) < 0) //将cfd也设置为非阻塞
        {
            printf("%s: fcntl nonblocking failed, %s\n", __func__, strerror(errno));
            break;
        }
        eventset(&g_events[i], cfd, recvdata, &g_events[i]); //找到合适的节点之后，将其添加到监听树中，并监听读事件
        eventadd(g_efd, EPOLLIN, &g_events[i]);
    }while(0);

    printf("new connect[%s:%d],[time:%ld],pos[%d]",inet_ntoa(cin.sin_addr), ntohs(cin.sin_port), g_events[i].last_active, i);
    return;
}
*/
/*读取客户端发过来的数据的函数*/
/*
void recvdata(int fd, int events, void *arg)
{
    struct myevent_s *ev = (struct myevent_s *)arg;
    int len;

    len = recv(fd, ev->buf, sizeof(ev->buf), 0);    //读取客户端发过来的数据

    eventdel(g_efd, ev);                            //将该节点从红黑树上摘除

    if (len > 0) 
    {
        ev->len = len;
        ev->buf[len] = '\0';                        //手动添加字符串结束标记
        printf("C[%d]:%s\n", fd, ev->buf);                  

        eventset(ev, fd, senddata, ev);             //设置该fd对应的回调函数为senddata    
        eventadd(g_efd, EPOLLOUT, ev);              //将fd加入红黑树g_efd中,监听其写事件    

    } 
    else if (len == 0) 
    {
        close(ev->fd);
        /* ev-g_events 地址相减得到偏移元素位置 */
        /*
        printf("[fd=%d] pos[%ld], closed\n", fd, ev-g_events);
    } 
    else 
    {
        close(ev->fd);
        printf("recv[fd=%d] error[%d]:%s\n", fd, errno, strerror(errno));
    }   
    return;
}
*/
/*发送给客户端数据*/
/*
void senddata(int fd, int events, void *arg)
{
    struct myevent_s *ev = (struct myevent_s *)arg;
    int len;

    len = send(fd, ev->buf, ev->len, 0);    //直接将数据回射给客户端

    eventdel(g_efd, ev);                    //从红黑树g_efd中移除

    if (len > 0) 
    {
        printf("send[fd=%d], [%d]%s\n", fd, len, ev->buf);
        eventset(ev, fd, recvdata, ev);     //将该fd的回调函数改为recvdata
        eventadd(g_efd, EPOLLIN, ev);       //重新添加到红黑树上，设为监听读事件
    }
    else 
    {
        close(ev->fd);                      //关闭链接
        printf("send[fd=%d] error %s\n", fd, strerror(errno));
    }
    return ;
}

/*创建 socket, 初始化lfd */
/*
void initlistensocket(int efd, short port)
{
    struct sockaddr_in sin;

    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    fcntl(lfd, F_SETFL, O_NONBLOCK);                //将socket设为非阻塞

    memset(&sin, 0, sizeof(sin));               //bzero(&sin, sizeof(sin))
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);

    bind(lfd, (struct sockaddr *)&sin, sizeof(sin));

    listen(lfd, 20);

    /* void eventset(struct myevent_s *ev, int fd, void (*call_back)(int, int, void *), void *arg);  */
   /* eventset(&g_events[MAX_EVENTS], lfd, acceptconn, &g_events[MAX_EVENTS]);    

    /* void eventadd(int efd, int events, struct myevent_s *ev) */
  //  eventadd(efd, EPOLLIN, &g_events[MAX_EVENTS]);  //将lfd添加到监听树上，监听读事件

   /* return;
}

int main()
{
    int port=SERV_PORT;

    g_efd = epoll_create(MAX_EVENTS + 1); //创建红黑树,返回给全局 g_efd
    if(g_efd <= 0)
            printf("create efd in %s err %s\n", __func__, strerror(errno));
    
    initlistensocket(g_efd, port); //初始化监听socket
    
    struct epoll_event events[MAX_EVENTS + 1];  //定义这个结构体数组，用来接收epoll_wait传出的满足监听事件的fd结构体
    printf("server running:port[%d]\n", port);

    int checkpos = 0;
    int i;
    while(1)
    {
    /*    long now = time(NULL);
        for(i=0; i < 100; i++, checkpos++)
        {
            if(checkpos == MAX_EVENTS);
                checkpos = 0;
            if(g_events[checkpos].status != 1)
                continue;
            long duration = now -g_events[checkpos].last_active;
            if(duration >= 60)
            {
                close(g_events[checkpos].fd);
                printf("[fd=%d] timeout\n", g_events[checkpos].fd);
                eventdel(g_efd, &g_events[checkpos]);
            }
        } */
        //调用eppoll_wait等待接入的客户端事件,epoll_wait传出的是满足监听条件的那些fd的struct epoll_event类型
       /* int nfd = epoll_wait(g_efd, events, MAX_EVENTS+1, 1000);
        if (nfd < 0)
        {
            printf("epoll_wait error, exit\n");
            exit(-1);
        }
        for(i = 0; i < nfd; i++)
        {
		    //evtAdd()函数中，添加到监听树中监听事件的时候将myevents_t结构体类型给了ptr指针
            //这里epoll_wait返回的时候，同样会返回对应fd的myevents_t类型的指针
            struct myevent_s *ev = (struct myevent_s *)events[i].data.ptr;
            //如果监听的是读事件，并返回的是读事件
            if((events[i].events & EPOLLIN) &&(ev->events & EPOLLIN))
            {
                ev->call_back(ev->fd, events[i].events, ev->arg);
            }
            //如果监听的是写事件，并返回的是写事件
            if((events[i].events & EPOLLOUT) && (ev->events & EPOLLOUT))
            {
                ev->call_back(ev->fd, events[i].events, ev->arg);
            }
        }
    }
    return 0;
}
*/

/*
#include <sys/types.h>                                                   
#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#include <sys/epoll.h>
#include <termios.h>
#include<time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
int main(int argc, char **argv)
{
    //char buf[1024];
    //scanf("%[0-9]",buf);
    //printf("%s\n",buf);
    //int b;
    //scanf("%d",&b);
    //printf("%d",b);

    char buf[50];
    scanf("%s",buf);
    printf("%s\n",buf);
    return 0;
} 

*/
/*
#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"  
#include"stdlib.h"   
#include"string.h" 
#define maxsize 1024
typedef struct
{
    float data[maxsize];
    int top;
}Stack1;
void Initstack1(Stack1 *S)
{
    S = (Stack1*)malloc(sizeof(Stack1));
    S->top = -1;
}
int Push1(Stack1 *S, float ch)
{
    if (S->top == maxsize - 1)
        return 0;
    else
    {
        S->top++;
        S->data[S->top] = ch;
        return 1;
    }
}//入栈Push
int Pop1(Stack1 *S, float ch)
{
    if (S->top == -1)
        printf("栈上溢出!\n");
    else
        ch = S->data[S->top];
    S->top--;
    return 1;
}//出栈
typedef struct
{
    char data[maxsize];
    int top;
}Stack2;
void Initstack2(Stack2 *S)
{
    S = (Stack2*)malloc(sizeof(Stack2));
    S->top = -1;
}
int Push2(Stack2 *S, char ch)
{
    if (S->top == maxsize - 1)
        return 0;
    else
    {
        S->top++;
        S->data[S->top] = ch;
        return 1;
    }
}//入栈Push
int Pop2(Stack2 *S, char ch)
{
    if (S->top == -1)
        printf("栈上溢出!\n");
    else
        ch = S->data[S->top];
    S->top--;
    return 1;
}//出栈
int Comop(char ch) //判断是否是运算符
{
    switch (ch)
    {
    case'+':
    case'-':
    case'*':
    case'/':
    case'(':
    case')':
    case'#':
        return 1;
    default:
        return 0;
    }
}//判断ch是否为运算符
char Prior[7][7] =
{ // 运算符优先级表   
          // '+' '-'   '*'  '/'  '('  ')'  '#'    
   ///*'+'/*{ '>', '>', '<', '<', '<', '>', '>' },*/
    ///*'-'*/{ '>', '>', '<', '<', '<', '>', '>' },
    ///*'*'*/{ '>', '>', '>', '>', '<', '>', '>' },
    ///*'/'*/{ '>', '>', '>', '>', '<', '>', '>' },
    ///*'('*/{ '<', '<', '<', '<', '<', '=', '<'},
    ///*')'*/{ '>', '>', '>', '>', ' ', '>', '>' },
    ///*'#'*/{ '<', '<', '<', '<', '<', '>', '=' }
//};
/*
int Opid(char op1)
{
    switch (op1)
    {
    case'+':return 0;
    case'-':return 1;
    case'*':return 2;
    case'/':return 3;
    case'(':return 4;
    case')':return 5;
    case'#':return 6;
    default:return -123456;
    }
}
char Precede(char op1, char op2)  //优先级比较
{
    int a, b;
    a = Opid(op1); b = Opid(op2);
    return(Prior[a][b]);
}
float Operation(float a, char op, float b)
{
    switch (op)
    {
    case '+':
        return b + a;
    case '-':
        return b - a;
    case '*':
        return b * a;
    case '/':
        return b / a;
    default:
        return -123456;
    }
}
void CreateExpression(char *exp)
{

    if (exp == NULL)
    {
        exit(1);
    }
    scanf("%s", exp);
}
void TransmitExpression(char *exp, char postexp[]) //中缀表达式转换后缀表达式
{
    Stack2 FZ;
    Initstack2(&FZ);
    int i = 0;
    char x;
    FZ.top = -1;
    Push2(&FZ, '#');
    FZ.data[FZ.top] = '#';
    while (*exp != '\0')
    {
        if (!Comop(*exp))
        {
            while (*exp >= '0'&&*exp <= '9')//读取一个数字串
            {
                postexp[i++] = *exp;
                exp++;
            }
            postexp[i++] = '#';
        }
        else
            switch (Precede(FZ.data[FZ.top], *exp))
        {
            case'<':
                Push2(&FZ, *exp);
                exp++;
                break;
            case'=':
                x = FZ.data[FZ.top];
                Pop2(&FZ, x);
                exp++;
                break;
            case'>':
                postexp[i++] = FZ.data[FZ.top];
                x = FZ.data[FZ.top];
                Pop2(&FZ, x);
                break;
        }
    }
    while (FZ.data[FZ.top] != '#')
    {
        postexp[i++] = FZ.data[FZ.top];
        x = FZ.data[FZ.top];
        Pop2(&FZ, x);
    }
    postexp[i] = '\0';
}
float EvaluateExpression(char *postexp) //后缀表达式的计算
{
    Stack1 SZ;
    Initstack1(&SZ);
    float a, b, d;
    SZ.top = -1;
    while (*postexp != '\0')
    {
        switch (*postexp)
        {
        case'+':
        case'-':
        case'*':
        case'/':
            a = SZ.data[SZ.top];
            Pop1(&SZ, a);
            b = SZ.data[SZ.top];
            Pop1(&SZ, b);
            Push1(&SZ, Operation(a, *postexp, b));
            break;
        default:
            d = 0;
            while (*postexp >= '0'&&*postexp <= '9')
            {
                d = 10 * d + *postexp - '0';
                postexp++;
            }
            Push1(&SZ, d);
            SZ.data[SZ.top] = d;

            break;
        }
        postexp++;
    }
    return(SZ.data[SZ.top]);
}
int Error(char *exp) //错误表达式判断
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (
            ((exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') && (exp[i + 1] == ')'))
            || ((exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') && (exp[i - 1] == '('))
            || (exp[i] == ')'&&exp[i + 1] == '(')
            || (exp[i] == '('&&exp[i + 1] == ')')
            || ((exp[i] == ')') && exp[i + 1] >= '0'&&exp[i + 1] <= '9')
            || (exp[i] >= '0'&&exp[i] <= '9'&&exp[i + 1] == '(')
            || (exp[0] == '+' || exp[0] == '-' || exp[0] == '*' || exp[0] == '/' || exp[0] == ')')
            || ((exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') && (exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' || exp[i + 1] == '/'))
            || (exp[i] == '/'&&exp[i + 1] == '0')
            )
            return 1;
        else
        if (exp[i] == '\0')
            return 0;
        i++;
    }
    return 0;
}
void menu()
{
    printf("\t\t--------------------------------------------\n");
    printf("\t\t|                  计算器                  |\n");
    printf("\t\t|              ----------------            |\n");
    printf("\t\t|              |              |            |\n");
    printf("\t\t|              ----------------            |\n");
    printf("\t\t|              1    2    3   +             |\n");
    printf("\t\t|              4    5    6   -             |\n");
    printf("\t\t|              7    8    9   *             |\n");
    printf("\t\t|              0   （    ）  /             |\n");
    printf("\t\t--------------------------------------------\n");
    printf("\t\t 请输入你要进行的操作：\n");
    printf("\t\t a表达式求值 b清空 c退出\n");
}
void clear()
{
    system("cls");
    menu();
}
void Quit()
{
    system("cls");
    exit(1);
}
int main()
{
    char c;
    char exp[maxsize];
    char postexp[maxsize] = { 0 };
    menu();
    while (1)
    {
        scanf("%c", &c);
        switch (c)
        {
        case 'a':
        sr :
            printf("请输入要计算的表达式:\n");
           CreateExpression(exp);
           if (!Error(exp))
           {
               TransmitExpression(exp, postexp);
               printf("后缀表达式为：%s\n", postexp);
               printf("表达式结果为：%s=", exp);
               printf("%g\n", EvaluateExpression(postexp));
               break;
           }
           else
           if (Error(exp))
           {
               printf("您输入的表达式有误！\n");
               goto sr;//goto语句在循环体里进行跳转
           }
        case'b':
            clear();
            break;
        case'c':
            Quit();
            break;
        }
    }
    system("pause");
}*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student {
	char name[50];
	int age;
	char sex[10];
	char tel[20];
};
struct Node{
	//int data;
	struct student data;
	struct Node *next;
};
struct Node* createlist()
{
	struct Node *head = (struct Node*)malloc(sizeof(struct Node));
	head->next = NULL;
	return head;
}
struct Node* list ;

struct Node* createNode(struct student  data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next = NULL;
	return newNode;
}
//打印链表
void printlist(struct Node *head)
{
	struct Node *p = head->next;
	if (p == NULL)
		return;
	while (p!=NULL)
	{
		//涉及到数据的处理也要修改
		printf("\t姓名\t年龄\t性别\t电话\n");
		printf("%s\t%d\t%s\t%s->\n",p->data.name,p->data.age,p->data.sex,p->data.tel);
		p = p->next;
	}
}
//插入结点
void insertlist(struct Node* head, struct student  data)
{
	struct Node* newNode=createNode(data);
	newNode->data = data;
	//头插法
	newNode->next = head->next;
	head->next = newNode;
}
//删除结点
void dellist(struct Node* head, char* name)
{
	struct Node* prev = head;
	struct Node* pcurrent = prev->next;
	if (pcurrent == NULL)
	{
		printf("链表为空，无法删除！！！\n");
		return;
	}
	//姓名是字符串无法直接比较
	while (strcmp(pcurrent->data.name, name))
	{
		prev = pcurrent;
		pcurrent = pcurrent->next;
		if (pcurrent->next == NULL)
		{
			printf("未找到指定数据！\n");
			return;
		}
	}
	prev->next= pcurrent->next;
	free(pcurrent);
}
//查找功能
struct Node* findlist(struct Node* head, char* name)
{
	struct Node* pmove = head->next;
	if (pmove->next== NULL)
		return NULL;
	while (strcmp(pmove->data.name,name))
	{
		pmove = pmove->next;
	}
	return pmove;
}
//数据的设计------->学生信息的抽象出来
void menu()
{
	//所有操作都同步到文件？？？？
	printf("--------------【学生信息管理系统】--------------\n");
	printf("\t\t0.退出系统\n");
	printf("\t\t1.录入信息\n");
	printf("\t\t2.浏览信息\n");
	printf("\t\t3.修改信息\n");
	printf("\t\t4.删除信息\n");
	printf("\t\t5.查找信息\n");
	printf("-----------------------------------------------\n");
}

void keyDown()
{
	int choice = 0;
	struct student data;
	scanf("%d", &choice);
	switch (choice)
	{
		case 0:
			printf("正常退出!\n");
			exit(0);//正常运行程序并退出程序
			break;
		case 1:
			printf("---------------------【录入信息】-----------------------\n");
			//插入链表
			printf("请输入学生姓名，年龄，性别，电话：");
			fflush(stdin);         //清空缓冲区
			scanf("%s%d%s%s", data.name, &data.age, data.sex, data.tel);
			insertlist(list, data);
			break;
		case 2:
			printf("---------------------【浏览信息】-----------------------\n");
			printlist(list);//打印链表
			break;
		case 3:
			printf("---------------------【修改信息】-----------------------\n");
			break;
		case 4:
			printf("---------------------【删除信息】-----------------------\n");
			break;
		case 5:
			printf("---------------------【查找信息】-----------------------\n");
			break;
		default:
			printf("选择错误，重新输入\n");
			break;
	}
}
int main()
{
    list=createlist();
	while (1)
	{
		menu();
		keyDown();
		system("pause");
		system("cls");
	}
	//测试链表代码
	/*struct Node* list = createlist();
	insertlist(list, 1);
	insertlist(list, 2);
	insertlist(list, 3);
	insertlist(list, 4);
	insertlist(list, 5);
	printlist(list);
	printf("--------------------------------------\n");
	dellist(list, 4);
	printlist(list);
	printf("--------------------------------------\n");
	printf("链表的查找：\n");
	printf("%d", findlist(list, 3)->data);*/
	system("pause");
	return 0;
}
