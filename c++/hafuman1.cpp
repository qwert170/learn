/*时间：2018.12.30
*作者：吴扬俊
*内容：给出任意一篇全英文字符的文本，求出其最优编码，并能解码
思路：
1，建立字频表（统计文本中每个字符出现的次数）
2，建立哈夫曼树，并求每个字符对应的编码
3，给文本编码，以二进制保存于文件code.dat
4，根据哈夫曼树，将code.dat解码，结果保存于recode.txt 
tips:
1，二进制文件读写（无法使用string)
2，ASCII码和字符转换
3，哈夫曼算法
4，哈希思想的妙用（计算字频；编码使用） 

数据结构
typedef struct
{
	int ascii,weight,parent,lchild,rchild;//哈夫曼树，它们依次表示：字符的ASCII码，双亲，左孩子，右孩子 
}HTNode,*HuffmanTree;

算法
假设有n个字符，申请2n个空间，0号不用 ,HTree数组首地址 
1，初始化1，所有成员赋0；初始化2，读入字符及相应的权值
2，令下个根节点j = n+1,在parent=0的点中挑选出最小值，次小值分别记录其下标index1，index2；
3，最小值和次小值的parent=j;  
*/
#include<iostream>
using namespace std;
#include<stdlib.h> 
#include<fstream>
#include<string>
#include<stack>

#define MIN1 0x1fffffff
#define MIN2 0x2fffffff


//Attention：只可以识别英文输入法下的所有字符，中文打出来的‘？’都不行 
char code[20];//二进制读写准备 

typedef struct
{
	int ascii,weight,parent,lchild,rchild;//哈夫曼树，它们一次表示：字符的ASCII码，双亲，左孩子，右孩子 
}HTNode,*HuffmanTree;

//统计每个字符出现次数：只有英文符号，否则报错 
void Count_Character_Occur_Frequency()
{
	int cof[256];//存储相应字符出现的次数，字符ASCII为下标。charater_occur_frequency 
	for(int i = 0; i < 256; i++)//初始化字符出现次数统计表 
	{
		cof[i] = 0;
	}
	//从源文件按行读取，并统计字符个数，由于字符个数有限，所以用字符的ASCII码作为数组下标，数组值作为次数，类似哈希映射 
	fstream inFile("source.txt",ios::in); 
	if(!inFile)cout<<"source.txt 打开失败！"<<endl;
	
	int sum = 0;//总行数，记录换行个数 
	string s;//存放一行 
	while(true)
	{
		getline(inFile,s);
		if(!inFile)break;//避免重复读取最后一个字符 
		sum++;
		for(int i = 0; i < s.size(); i++)
		{
			int a = s[i];//cout<<"a:"<<a<<endl;中文会溢出 
			cof[a]++; //计数 
		}
	}
	inFile.close();//好习惯 
	int a = '\n';//换行符 
	cof[a] = sum; //换行符个数 
	//=======将所有出现的字符及其次数写入文件（类似全局数组）========= 
	int n = 0;//计算出现字符总个数 
	for(int i = 0; i < 256; i++)
	{
		if(cof[i] != 0)n++; 
	}
	fstream outFile("字频表.txt",ios::out);
	if(!outFile)cout<<"字频表.txt 打开失败！"<<endl;
	outFile<<n<<endl;//写入字符总个数 
	//打印调试 
	for(int i = 0; i < 256; i++)
	{
		if(cof[i] != 0)
		{
			char ch = i - '\0';
	//		cout<<"i: "<<i<<"  字符："<<ch<<" cof[i]: "<<cof[i]<<endl;
			outFile<<i<<" "<<cof[i]<<endl;//写入文件 
		}
	}
	outFile.close();
}
//创建哈夫曼树 
void CreateHT()
{
	HuffmanTree HTree;
	fstream inFile("字频表.txt",ios::in);
	if(!inFile)cout<<"字频表.txt 打开失败！"<<endl;
	
	int n;//节点个数
	inFile>>n;
	HTree = (HTNode*)malloc(2*n*sizeof(HTNode));//哈夫曼构造，共需2n-1个，0号单元不用
	for(int i = 1; i < 2*n; i++)//初始化 1
	{
		HTree[i].ascii = HTree[i].lchild = HTree[i].parent = HTree[i].rchild = HTree[i].weight = 0;//0号单元无用 
	} 
	for(int i = 1; i <= n; i++)//初始化 2，从文件读取ASCII码及相应权值 
	{
		inFile>>HTree[i].ascii>>HTree[i].weight;
	} 
	inFile.close();
/*	for(int i = 1; i < 2*n; i++)//打印输出调试 
	{
		cout<<HTree[i].ascii <<" "<<HTree[i].weight<<endl;
	} 
*/	
	for(int i = n+1; i < 2*n; i++)//从n+1开始，进行n-1次计算 
	{
		//寻找最小，次小值，记录其下标 
		int min1 = MIN1,min2 = MIN2;
		int index1 = 0,index2 = 0;
		
		for(int j = 1; j < i; j++)//i是即将要被填入的根节点 
		{
			if(HTree[j].parent == 0)//双亲为0表示尚待操作 
			{
				if(min1 > HTree[j].weight)
				{
					min2 = min1;//先赋给次小值 
					index2 = index1;
					min1 = HTree[j].weight;
					index1 = j;
				}
				else if(min2 > HTree[j].weight)
				{
					min2 = HTree[j].weight;
					index2 = j;
				}
			}
		}//cout<<index1<<" "<<index2<<endl; 
		
		HTree[i].weight = HTree[index1].weight + HTree[index2].weight;//双亲权值更新 
		HTree[index1].parent = HTree[index2].parent = i;//孩子的双亲节点更新
		if(HTree[index1].weight < HTree[index2].weight)//1，两个节点权值不同，左小右大 ；相同，下标小者在左 
		{
			HTree[i].lchild = index1;//下标赋值 
			HTree[i].rchild = index2;
		}
		else if(HTree[index1].weight > HTree[index2].weight)
		{
			HTree[i].lchild = index2;
			HTree[i].rchild = index1;
		}
		else 
		{
			if(index1 < index2)
			{
				HTree[i].lchild = index1;
				HTree[i].rchild = index2;
			}
			else
			{
				HTree[i].lchild = index2;
				HTree[i].rchild = index1;
			}
		}
	} 
	fstream outFile("哈夫曼树.txt",ios::out);
	if(!outFile)cout<<"哈夫曼树.txt 无法打开！"<<endl;
	outFile<<n<<endl;//节点个数 
	for(int i = 1; i < 2*n; i++)//打印输出调试 
	{
//		cout<<"i:"<<i<<" ascii:"<<HTree[i].ascii <<" weight:"<<HTree[i].weight<<" parent:"<<HTree[i].parent<<" lchild:"<<HTree[i].lchild<<" rchild:"<<HTree[i].rchild<<endl;
		outFile<<" "<<HTree[i].ascii <<" "<<HTree[i].weight<<" "<<HTree[i].parent<<" "<<HTree[i].lchild<<" "<<HTree[i].rchild<<endl;	
	} 
	outFile.close();
	
	//==========建立编码表，写入字符，权值，编码==================
	outFile.open("哈夫曼编码表.txt",ios::out);
	if(!outFile)cout<<"哈夫曼编码表.txt 打开失败！"<<endl;
	//利用栈从叶子出发读取每个字符的编码，在写入文件 
	stack<char> code;//存储编码 
	for(int i = 1; i <= n; i++)//对n个字符分别求编码 
	{
		int j = i;
		do{
			int p = HTree[j].parent;
			if(p != 0)
			{
				int l,r;
				l = HTree[p].lchild;
				r = HTree[p].rchild;
				if(j == l)code.push('0');
				if(j == r)code.push('1');
				j = p;
			}
		}while(HTree[j].parent != 0);
		
		outFile<<HTree[i].ascii<<" "<<HTree[i].weight<<" ";//写入字符，权值 
		while(!code.empty())
		{
			outFile<<code.top();//写入编码 
			code.pop();
		}outFile<<endl;
	} 
	outFile.close();
} 
void Encode()
{
	fstream inFile("哈夫曼编码表.txt",ios::in);
	if(!inFile)cout<< "哈夫曼编码表.txt"<<endl;
	string s,codeList[256];//将编码表从文件读入该数组中，ASCII码为下标，类似哈希映射 
	int ch,w;
	while(true)
	{
		inFile>>ch>>w>>s;
		if(!inFile)break;
//		cout<<" ch:"<<ch<<" w:"<<w<<" s:"<<s<<endl;
		codeList[ch] = s; 
	}
	inFile.close();
	
//	cout<<codeList[63]<<endl; 
/*	for(int i = 0; i < 256; i++)//测试 
	{
		if(!codeList[i].empty())
		{//cout<<"!"<<endl;
		//	cout<<i<<" "<<codeList[i]<<endl;
		}
	}
*/	
	inFile.open("source.txt",ios::in);
	if(!inFile)cout<<"source.txt 打开失败！"<<endl;
/*	fstream outFile("code.txt",ios::out);
	if(!outFile)cout<<"code.txt打开失败！"<<endl;
*/	
	fstream outFile("code.dat",ios::out|ios::binary);
	if(!outFile)cout<<"code.dat打开失败！"<<endl;
	string s2;
	while(true)
	{
		getline(inFile,s);
		if(!inFile)break;
		int a;
		for(int i = 0; i < s.size(); i++)
		{
			a = s[i];//转化为ASCII码 
			int j; 
			for(j = 0; j < codeList[a].size();j++)
			{	
				s2 = codeList[a];
				code[j] = s2[j];
			}code[j]='\0';//!!!关键的一句 
			outFile.write((char*)code,20*sizeof(char));
		}
		a = '\n';
		for(int j = 0; j < codeList[a].size();j++)
		{
			code[j]  = (codeList[a])[j];
		}
		outFile.write((char*)code,20*sizeof(char));
	}
	inFile.close();
	outFile.close(); 
}
//解码 
void Decode()
{
	fstream inFile("哈夫曼树.txt",ios::in);
	if(!inFile)cout<<"哈夫曼树.txt 打开失败！"<<endl; 
	int n;
	inFile>>n;
	HuffmanTree HTree;
	HTree = (HTNode*)malloc(2*n*sizeof(HTNode));
	for(int i = 1; i < 2*n; i++)
	{
		inFile>>HTree[i].ascii >>HTree[i].weight>>HTree[i].parent>>HTree[i].lchild>>HTree[i].rchild;	
	}
	inFile.close();
	for(int i = 1; i < 2*n; i++)//打印输出调试 
	{
	//	cout<<"i:"<<i<<" ascii:"<<HTree[i].ascii <<" weight:"<<HTree[i].weight<<" parent:"<<HTree[i].parent<<" lchild:"<<HTree[i].lchild<<" rchild:"<<HTree[i].rchild<<endl;
	} 
/*	inFile.open("code.txt",ios::in);
	if(!inFile)cout<<"code.txt 打开失败！"<<endl;
*/
	inFile.open("code.dat",ios::in|ios::binary);
	if(!inFile)cout<<"code.dat 打开失败！"<<endl;
	
	fstream outFile("recode.txt",ios::out);
	if(!outFile)cout<<"recode.txt 打开失败！"<<endl;
	char ch;
	int root = 2*n - 1;//char code[100];
//	string s;
	while(true)
	{
		inFile.read((char*)code,20*sizeof(char));
		if(!inFile)break;
	//	cout<<"ch: "<<ch<<" root: "<<root<<endl;	
		for(int i = 0; code[i] != '\0'; i++)
		{//cout<<ch;
			ch = code[i];
			if(ch == '0')root = HTree[root].lchild;
		else if(ch == '1')root = HTree[root].rchild;
		
		if(HTree[root].lchild == 0)
		{//cout<<endl;
			char cht = HTree[root].ascii;
			outFile<<cht;
			root = 2*n - 1;
		} 
		
		}//cout<<endl;
	}
	outFile.close();
}
int main()
{
	Count_Character_Occur_Frequency();
	CreateHT();
	Encode();
	Decode();
	return 0;
} 
