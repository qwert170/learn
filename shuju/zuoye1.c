/*57页8
#include<stdlib.h>
#include<stdio.h>
typedef struct linklist{
    int data;
    struct linklist *next;
}Node;
void create(Node **p);
int main()
{
    Node *la,*lb,*p,*q,*t;
    create(&la);
    create(&lb);

    int i,j,len;
    int k=1;
    p=la;
    q=lb;
    t=la;
    printf("输入i,j,len\n");
    scanf("%d%d%d",&i,&j,&len);
    while(k<i)
    {
        p=p->next;
        k++;
    }
    k=1;
    while(k<len+i-1)
    {
        t=t->next;
        k++;
    }
    k=1;
    while(k<j)
    {
        q=q->next;
        k++;
    }
    t->next=q->next;
    q->next=p;
    p=lb;
    printf("lb:");
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void create(Node **p){
    int number;
    Node *s,*k;
    
    scanf("%d",&number);
    if(number==0) return;
    (*p)=(Node *)malloc(sizeof(Node));
    (*p)->data=number;
    s=*p;
    while(1){
        scanf("%d",&number);
        if(number==0)   break;
        Node *t=(Node *)malloc(sizeof(Node));
        t->data=number;
        s->next=t;
        s=s->next;
    }
    s->next=NULL;

    s=*p;
    while(s){
        printf("%d ",s->data);
        s=s->next;
    }
    printf("\n");
}
*/
//57页9
#include<stdio.h>
#include<stdlib.h>
typedef struct linklist{
    int data;
    struct linklist *next;
}Node;

void create(Node **p);
int cnt(Node *head);
void hebin(Node *p,Node *q,int a,int b);
Node *head3;
int main()
{
    Node *head1,*head2;
    head1=(Node *)malloc(sizeof(Node));
    head1->next=NULL;
    head2=(Node *)malloc(sizeof(Node));
    head2->next=NULL;
    head3=(Node *)malloc(sizeof(Node));
    head3->next=NULL;
    create(&head1);
    create(&head2);
  
    int a;
    a=cnt(head1);
    int b;
    b=cnt(head2);
    
    hebin(head1,head2,a,b);
}

int cnt(Node *head)
{
    int cnt=0;
    Node *p;
    p=head->next;
    
    while(p){
        cnt++;
        p=p->next;
    }
    
    return cnt;
}

void hebin(Node *p,Node *q,int a,int b)
{
    Node *w,*t,*r;
    w=p->next;
    t=q->next;
    r=head3;

    if(a>b)
    {
        while(t)
        {
            r->next=t;
            t=t->next;
            r=r->next;
            r->next=w;
            w=w->next;
            r=r->next;
        }

        while(w)
        {
            r->next=w;
            w=w->next;
            r=r->next;
        }
    }else
    {
        while(w)
        {
            r->next=w;
            w=w->next;
            r=r->next;
            r->next=t;
            t=t->next;
            r=r->next;
        }
        while(t)
        {
            r->next=t;
            t=t->next;
            r=r->next;
        }
    }
    r->next=NULL;
    r=head3->next;
    while(r)
    {
        printf("%d ",r->data);
        r=r->next;
    }
    printf("\n");
}

void create(Node **p){
    int number;
    Node *s;
    s=*p;
    while(1){
        scanf("%d",&number);
        if(number==0)   break;
        Node *t=(Node *)malloc(sizeof(Node));
        t->data=number;
        s->next=t;
        s=t;
    }
    s->next=NULL;

    s=(*p)->next;
    while(s){
        printf("%d ",s->data);
        s=s->next;
    }
    printf("\n");
}

