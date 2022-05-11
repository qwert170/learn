#include<iostream>
#include<string>
#include<fstream>
#include<memory.h>
#include<algorithm>
#include<vector>

using namespace std;
const int MAX=100;
const int inf=32665;

struct Node{
public:
    Node(int in,int we,Node * n):index(in),weight(we),next(n){}
    int index;
    int weight;
    Node *next;
};

struct TopNode{
    string name;//地点名称
    Node *first;
};

struct Graph{
public:
    Graph();
    int locate(string s);
    void shortest();
    void print_path(int i,int j);
    void print_result();
    void perfect();
    void make_map();
    bool isVisited(bool visited[]);
    void getPath();
    void printPath();
private:
    TopNode map[MAX];
    int mkmap[MAX][MAX];
    int path[MAX][MAX];//中转站点
    int dis[MAX][MAX];//最短距离
    int numarc;//边数
    int numvertex;//点数
    int dp[MAX][MAX];
    vector<int> p;
};


int Graph::locate(string s)
{
    for(int i=0;i<this->numvertex;i++)
    {
        if(s==this->map[i].name) return i;
    }
    return -1;
}

void Graph::make_map()
{
    //初始化
    for(int i=0;i<this->numvertex;i++)
    {
        for(int j=0;j<this->numvertex;j++)
        {
            if(i==j) this->mkmap[i][j]=0;
            else this->mkmap[i][j]=inf;
        }
    }

    Node *p;
    for(int i=0;i<this->numvertex;i++)
    {
        p=this->map[i].first;
        while(p)
        {
            int j=p->index;
            mkmap[i][j]=p->weight;
            p=p->next;
        }
    }

    for(int i=0;i<this->numvertex;i++)
    {
        for(int j=0;j<this->numvertex;j++)
        {
            cout<<mkmap[i][j]<<" ";
        }
        cout<<endl;
    }
}

Graph::Graph()
{
    fstream f;
	f.open("/home/zxp/learngit/shuju/gongyuan/mappoint",ios::out);//写入

    cout<<"输入景点数和边数:";
    cin>>this->numvertex>>this->numarc;

    cout<<"输入景点信息：";
    for(int i=0;i<this->numvertex;i++)
    {
        cin>>this->map[i].name;
        f<<this->map[i].name<<endl;
        this->map[i].first=nullptr;
    }

    cout<<"输入两两景点以及之间的路径：";
    for(int i=0;i<this->numarc;i++)
    {
        string a,b;
        int w;
        cin>>a>>b>>w;
        f<<a<<" "<<b<<" "<<w<<endl;
        int p,q;
        p=locate(a);
        q=locate(b);
        if(p!=-1&&q!=-1)
        {
            Node *t=new Node(p,w,map[q].first);
            Node *o=new Node(q,w,map[p].first);

            map[p].first=o;
            map[q].first=t;
           
        }else{
            cout<<"输入地点错误，请重新输入！"<<endl;
            continue;
        }
    }
    f.close();
    
    this->shortest();
    this->make_map();
}

void Graph::print_result()
{
    string a,b;
    cout<<"输入要寻找的两个景点的最短路径（输入景点名称）：";
    cin>>a>>b;
    int i=locate(a);
    int j=locate(b);
    if(this->dis[i][j]==inf){
        cout<<a<<"和"<<b<<"之间没有路径。"<<endl;
    }else{
        cout<<a<<"和"<<b<<"的最短路径为："<<this->dis[i][j]<<endl;
        cout<<a<<"->";
        print_path(i,j);
        cout<<b<<endl;
    }
}

void Graph::print_path(int i,int j)
{
   
    int k=this->path[i][j];
    if(k==-1) return;
    print_path(i,k);
    cout<<this->map[k].name<<"->";
    print_path(k,j); 
}

void Graph::shortest()
{
    int i,j;
    for(i=0;i<this->numvertex;i++)
    {
        for(j=0;j<this->numvertex;j++)
        {
            if(i==j) this->dis[i][j]=0;
            else this->dis[i][j]=inf;
        }
    }

    memset(this->path,-1,sizeof(path));

    Node *p;

    for(i=0;i<this->numvertex;i++)
    {
        p=this->map[i].first;
        while(p)
        {
            this->dis[i][p->index]=p->weight;
            this->dis[p->index][i]=p->weight;
            p=p->next;
        }
    }

    int k;
    for(i=0;i<this->numvertex;i++)
    {
        for(j=0;j<this->numvertex;j++)
        {
            for(k=0;k<this->numvertex;k++)
            {
                if(this->dis[i][j]>this->dis[i][k]+this->dis[k][j])
                {
                    this->path[i][j]=k;
                    this->dis[i][j]=this->dis[i][k]+this->dis[k][j];
                }
            }
        }
    }
}

void Graph::perfect()
{
     for(int i = 0 ; i < numvertex ;i++){
        dp[i][0] = mkmap[i][0];
    }
    int n=1<<(numvertex-1);
    //求解dp[i][j],先跟新列在更新行
    for(int j = 1 ; j < n ;j++){
        for(int i = 0 ; i < numvertex ;i++ ){
            dp[i][j] = inf;
            //如果集和j(或状态j)中包含结点i,则不符合条件退出
            if( ((j >> (i-1)) & 1) == 1){
                continue;
            }
            for(int k = 1 ; k < numvertex; k++){
                if( ((j >> (k-1)) & 1) == 0){
                    continue;
                }
                if( dp[i][j] > mkmap[i][k] + dp[k][j^(1<<(k-1))]){
                    dp[i][j] = mkmap[i][k] + dp[k][j^(1<<(k-1))];
                }
            }
        }
    }
    for(int j = 1 ; j < n ;j++){
        for(int i = 0 ; i < numvertex ;i++ ){
        cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool Graph::isVisited(bool visited[]){
    for(int i = 1 ; i<this->numvertex ;i++){
        if(visited[i] == false){
            return false;
        }
    }
    return true;
}

void Graph::getPath(){
    //标记访问数组
    bool visited[numvertex] = {false};
    //前驱节点编号
    int n=1<<(numvertex-1);
    int pioneer = 0 ,min = inf, S = n - 1,temp ;
    //把起点结点编号加入容器
    p.push_back(0);
 
    while(!isVisited(visited)){
        for(int i=1; i<numvertex;i++){
            if(visited[i] == false && (S&(1<<(i-1))) != 0){
                if(min > mkmap[i][pioneer] + dp[i][(S^(1<<(i-1)))]){
                    min = mkmap[i][pioneer] + dp[i][(S^(1<<(i-1)))] ;
                    temp = i;
                }
            }
        }
        pioneer = temp;
        p.push_back(pioneer);
        visited[pioneer] = true;
        S = S ^ (1<<(pioneer - 1));
        min = inf;
    }
}

void Graph::printPath(){
    cout<<"最小路径为：";
    vector<int>::iterator  it = p.begin();
    for(it ; it != p.end();it++){
        cout<<map[*it].name<<"--->";
    }
    //单独输出起点编号
    cout<<map[0].name<<endl;
}

int main()
{
    cout<<"**********************************************"<<endl;
    cout<<"                    导游图"<<endl;
    cout<<"**********************************************"<<endl;
    Graph G;
    while(1)
    {
        int choice;
        cout<<"**********************************************"<<endl;
        cout<<"                    导游图"<<endl;
        cout<<"                  1 -- 最短路径"<<endl;
        cout<<"                  2 -- 最佳路线"<<endl;
        cout<<"                  0 -- 退出"<<endl;
        cout<<"**********************************************"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 0:
                return 0;
            case 1:
                G.print_result();
                break;
            case 2:
                G.perfect();
                G.getPath();
                G.printPath();
                break;
        }
    }
    
}