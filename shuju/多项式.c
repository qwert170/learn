#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct Polynomial
{
    int coef;//系数
    int expn;//指数
    struct Polynomial *next;
}*Poly, Node;
Poly Creat()                          //建立一元多项式
{
    Node *head, *rear, *s;
    int e; 
    int c;
    head = (Poly)malloc(sizeof(Node));  //头节点
    rear = head;                      //尾插法,rear始终动态指向链表的当前结尾，其初值指向头结点
    printf("请输入一个一元多项式，形如（系数c，指数e，c=0退出）\n");
    scanf("%d,%d", &c, &e);
    while (c != 0)                  //c=0则结束
    {
        s = (Poly)malloc(sizeof(Node));
        s->coef = c;
        s->expn = e;
        rear->next = s;         // 将新结点插到*rear之后, 原来的尾结点rear的next 记录新结点的地址
        rear = s;              //新结点变成当前的表尾
        scanf("%d,%d", &c, &e);
    }
    rear->next = NULL;  //将最后一个节点的next链域置为空，表示链表的结束
    return (head);
}
void show(Poly p)                 // 输出一元多项式
{
    Poly q = p->next;           //p的next节点和q的指针指向同一个地址
    int flag = 1;                  //定义一个flag=1，用于输入加号的条件
    if (!q)                     //若一元多项式为假，输出0
    {
        putchar('0');
        printf("\n");
        return;
    }
    while (q)                   //若一元多项式为真，执行while循环
    {
        if (q->coef > 0 && flag != 1)
            putchar('+');  //如果一元多项式的系数大于0并且flag已经不再是1，则输出+
        if (q->coef != 1 && q->coef != -1)  //如果一元多项式系数不是1也不是-1
        {
            printf("%d", q->coef);    //直接输出一元多项式的系数
            if (q->expn == 1)         //再看指数，如果指数是1，直接输出x
                putchar('X');
            else if (q->expn)
                printf("X^%d", q->expn);  //否则  输出X^%d
        }
        else
        {
            if (q->coef == 1)   //如果一元多项式的系数是1
            {
                if (!q->expn)   //在判断指数是否为真，若指数为0，直接输出1即可
                    putchar('1');
                else if (q->expn == 1)
                    putchar('X');   //如果再系数是1的情况下指数也是1，则直接输出x即可
                else
                    printf("X^%d", q->expn);// 系数为1，指数不为1，则输出X^%d
            }
            if (q->coef == -1)  //如果系数为-1
            {
                if (!q->expn)
                    printf("-1");   //若指数为0，则输出-1
                else if (q->expn == 1)
                    printf("-X");    //若指数为1，则输出-x
                else
                    printf("-X^%d", q->expn);
            }
        }
        q = q->next;      //使当前指针指向链表的下一个结点。
        flag++;
    }
    printf("\n");
}
Poly Add(Poly pa, Poly pb)   //多项式相加
{
    Poly qa = pa->next;       //将pa的next域赋给qa指针   
    Poly qb = pb->next;
    Poly headc, pc, temp;
    pc = (Poly)malloc(sizeof(Node));   //申请一个动态存储空间
    pc->next = NULL;
    headc = pc;
    while (qa != NULL && qb != NULL)  //  当qa，qb都存在
    {
        temp = (Poly)malloc(sizeof(Node));
        if (qa->expn < qb->expn)  //比较指数
        {
            temp->expn = qa->expn;   //将指数小的链入和多项式中
            temp->coef = qa->coef;  //同时系数也链入和多项式
            qa = qa->next;          //qa指针指向下一个结点
        }
        else if (qa->expn == qb->expn)    //指数相等
        {
            temp->expn = qa->expn;         //指数链入和多项式
            temp->coef = qa->coef + qb->coef;//系数相加再链入和多项式
            qa = qa->next;          // qa,qb分别指向下一个结点
            qb = qb->next;
        }
        else
        {
            temp->expn = qb->expn;
            temp->coef = qb->coef;
            qb = qb->next;
        }
        if(temp->coef != 0)          //若链入结束后最后一个系数不为0
        {
            temp->next = NULL;       //则使和多项式下一个结点指向空，即结束
            pc->next = temp;
            pc = temp;     //将temp中的多项式链入pc中
        }
        else
            free(temp);     //释放temp
    }
    while (qa != NULL)     //qb不存在
    { 
        temp = (Poly)malloc(sizeof(Node));
        temp->expn = qa->expn;
        temp->coef = qa->coef;
        qa = qa->next;             //直接把qa链入和多项式
        temp->next = NULL;  
        pc->next = temp;            //将temp中的多项式链入pc中
        pc = temp;
    }
    while (qb != NULL) 
    {
        temp = (Poly)malloc(sizeof(Node));
        temp->expn = qb->expn;
        temp->coef = qb->coef;
        qb = qb->next;
        temp->next = NULL;  
        pc->next = temp;
        pc = temp;
    }
    return headc;
}
Poly diff(Poly pa, Poly pb)  //多项式相减
{
    Poly qb = pb->next;
    Poly pd = NULL;
    while (qb)
    {
        qb->coef = -qb->coef;  //第二个多项式系数变为负，然后两个多项式相加即可
        qb = qb->next;
    }
    pd = Add(pa, pb);          //调用加法函数
    for (qb = pb->next; qb != NULL; qb = qb->next)  // 恢复pb中的指数
        qb->coef *= -1;
    return pd;
}
Poly Cheng(Poly pa, Poly pb)      //多项式相乘
{
    Poly qa = pa->next;            //将pa的next域赋给qa指针
    Poly qb = pb->next;            //将pb的next域赋给qb指针
    Poly head, pe, temp;            //定义三个指针
    Poly sum = NULL;  
    head = (Poly)malloc(sizeof(Node));  //申请存储空间
    head->next = NULL;
    if (qa != NULL && qb != NULL)        //qa,qb都存在
    {
        for (qa = pa->next; qa != NULL; qa = qa->next)  //for循环，以qa存在为条件
        {
            sum = (Poly)malloc(sizeof(Node));   //申请一个存储空间
            sum->next = NULL;
            pe = sum;
            for (qb = pb->next; qb != NULL; qb = qb->next)//for 循环 以qb存在为条件
            {
                temp = (Poly)malloc(sizeof(Node));   //申请一个存储空间
                temp->coef = qa->coef * qb->coef;     //执行乘法运算法则，指数相加，系数相乘
                temp->expn = qa->expn + qb->expn;
                temp->next = NULL;   
                pe->next = temp;                       //将temp中的多项式链入pe中
                pe = temp;
            }
            head = Add(head, sum);                    //调用加法函数
        }
    }
   
    return head;
}
int main()
{
    Poly qc;         //定义三个指针 qc，qd，qe
    Poly qd;
    Poly qe;
    Node *p, *q;
    printf("************************************\n");
    printf("*             欢迎使用             *\n");
    printf("************************************\n");
    p = Creat();        //调用建立一元多项式函数
    show(p);            //输出一元多项式p
    q = Creat();         //调用一元多项式函数
    show(q);            //输出一元多项式q
    
    qc = Add(p, q);     //调用加法函数
    printf("加法：");     // 输出加法两个字，提示操作者运行的为加法
    show(qc);            //显示出和多项式
 
    qd = diff(p, q);      //调用减法函数
    printf("减法：");
    show(qd);               //输出差多项式
 
    qe = Cheng(p, q);       //调用乘法函数
    printf("乘法：");
    show(qe);            //输出积多项式
    printf("***********************************\n");
    printf("*          谢谢使用               *\n");
    printf("***********************************\n");
    return 0;
}

