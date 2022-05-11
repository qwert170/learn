/*邻接矩阵
#include<iostream>
#include<stack>

using namespace std;
const int MAX=10;

template<class vertex,class edge>
struct Graph
{
public:
    Graph();
    //~Graph();
    int locate(vertex ch);
    void print();
    void DFS();
private:
    int arc;//边
    int ver;//点
    vertex v[MAX];
    edge m[MAX][MAX];
};

template<class vertex,class edge>
Graph<vertex,edge>::Graph()
{
    cout<<"输入顶点数和边数：";
    cin>>this->ver>>this->arc;

    cout<<"输入顶点信息：";
    for(int i=0;i<this->ver;i++)
    {
        cin>>this->v[i];
    }

    for(int i=0;i<this->ver;i++)
    {
        for(int j=0;j<this->ver;j++)
        {
            this->m[i][j]=0;
        }
    }

    cout<<"输入两个顶点和权值：";
    for(int i=0;i<this->arc;i++)
    {
        vertex a,b;
        edge c;
        cin>>a>>b>>c;
        int x=this->locate(a);
        int y=this->locate(b);

        this->m[x][y]=c;
        this->m[y][x]=c;
    }
}

template<class vertex,class edge>
int Graph<vertex,edge>::locate(vertex ch)
{
    for(int i=0;i<this->ver;i++)
    {
        if(this->v[i]==ch)
        {
            return i;
        }
    }
    return -1;
}


template<class vertex,class edge>
void Graph< vertex, edge>::print()
{
    int i,j;
    for( i=0;i<this->ver;i++)
    {
        for(j=0;j<this->ver;j++)
        {
            cout<<this->m[i][j]<<" ";
        }
        cout<<endl;
    }
}

template<class vertex,class edge>
void Graph<vertex,edge>::DFS()
{
    stack<vertex> s;
    int visited[MAX]={0};
    vertex ch=this->v[0];
    s.push(ch);
    vertex t;
    while(!s.empty())
    {
        t=s.top();
        s.pop();
        int k=locate(t);
        if(!visited[k])
        {
            cout<<t<<" ";
            visited[k]=1;
        }
        
        for(int i=0;i<this->ver;i++)
        {
            if(this->m[k][i]!=0&&!visited[i])
            {
                s.push(this->v[i]);
            }
        }
    }
}

int main()
{
    Graph<char,int> g;
    g.print();
    g.DFS();
    return 0;
}
*/

/*邻接表*/

#include <iostream>
#include<queue>
using namespace std;
 
#define MAXVERTEX 100   //最大顶点数
typedef char vertextype;    //定义顶点的存储类型
typedef int arctype;    //定义边的权值类型
 
typedef struct ArcNode  //边表节点
{
    int adjvex; //邻接点域，存储该顶点对应的下标
    int wigth;  //用于存储权值
    struct ArcNode *next; //链域，指向下一个邻接点
}ArcNode;
 
typedef struct VertexNode   //顶点表节点
{
    char data;    //存储顶点数据的信息
    ArcNode *firstarc;  //边表头指针
}VertexNode, AdjList[MAXVERTEX];
 
typedef struct
{
    AdjList adjlist;    //定义邻接表
    int numvertex;  //当前邻接表的顶点数
    int numarc; //当前邻接表的边数
}GraphAdjList;

int visited[MAXVERTEX];

int locate(char ch,GraphAdjList &G)
{
    for(int i=0;i<G.numarc;i++)
    {
        if( G.adjlist[i].data==ch)
        {
            return i;
        }
    }
    return -1;
}

//建立图的邻接表
void CreateAdjListGraph(GraphAdjList &G)
{
    ArcNode *e;
    cin >> G.numvertex; //输入当前图的顶点数
    cin >> G.numarc;    //输入当前图的边数
    for(int i = 0; i < G.numvertex; i++)    //建立顶点表
    {
        cin >> G.adjlist[i].data;   //输入顶点信息
        G.adjlist[i].firstarc = NULL;   //将表边指针置为空
    }
    for(int k = 0; k < G.numarc; k++)
    {
        char a,b;
        int i, j, w;
        cin >> a >> b >> w; //输入边两边的顶点和边上的权重
        i=locate(a,G);
        j=locate(b,G);
        e = new ArcNode;   //创建一个表边节点指针
        e->adjvex = j;
        e->wigth = w;

        e->next = G.adjlist[i].firstarc;
        G.adjlist[i].firstarc = e;
        
        //因为是无向图，彼此相对称
        e = new ArcNode;   //创建一个表边节点指针
        e->adjvex = i;
        e->wigth = w;
        e->next = G.adjlist[j].firstarc;
        G.adjlist[j].firstarc = e;
    }
}
 
//打印邻接表
void PrintfGraphAdjList(GraphAdjList G)
{
    for(int i = 0; i < G.numvertex; i++)
    {
        ArcNode *p = G.adjlist[i].firstarc;
        cout << G.adjlist[i].data << '\t';
        while(p)
        {
            cout << "下标："<<p->adjvex << ' ' <<"权值"<< p->wigth << '\t';
            p = p->next;
        }
        cout << endl;
    }
}

void BFS(GraphAdjList G,int i)
{
    cout<<G.adjlist[i].data<<" ";
    visited[i]=1;
    queue<int> q;
    q.push(i);
    int t;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        ArcNode *p;
        p = G.adjlist[i].firstarc;	
        while(p)
        {
			if (!visited[p->adjvex])	//如果顶点未访问就处理
			{
				visited[p->adjvex] = 1;
				cout << G.adjlist[p->adjvex].data << " ";
				q.push(p->adjvex);
			}
			p = p->next;
        }
    }

    
}

void TraverseG(GraphAdjList G)
{
    int i;
    
    for(i=0;i<G.numvertex;i++) visited[i]=0;
    for(i=0;i<G.numvertex;i++)
    {
        if(!visited[i]) BFS(G,i);
    }
}

int main()
{
    GraphAdjList G;
    CreateAdjListGraph(G);
    PrintfGraphAdjList(G);
    TraverseG(G);
    return 0;
}
