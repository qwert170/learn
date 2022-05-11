#include "SDL2/SDL.h"
#include <stdio.h
#include<stdlib.h>   
#include<string.h> 

#define maxsize 50
typedef struct {
    int data[maxsize];
    int top;
}stackshuju;

typedef struct{
    char symbol[maxsize];
    int top;
}stackhuhao;

void init_data(stackshuju *p){//数据栈初始化
    p->top=-1;
}

void init_symbol(stackhuhao *p)//符号栈初始化
{
    p->top=-1;
}

void push_data(stackshuju *s,int num)//数据入栈
{
    s->top++;
    s->data[s->top]=num;
}

void push_symbol(stackhuhao *s,char symbol)//符号入栈
{
    s->top++;
    s->symbol[s->top]=symbol;
}

int gettop_shuju(stackshuju  *s)
{
    return s->data[s->top];
}

char gettop_fuhao(stackhuhao *s)
{
    return s->symbol[s->top];
}

int pop_shuju(stackshuju *s)
{
    int x;
    x=s->data[s->top];
    s->top--;
    return x;
}

char pop_fuhao(stackhuhao *s)
{
    char ch;
    ch=s->symbol[s->top];
    s->top--;
    return ch;
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
    printf("\t\t a表达式求值  b退出\n");
}

int first(char x)
{
    switch (x)
    {
        case'+':return 0;
        case'-':return 1;
        case'*':return 2;
        case'/':return 3;
        case'(':return 4;
        case')':return 5;
        default:return -1;
    }
}

double transmit()
{
    char ch;
    char *str=(char *)malloc(sizeof(char)*50);
    char data[50]={0};
    printf("输入表达式：\n");
    while((ch=getchar())!='\n')
    {

    }
}

int  mian()
{
    char choice;
    double result;
    while(1)
    {
        menu();
        scanf("%c",&choice);
        switch(choice)
        {
            case 'a':
                
                result=transmit();
                printf("计算结果是：%d\n",result);
                break;
            case 'b':
                system("cls");
                return 0;
        }
    }
}
