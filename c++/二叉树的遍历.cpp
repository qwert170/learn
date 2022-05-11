#include<iostream>
#include<stack>
#include<cstdio>
#include<stack>
#include<queue>

using namespace std; 
 
class treenode{
    public:
        int data;
        treenode *left,*right;
};

class tree{
    public:
        treenode *root;
        treenode *createtree();
        void postorder(treenode *p);
        void firstorder(treenode *p);
        void levelorder(treenode *root);
};

treenode* tree::createtree()
{
    int data;
    treenode *t=new treenode;
    cout<<"输入当前节点的大小："<<endl;
    cin>>data;
    if (data<=0){
        printf("当前分支输入结束！\n");
        return NULL;
    }
    t->data=data;
    t->left=createtree();
    t->right=createtree();
    return t;
}

void tree::postorder(treenode *p)
{
    if(p)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<" ";
    }
}

void tree::firstorder(treenode *p)
{
    stack<treenode*> s;
    treenode *t;
    t=p;
    while(t!=NULL||!s.empty())
    {
        while(t)
        {
            cout<<t->data<<" ";
            s.push(t);
            t=t->left;
        }
        if(!s.empty())
        {
            t=s.top();
            s.pop();
            t=t->right;
        }
    }
    cout<<endl;
}

void tree::levelorder(treenode *root)
{
    queue<treenode*> q;
    q.push(root);
    treenode *t;
    while(!q.empty())
    {
        t=q.front();
        cout<<t->data<<" ";
        q.pop();
        if(t->left!=NULL)
        {
            q.push(t->left);
        }
        if(t->right!=NULL)
        {
            q.push(t->right);
        }
    }
    cout<<endl;
}

int main()
{
    tree t;
    t.root=t.createtree();
    t.postorder(t.root);//递归后序遍历
    cout<<endl;
    t.firstorder(t.root);//先序循环遍历
    t.levelorder(t.root);//层次遍历 
}