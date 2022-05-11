#include<iostream>
using namespace std;
#include<fstream>
#include<map>
#include<string>
#include<vector>
#include <algorithm>
#include<cstdio>
#include <bits/stdc++.h>

typedef pair<int,int> PAIR;

class treenode
{
    public:
        treenode()=default;
        int data;
        int weight;
        treenode *left,*right;
        treenode(PAIR t){
            this->data=t.first;
            this->weight=t.second;
        };
};

class tree
{
    public:
        treenode *root;
        map<int,int> t;
        vector<treenode*> k;
        void count_weight(map<int,int>&);
        treenode* create_tree(vector<treenode*> &t);
        void change( map<int,int>,vector<treenode*>& k);
        
};

bool cmp(const PAIR &i,const PAIR &j)
{
    return i.second>j.second;
}

treenode *tree::create_tree(vector<treenode*> &t)//建立二叉树
{
    treenode *root=new treenode;
    sort(t.begin(),t.end(),cmp);
    int min=t.back()->weight;
    t.pop_back();
    root->left=create_tree(t);
    root->right=create_tree(t);
    root->weight=
    
    treenode *p=new treenode;
    

    

}

void tree::count_weight(map<int,int> &t)//计算权值
{
    ifstream fin("/home/zxp/learngit/c++/soucefile.txt");
    string s;
    int sum=0;
    while(true)
    {
        getline(fin,s);
        if(!fin) break;
        sum++;
        for(int i=0;i<s.size();i++)
        {
            t[int(s[i])]++;
        }
    }
    fin.close();
    int a='\n';
    t[a]=sum;

    // for(auto i=t.begin();i!=t.end();i++)
    // {       
    //     cout<<int(i->first)<<" "<<i->second<<endl;   
    // }
    cout<<endl;
}

void tree::change(map<int,int> t,vector<treenode*> &k)
{
    for (auto i=t.begin();i!=t.end();i++)
    {
        treenode *p=new treenode;
        p->data=i->first;
        p->weight=i->second;
        k.push_back(p);
    }
}

int main()
{
    tree shu;
    //ofstream fout("codefile.txt");
    //ofstream fou("decodefile.txt");
    shu.count_weight(shu.t);
    shu.change(shu.t,shu.k);
    shu.create_tree(shu.k,shu.root);
}
