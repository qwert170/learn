//链表
//循环链表
/*
#include<stdio.h>
#include<stdlib.h>
typedef struct linklist{
    int data;
    struct linklist *next;
}Node;

void weiadd(Node *head);
void headadd(Node *head);
void sanchu(Node *head);
void sczhi(Node *head);
void xiugai(Node *head);
void chazhao(Node *head);
void czzhi(Node *head);

int main(){
    Node *head;
    Node *p;
    int number;
    head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    p=head;
    while(1){
      scanf("%d",&number);
      if(number==0)  break;
      Node *s=(Node *)malloc(sizeof(Node));
      s->data=number;

      p->next=s;
      p=s;
    }
   // p->next=NULL;
   p->next=head;
//原链表
    p=head->next;
  //while(p){
    while(p->next!=head->next){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
//尾接的数
    weiadd(head);
    p=head->next;
    //while(p){
    while(p->next!=head->next){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
//头接的数
    headadd(head);
    p=head->next;
    //while(p){
     while(p->next!=head->next){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
//删除第几个节点
    sanchu(head);
    p=head->next;
    //while(p){
     while(p->next!=head->next){    
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
//删除确定值
    sczhi(head);
    p=head->next;
    //while(p){
     while(p->next!=head->next){    
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
//修改节点信息
    xiugai(head);
    p=head->next;
    //while(p){
     while(p->next!=head->next){    
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
//查找第几个节点
    chazhao(head);
    p=head->next;
    //while(p){
    while(p->next!=head->next){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
//查找确定值
    czzhi(head);
    p=head->next;
    //while(p){
         while(p->next!=head->next){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");

    return 0;
}

//尾接
void weiadd(Node *head){
    int s;
    Node *t;
    printf("尾插的数：");
    scanf("%d",&s);
    Node *q=(Node *)malloc(sizeof(Node));
    q->data=s;
    t=head->next;
    //while(t->next){
    while(t->next->next!=head->next){
        t=t->next;
    }
    t->next=q;
    t=q;
    //t->next=NULL;
    t->next=head;
}

//头接
void headadd(Node *head){
    int s;
    printf("头插的数：");
    scanf("%d",&s);
    Node *q=(Node *)malloc(sizeof(Node));
    q->data=s;
    Node *t;
    t=head;
    q->next=head->next;
    head->next=q;
}
//删除节点
void sanchu(Node *head){
    int i,t;
    Node *q,*s;
    printf("删除第几个:");
    scanf("%d",&t);
    q=head;
    for(i=1;i<t;i++){
        q=q->next;
    }
    s=q->next;
    q->next=s->next;
    free(s);
}
//删除值
void sczhi(Node *head){
    int a;
    printf("删除值：");
    scanf("%d",&a);
    Node *q,*t;
    q=head;
    t=q->next;
    //while(t){
    while(t->next!=head->next){
        if(t->data==a){
            q->next=t->next;
            free(t);
            t=q->next;
        }
        q=q->next;
        //if(t)  t=t->next;
        //else t=NULL;
        if(t->next!=head->next) t=t->next;
        else t=head;
    }
}
//修改节点
void xiugai(Node *head){
    int i,a,b;
    printf("修改第几个节点：");
    scanf("%d",&a);
    Node *q,*t;
    q=head;
    for(i=1;i<a;i++){
        q=q->next;
    }
    t=q->next;
    printf("修改的值:");
    scanf("%d",&b);
    t->data=b;
}
//查找节点
void chazhao(Node *head){
    int i,a;
    printf("查找第几个节点：");
    scanf("%d",&a);
    Node *q,*t;
    q=head;
    for(i=1;i<a;i++){
        q=q->next;
    }
    t=q->next;
    printf("第%d个节点：\n",a);
    printf("数值为%d\n",t->data);
}
//查找值
void czzhi(Node *head){
    int i,a;
    printf("查找确定值：");
    scanf("%d",&a);
    i=1;
    Node *t,*q;
    q=head->next;
    //while(q){
    while(q->next!=head->next){
        if(q->data==a){
            printf("第%d个节点\n",i);
        }
        i++;
        q=q->next;
    }
}
*/

//双向链表
/*
#include<stdio.h>
#include<stdlib.h>
typedef struct linklist{
    struct linklist *pre;
    int data;
    struct linklist *next;
}Node;
void weijie(Node *head);
void headadd(Node *head);
void sanchu(Node *head);
void sczhi(Node *head);

int main(){
    int number;
    Node *head,*p;
    head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    head->pre=NULL;
    p=head;
    while(1){
        scanf("%d",&number);
        if(number==0) break;
        Node *q=(Node *)malloc(sizeof(Node));
        q->data=number;
        q->next=NULL;
        q->pre=NULL;
        p->next=q;
        q->pre=p;
        p=q;
    }
    p->next=NULL;

    p=head->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    //尾接
    weijie(head);
     p=head->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    //头接
    headadd(head);
    p=head->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    //删除节点
    sanchu(head);
     p=head->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    //删除值
    sczhi(head);
     p=head->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return 0;
}

//尾接
void weijie(Node *head){
    int number;
    Node *t;
    printf("尾接的数：");
    scanf("%d",&number);
    Node *s=(Node *)malloc(sizeof(Node));
    s->data=number;
    s->pre=NULL;
    s->next=NULL;
    t=head->next;
    while(t->next){
        t=t->next;
    }
    t->next=s;
    s->pre=t;
    t=s;
    t->next=NULL;
}

//头接
void headadd(Node *head){
    int s;
    printf("头插的数：");
    scanf("%d",&s);
    Node *q=(Node *)malloc(sizeof(Node));
    q->data=s;
    Node *t;
    t=head->next;
    q->next=t;
    t->pre=q;
    head->next=q;
    q->pre=head;
}

//删除节点
void sanchu(Node *head){
    int i,t;
    Node *q,*s,*u;
    printf("删除第几个:");
    scanf("%d",&t);
    q=head;
    for(i=1;i<t;i++){
        q=q->next;
    }
    s=q->next;
    u=s->next;
    q->next=u;
    u->pre=q;
    free(s);
}

//删除值
void sczhi(Node *head){
    int a;
    printf("删除值：");
    scanf("%d",&a);
    Node *q,*t;
    q=head;
    t=q->next;
    while(t){
        if(t->data==a){
            Node *e;
            e=t->next;
            q->next=t->next;
            e->pre=q;
            free(t);
            t=q->next;
        }
        q=q->next;
        if(t)  t=t->next;
        else t=NULL;
    }
}
*/