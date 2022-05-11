#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxleaf 20
#define maxnode maxleaf*2-1
#define maxval 1000
#define maxsize 100

typedef struct
{
    char ch;
    float weight;
    int lchild, rchild,parent;
}huffmantree;

typedef struct
{
    char bits[maxsize];
    int start;
    char ch;
}code_;

void huffman(huffmantree tree[], int n)
{
    int i, j, min, min1;
    float small1, small2, f;
    char c;
    int m = 2*n -1;
    for (i = 0; i < m; i++)
    {
        tree[i].parent = 0;
        tree[i].lchild = -1;
        tree[i].rchild = -1;
        tree[i].weight = 0.0;
    }
    for (i = 0; i < n; i++)
    {
        printf("第%d个元素：\n", i+1);
        printf("结点值：");
        scanf("%c", &c);
        getchar();
        printf("权重：");
        scanf("%f", &f);
        getchar();
        tree[i].ch = c;
        tree[i].weight = f;
    }
    for (i = n; i < m; i++)
    {
        min = 0;
        min1 = 0;
        small1 = maxval;
        small2 = maxval;
        for (j = 0; j < i; j++)
            if (tree[j].parent == 0)
                if (tree[j].weight < small1)
                {
                    small2 = small1;
                    small1 = tree[j].weight;
                    min1 = min;
                    min = j;
                }
                else if (tree[j].weight < small2)
                {
                    small2 = tree[j].weight;
                    min1 = j;
                }
        tree[min].parent = i;
        tree[min1].parent = i;
        tree[i].lchild = min;
        tree[i].rchild = min1;
        tree[i].weight = tree[min].weight + tree[min1].weight;
    }
}

void huffmancode(code_ code[], huffmantree tree[], int n)
{
    int i, c, p;
    code_ cd;
    for (i = 0; i < n; i++)
    {
        cd.start = n;
        cd.ch = tree[i].ch;
        c = i;
        p = tree[i].parent;
        while (p != 0)
        {
            cd.start--;
            if (tree[p].lchild == c)
            {
                cd.bits[cd.start] = '0';
            }
            else
            {
                cd.bits[cd.start] = '1';
            }
            c = p;
            p = tree[p].parent;
        }
        code[i] = cd;
    }
}

int main()
{
    int i, j, n, m;
    huffmantree tree[maxnode];
    code_ code[maxleaf];
    printf("请输入元素个数：");
    scanf("%d", &n);
    getchar(); 
    huffman(tree, n);
    huffmancode(code,tree,n);
    printf("%s","\033[1H\033[2J"); 
    for (i = 0; i < n ; i++)
    {
        printf("%c：", code[i].ch);
        printf("%d:",code[i].start);
        for (j = code[i].start; j < n; j++)
            printf("%c", code[i].bits[j]);
        printf("\n");
    }

    printf("输入要解码的字符串：\n");
    char ch[100];
    scanf("%s",ch);
    int num[100];
    
    for (i=0;i<strlen(ch);i++)
    {
        if(ch[i]=='0') num[i]=0;
        else num[i]=1;
    }

    int k=0;
    i=0;
    int t=k;
    while(k<strlen(ch)){  
        for(j = code[i].start,k=t; j < n;j++){
            if(ch[k]==code[i].bits[j])
            {
                k++;
                if(j==n-1){
                    printf("%c",code[i].ch);
                    t=k;
                    i=0;
                    break;
                }
            }else{
                i=i%n;
                i++;
                break;
            }      
        }
    }
    return 0;
}

