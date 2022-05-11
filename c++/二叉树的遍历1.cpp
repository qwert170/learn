#include <iostream>
using namespace std;
//二叉树链式表示 
//结点类模板 
template<class T>
class TreeNode
{
	public:	
		//数据域
		T data;
		//左孩子，右孩子 
		TreeNode<T> *leftChild;
		TreeNode<T> *rightChild; 
		//创建
		TreeNode()
		{
			this->leftChild = NULL;
			this->rightChild = NULL;
		} 
};
//数类
template<class T>
class BinaryTree
{
	public:
		TreeNode<T> *root;
		//二叉树操作
		//中序遍历 
		void InOrder(TreeNode<T>* currentNode); 
		//先序遍历
		void PreOrder(TreeNode<T>* currentNode); 
		//后序遍历 
		void PostOrder(TreeNode<T>* currentNode); 
		//层序遍历
		void LevelOrder(TreeNode<T>* currentNode); 
}; 
//中序
template <class T>
void BinaryTree<T>::InOrder(TreeNode<T>* currentNode)
{
	if(currentNode){	
		InOrder(currentNode->leftChild);
		cout << currentNode->data << endl;
		InOrder(currentNode->rightChild);		
	}	
} 
//先序 
template <class T>
void BinaryTree<T>::PreOrder(TreeNode<T>* currentNode){
	if(currentNode){
		cout << currentNode->data << endl;	
		InOrder(currentNode->leftChild);
		InOrder(currentNode->rightChild);		
	}	
}
//后序
template <class T>
void BinaryTree<T>::PostOrder(TreeNode<T>* currentNode)
{
	if(currentNode){	
		InOrder(currentNode->leftChild);
		InOrder(currentNode->rightChild);	
		std::cout << currentNode->data << std::endl;	
	}	
} 
//层序
template <class T>
void BinaryTree<T>::LevelOrder(TreeNode<T>* currentNode){
	if(currentNode == root) 
	cout << currentNode->data<<endl;
	if(currentNode&&currentNode->leftChild || currentNode&&currentNode->rightChild)
	{
		cout << currentNode->leftChild->data;
		cout << currentNode->rightChild->data;
		cout<<endl;
		LevelOrder(currentNode->leftChild);
		LevelOrder(currentNode->rightChild);
	}	

} 
//创建二叉树—手动创建 
int main()
{
	BinaryTree<int> tree;
	TreeNode<int> a, b, c, d, e, f, g;
	a.data = 1;
	b.data = 2;
	c.data = 3;
	d.data = 4;
	e.data = 5;
	f.data = 6;
	g.data = 7;
	
	tree.root = &a;
	a.leftChild = &b;
	a.rightChild = &c;
	b.leftChild = &d;
	d.rightChild = &e;
	c.leftChild = &f;
	c.rightChild = &g;

	tree.InOrder(tree.root);
	cout<<"先序"<<endl; 
	tree.PreOrder(tree.root);
	cout<<"后序"<<endl; 
	tree.PostOrder(tree.root); 
	cout<<"层序"<<endl;
	tree.LevelOrder(tree.root); 
}