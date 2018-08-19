#include<iostream>
using namespace std;
typedef struct BiNode{				//二叉链表定义
	char data;
	struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

//先序遍历的顺序建立二叉链表
void CreateBiTree(BiTree &T){	
	//按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//递归结束，建空树
	else{							
		T=new BiTNode;
		T->data=ch;					//生成根结点
		CreateBiTree(T->lchild);	//递归创建左子树
		CreateBiTree(T->rchild);	//递归创建右子树
	}								//else
}									//CreateBiTree

void InOrderTraverse(BiTree T){  
	//中序遍历二叉树T的递归算法
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}
void firstTraverse(BiTree T){  
	//先序遍历二叉树T的递归算法
	if(T){
		cout << T->data;
		firstTraverse(T->lchild);
		firstTraverse(T->rchild);
	}
}
void lastTraverse(BiTree T){  
	//后序序遍历二叉树T的递归算法
	if(T){
		lastTraverse(T->lchild);
		lastTraverse(T->rchild);
		cout << T->data;
	}
}
int depth(BiTree T)  //计算二叉树的深度
{
	int m,n;
	if(T==NULL) return 0;
	else
	{
		m=depth(T->lchild);
		n=depth(T->rchild);
		if(m>n)  return (m+1);
		else     return (n+1);
	}
}
int NodeCount (BiTree T)
{
	if(T==NULL)  return 0;
	else  return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}
void main(){
	BiTree tree;
	cout<<"请输入建立二叉链表的序列：\n";
	CreateBiTree(tree);
	cout<<"先序遍历的结果为：\n";
	firstTraverse(tree);
	cout<<endl;
	cout<<"中序遍历的结果为：\n";
	InOrderTraverse(tree);
	cout<<endl;
	cout<<"后序遍历的结果为：\n";
	lastTraverse(tree);
	cout<<endl;
	cout<<"树的高度："<<depth(tree)<<endl;
	cout<<"二叉树中的所有结点个数："<<NodeCount(tree)<<endl;
}
