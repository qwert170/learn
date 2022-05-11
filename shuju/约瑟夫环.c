#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int id;
    int password;
    struct Node *next;
}list, *plist;

plist create(int n)
{
    plist head, r, p; 
    head = (plist)malloc(sizeof(list));
    head->next = NULL;
    r = head;
    for (int i = 1; i <= n; i++) {
        p = (plist)malloc(sizeof(list));
        p->password = rand()%10;
        printf("第%d位密码：%d\n", i, p->password);
        // scanf("%d", &p->password);
        p->id = i;
        r->next = p;
        r = p;
    }
    r->next = head->next;
    free(head);
    return p;
}

plist get(plist head, int k)
{
    plist p = head->next;
    int j = 0;
    while (p->next != NULL && j < k) {
        p = p->next;
        j++;
    }
    if (j == k) return p;
    else return NULL; 
}

void delete_p(plist p)
{
    plist s, prep;
    prep = p;
    p = p->next;
    int n;
    int password = p->password;
    
    while (p->next != p) {
        n = 1;
        while (n != password) {
            prep = p;
            p = p->next;
            n++;
        }
        s = p;
        prep->next = p->next;
        printf("出局：%d", p->id);
        printf(" 新密码：%d\n", p->password);
        password = p->password;
        p = p->next;
        free(s);
    }
    printf("最终出局：%d\n", p->id);
    free(p);
}

int main()
{
    int n, m;
    plist p = NULL;
    printf("人数：");
    scanf("%d", &n);
    p = create(n);
    m = 1 + rand()%(n-1);
    printf("从第%d位开始报数\n", m);
    plist l = get(p, m);
    delete_p(l);

    return 0;
}