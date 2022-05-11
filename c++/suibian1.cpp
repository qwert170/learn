/*
#include<iostream>
#include<climits>
int main()
{
    using namespace std;
    int n_int=INT_MAX;
    short n_short=SHRT_MAX;
    long n_long=LONG_MAX;
    long long n_llong=LLONG_MAX;
    cout<<"int is "<<sizeof(int)<<" bytes."<<endl;
    cout<<"short is "<<sizeof n_short <<" bytes."<<endl;
    cout <<"long is "<<sizeof n_long<<" bytes. "<<endl;
    cout<<"long long is "<<sizeof n_llong<<" bytes."<<endl;
    cout<<endl;

    cout<<"Maximum values: "<<endl;
    cout<<"int: "<<n_int<<endl;
    cout<<"short: "<<n_short<<endl;
    cout<<"long: "<<n_long<<endl;
    cout<<"long long: "<<n_llong<<endl;

    cout<<"Minimum int value = "<<INT_MIN<<endl;
    cout<<"Bits per byte = "<<CHAR_BIT<<endl;

    return 0;
}
*/
/*
#include<iostream>
int main()
{
    using namespace std;
  //  cout.setf(ios_base::fixed,ios_base::floatfield);
    float tub=10.0/3.0;
    double mint=10.0/3.0;
    const float million=1.0e6;

    cout<<"tub = "<<tub;
    cout<<" ,a million tubs = "<<million*tub;
    cout<<",\nand ten million tub2 = ";
    cout<<10*million*tub<<endl;

    cout<<"mint = "<<mint<<"and a million mints = ";
    cout<<million*mint<<endl;
    return 0;
}
*/
/*
#include<iostream>
#include<string>
struct people{
   // char name[20];
   std::string name;
    float age;
    double weight;
};

int main()
{
    using namespace std;
    string str1;
    string str2="hhahahha";
    string str3;
    string str4;
    int len;
    people ren=
    {
        "Li hua",
        18,
        51.2
    };
    cin>>str1;
    cout<<"str1: "<<str1<<endl;
    cout<<"str2: "<<str2<<endl;
    str3=str1+str2;
    str1+=str2;
    cout<<"str3: "<<str3<<endl;
    cout<<"str1: "<<str1<<endl;
    len=str3.size();
    cout<<"len: "<<len<<endl;
    getline(cin,str4);
    return  0;
}
*/ 

/*
#include<iostream>
#include<fstream>

int main()
{
    int x,y;
    
    using namespace std;
    ifstream fout;
    fout.open("a.txt");
    cin>>x;
    y=(4 + x++)+(6 + x++);
    printf("%d\n",y);
    cout<<x<<endl;
    cout<<y<<endl;
    return 0;
}
*/
/*
#include<iostream>
#include<cstddef>
#include<iterator>
#include<vector>
#include<string>
#include<stdexcept>//异常
#include<cassert>
#include"Sales_data_ex21.h"

using namespace std;
void print(const int ia[10]);
int &get(int *array,int index);
int &get(int *arry, int index);

int main()
{*/
    /*
    std::cout<<"hello ,world"<<std::endl;
    int a,b;
    std::cout<<"enter two shuzi"<<std::endl;
    std::cin>>a>>b;
    std::cout<<"a+b = "<<a+b<<" and "<<
        " a*b = "<<a*b<<std::endl;
    */
  // std::cout<<"/*";
  // std::cout<<"*/";
  //std::cout<</* "*/" */;
  //  std::cout<</* "*/" /* "/*" */;
  /*
  int a=3,b=4;
  decltype(a) c =a;
  decltype((b)) d=a;
  ++c;
  ++d;
  std::cout<<"a : "<<a<<" b: "<<b<<" c: "<<c<<" d: "<<d<<std::endl;
  */
 //constexpr
 //    size_t array_size=10;
 /*
    int ia[10];
    for(size_t ix=1;ix<=10;++ix)
    {
        ia[ix]=ix;
    }
 
  //  int ia[10]={0,1,2,3,4,5,6,7,8,9};
    int *pbeg=std::begin(ia);
    int *pend=std::end(ia);
    while(pbeg!=pend)
    {
        std::cout<<*pbeg<<" ";
        pbeg++;
    }
    std::cout<<std::endl;
    */
// for(size_t i=1;i<=array_size;i++)
 //{
   //  std::cout<<ia[i]<<" ";
 //}
// std::cout<<std::endl;
   // const char ca[]={'h','e','l','l','o'};
    //const char *cp=ca;
    //while(*cp)
    //{
      //  std::cout<<*cp<<std::endl;
        //++cp;
    //}
    //int a;
    //a=5+10*20/2;
    //std::cout<<a<<std::endl;
    //std::cout<<5+10*20/2<<std::endl;
    //string s;
    //s="hello world";
    //for(auto t=s.begin();t!=s.end()/*&&!isspace(*t)*/;++t)
    //{
      //  *t=toupper(*t);
    //}
    //cout<<s<<endl;
    //vector<int> s{1,2,3,4,5,6,7,8,9};
    //for(auto &t:s)
    //{
      //  t=(( t % 2 ==0)?t:t*2);
    //}
    //for(auto t:s)
    //{
      //  cout<<t<<"  ";
    //}
    //cout<<endl;
    //string s="word";
    //string p1=s +((s[s.size()-1]=='s')? "":"s");
    //cout<<p1<<endl;
   // string s1,s2;
    //while(cin>>s1>>s2&&!s1.empty()&&s2.empty()&&s1[0]!='n')
    //{
      //if(s1.size()<s2.size())
        //cout<<s1;
      //else 
        //cout<<s2;
    //}
    //double a,b,t;
    //cin>>a>>b;
    //try{
      //t=a/b;
      //cout<<t<<endl;
    //}catch (invalid_argument err)
    //{
      //cout<<"error"<<endl;
    //}
    //vector<int> s{1,3,5,7,9,2,4,6,8,10};
    //int s[10]={1,3,5,7,9,2,4,6,8,10};
    //int a=1,b=2,c=3,d=4,x=5,y=6;
    ///int t= (x=a>b)&&(y=c>d) ;
     //cout<<t <<endl; 
    //print(s);

	//int ia[10];
	//for (int i = 0; i != 10; ++i){
		//get(ia, i) = i;
    //cout<<ia[i]<<" ";
  //}
  /*
  string s;
  while(cin>>s&&s!="sought") {} 
  assert(cin);

}

int &get(int *arry, int index) { return arry[index]; }


void print(const int ia[10])
{
  for(size_t i=0;i!=10;i++)
  {
    cout<<ia[i]<<endl;
  }
}*/
/*
#include <iostream>
#include <string>
#include "Sales_data_ex21.h"
using namespace std;
 
int main()
{
    Sales_data total(cin);

    if (!total.isbn().empty())
    {
        Sales_data trans;

        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(cout, total);
                std::cout << std::endl;
                total = trans;
            }
        }
        print(cout, total);
        std::cout << std::endl;

        return 0;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;  // indicate failure
    }
}


int KmpSearch(string s, string p)
{
	int i = 0;
	int j = 0;
	int sLen =s.size();
	int pLen = p.size();
	while (i < sLen && j < pLen)
	{
		//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++    
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]    
			//next[j]即为j所对应的next值      
			j = next[j];
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}*/
/*
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
  string expression{ "This is (pezy)." };
  bool bSeen = false;
  stack<char> stk;
  for (const auto &s : expression)
  {
    if (s == '(') { bSeen = true; continue; }
    else if (s == ')') bSeen = false;

    if (bSeen) stk.push(s);
  }

  string repstr;
  while (!stk.empty())
  {
    repstr += stk.top();
    stk.pop();
  }
    
  expression.replace(expression.find("(")+1, repstr.size(), repstr);
    
  cout << expression << endl;
    
  string express{"This is (express)."};
  bool judge=false;
  stack<char> stk1;
  for (const auto&s:express)
  {
    if(s=='('){judge=true;continue;}
    else if(s==')') judge=false;

    if(judge==true) stk1.push(s);
  }

  string rep;
  while(!stk1.empty())
  {
    rep+=stk1.top();
    stk1.pop();
  }
  express.replace(express.find('(')+1,rep.size(),rep);
  cout<<express<<endl;
  return 0;
}
*/
// #include<iostream>
// #include<map>
// #include<vector>
// #include <algorithm>
// using namespace std;
// // class Hasptr{
// //   public:
// //     Hasptr(Hasptr &&p) noexcept:ps(p.ps),i(p.i) {p.ps=0;}//noexcpt不抛出异常
// //     Hasptr &operator=(Hasptr rhs)
// //     {
// //       swap(*this,rhs);return *this;
// //     }
// // }
// int main()
// {
  // map<string,size_t> word_count;
  // string word;
  // while(cin>>word)
  // {
  //   ++word_count[word];
  //   if (cin.get()=='\n'){
  //     break;
  //   }
  // }
  // for (const auto &w:word_count)
  // {
  //   cout<<w.first<<" occurs "<<w.second<<((w.second>1)?" times":" time")<< endl;
  // }

  // vector<int> a{4,5,2,3,1};
  // vector<int> b(a);
  // int i,j;
  // for(i=0;i<5;i++)
  // {
  //   cout<<a[i];
  // }
  // cout<<endl;

  // for(i=0;i<5;i++)
  // {
  //   cout<<b[i];
  // }
  // cout<<endl;

  // for (i=0;i<5;i++)
  // {
  //   for ( j=0;j<4-i;j++)
  //   {
  //     if(a[i]>a[j])
  //     {
  //       swap(a[i],a[j]);
  //     }
  //   }
  // }

  // for(i=0;i<5;i++)
  // {
  //   cout<<a[i];
  // }
  // cout<<endl;

  // sort(b.begin(),b.end());

  // for(i=0;i<5;i++)
  // {
  //   cout<<b[i];
  // }
  // cout<<endl;

  // int a=5;
  // int &b=a;
  // auto &&c=a;
  // cout<<a<<endl<<b<<endl<<c<<endl;
  
//}
/*
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int cmp(char a,char b)
{
return a>b;
}
char map[300];
int main()
{
    scanf("%s",map);
int      len=strlen(map);
    sort(map,map+len,cmp);
    for(int i=0;i<len;i++)
        printf("%c ",map[i]);
    printf("\n");
    return 0;
}*/
/*
#include<iostream>
using namespace std;
class A{
    public:
    A(int i){x=i;}
    void dispa(){
        cout<<x<<",";
    }
    A& operator=(const A& rhs);
    private:
    int x;
};

class B:public A{
    public:
    B(int i):A(i+10){x=i;}
    void dispb(){
        cout<<x<<endl;
    }
    private:
    int x;
};

A& A::operator=(const A& rhs)
{
  if (this!= &rhs)
  {
    this->x=rhs.x;
  }
  return *this;
}

int main()
{
  A a(3);//a 3
  B b(3);//b 3 13
  a.dispa();//3
  b.dispa();//13
  b.dispb();//3
  a=b;
  a.dispa();
  return 0;
}

*/
/*
#include"iostream.h"
//#include<iostream>
//using namespace std;
using namespace std; 
int max(int x,int y);//函数声明
int main()
{
  int a,b,c;
	cin>>a>>b;
	c=max(a,b);
	cout<<"max= "<<c<<'\n';
}
int max(int x,int y)//函数定义
{
  int z;
  if(x>y) z=x;
	else z=y;
  return (z);
}
*/
/*
#include<iostream>
#include<string>
using namespace  std;
int main()
{
  string user_name;
  cout<<"Please enter you first name: ";
  cin>>user_name;
  cout<<'\n'<<"hello, "<<user_name<<"...and goodbye!\n";
  return 0;
}*/


/*
#include<iostream>
using namespace std;
int main()
{
  int a,b,c;
  cin>>a>>b;
  if(b==0) return -1;
  c=a/b;
  cout<<a<<endl<<b<<endl<<c<<endl;
  cout<<"c= "<<c<<'\n';
  return 0;
}*/

#include<iostream>
using namespace std;
void add(int &a,int b)
{
  a=a+b;
//  cout<<c<<endl;
  
 // return c;
}
int main()
{
  int a=1;
  int b=3;
  add(a,2);
  add(b,4);
  cout<<a<<" "<<b<<endl;
}