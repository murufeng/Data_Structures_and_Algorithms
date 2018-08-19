#include<stdio.h>
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef char Elem;
typedef struct stack
{
	Elem *base;
	Elem *top;
	int num;
}Sqstack;
int  InitStack(Sqstack &s)
{
	s.base=new Elem[MAXSIZE];
	if(s.base==NULL)
	{
		printf("栈创建失败!\n");
		return 0;
	}
	s.top=s.base;
	*s.top=0;
	s.num=100;
}
int  push(Sqstack &s,Elem e)
{
	if((s.top-s.base)>=s.num)
	{
		printf("栈已满!\n");
		return 0;
	}
	*s.top++=e;
}
int  pop(Sqstack &s,Elem e)
{
	if(s.base==s.top)
	{
		printf("该栈是空栈!\n");
		return 0;
	}
	e=*--s.top;
}
bool StackEmpty(Sqstack &s)
{
	if(s.base==s.top)
		return true;
	return false;
}
bool Matching(Sqstack &s)
{
	InitStack(s);
	int flag;
	flag=1;
	char x;
	char ch;
	cin>>ch;
	while(ch!='#'&&flag)
	{
		switch(ch)
		{
		case'[':
		case'(':
			push(s,ch);
			break;
		case ')':
			if(*(s.top-1)=='('&&!StackEmpty(s))
				pop(s,x);
			else flag=0;
			break;
		case ']':
			if(*(s.top-1)=='['&&!StackEmpty(s))
		      pop(s,x);
			else
				flag=0;
			break;
		}
		cin>>ch;
	}
	if(StackEmpty(s)&&flag)
		return true;
	else
	    return false;
}
int main()
{
	Sqstack s;
	InitStack(s);
	if(Matching(s))
		printf("输入的括号匹配!\n");
	else
		printf("输入的括号不匹配!\n");
	free(s.base);
	return 0;	
}
