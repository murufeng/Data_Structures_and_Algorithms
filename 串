#include <stdio.h>
#include <iostream.h>
#include <stdlib.h>
#define INITSIZE 128
#define INCRE 20
#define OK 1
#define ERROR 0
typedef struct 
{
	char *data;
	int length;
	int stringsize;
}SqString;
int InitString(SqString *S)//初式化串
{
	S->data=(char*)malloc(INITSIZE*sizeof(char));
	if(!S->data)
		return ERROR;
	S->length=0;
	S->stringsize=INITSIZE;
	return OK;
}
int StrLength(SqString *S)//求串长
{
	return S->length;
}
int StrEmpty(SqString *S)//判断串空
{
	if(S->length==0)
		return OK;
	else 
		return ERROR;
}
int StrAssign(SqString *S,char *str)//串赋值
{
	int i=0;
	while(*str)
		S->data[i++]=*str++;
	S->data[i]='\0';
	S->length=i;
	return OK;
}
int StrCopy(SqString *S,SqString *T)//串复制
{
	int i=0;
	S->length=T->length;
	while (i<T->length)
		S->data[i]=T->data[i++];
	S->data[i]='\0';
	return OK;
}
int SubString(SqString *S1,SqString *S,int pos,int len)     //取子串。把S的第pos个字符开始长度为len的连续字符序列赋给子串S1
{
	int i;
	if(pos<1||pos>S->length||len<0||len>S->length-pos+1)
		return ERROR;
	S1->length=0;
	for(i=0;i<len;i++)
	{
		S1->data[i]=S->data[i+pos-1];
		S1->length++;
	}
	S1->data[i]='\0';
	return OK;
}
int StrCompare(SqString *S,SqString *T)//串比较
{
	int i;
	for(i=0;i<S->length&&i<T->length;i++)
		if(S->data[i]!=T->data[i])
			return S->data[i]-T->data[i];
		return S->length-T->length;
}
int StrConcat(SqString *S,SqString *S1,SqString *S2)//串连接
{
	int i=0,j=0;
	if(S1->length+S2->length>=S->stringsize)
	{
		S->data=(char *)realloc(S->data,(S->stringsize+INCRE)*sizeof(char));
		if(!S->data)
			return ERROR;
		S->stringsize+=INCRE;
	}
	while (i<S1->length)
		S->data[i]=S1->data[i++];
	while(j<S2->length)
		S->data[i++]=S2->data[j++];
	S->data[i]='\0';
	S->length=S1->length+S2->length;
	return OK;
}
void getNext(SqString *t,int next[])
{
	int i=0,j=-1;
	next[0]=-1;
	while(i<t->length)
	{
		if((j==-1)||(t->data[i]==t->data[j]))
		{
			i++;
			j++;
			next[i]=j;
		}
		else
			j=next[j];
	}
}//KMP算法
int indexKmp(SqString *S,SqString *t,int start,int next[])
{
	int i=start-1,j=0;
	while(i<S->length&&j<t->length)
		if(j==-1||S->data[i]==t->data[j])
		{
			i++;
			j++;
		}
		else
			j=next[j];
		if(j>t->length)
			return (i-t->length+1);
		else
			return 0;
}
void print(SqString *S)
{
	cout<<S;
}
int main()
{
	//SqString *S,*t,*S1,*S2,*s3,*T;

	int next[100];
	SqString *S,*t,*S1,*S2,*S3,*T;
	InitString(S);
	//InitString(t);
	//InitString(S1);
	//InitString(S2);
	//InitString(S3);
	//InitString(T);
	
	S->data="ABSDERFGTGH";
	//t->data="2345BDGREFGYHYF";
	//S2->data="AVDGR13246f8gy";
	int a;
	while(1)  
    {  
       
        printf("1.求S串长\n");  
        printf("2.把S串复制给S3\n");  
        printf("3.连接S,t串\n");  
        printf("4.比较S和S2两串大小\n");  
        printf("5.取子串。把S的第pos个字符开始长度为len的连续字符序列赋给子串S1\n");  
        printf("6.串模式匹配S和t\n");  
        printf("0.退出\n");  
        printf("\n输入1-6，选择您需要的功能:");  
        scanf("%d",&a);  
        printf("\n您选择的功能号为：%d\n",a);
	}
	switch(a)
	{
	case 1:StrLength(S);
		break;
	case 2:StrCopy(S3,S);print(S3);
		break;
	case 3:StrConcat(T,S,t);
		break;
	case 4:StrCompare(S,S2);
		break;
	case 5:SubString(S1,S,3,4);print(S1);
		break;
	case 6:indexKmp(S,t,2,next);
		break;
	case 0:printf("退出\n");
		 default:break;
	}
	return 0;
}
