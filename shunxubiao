#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define MAXSIZE 10
#define NULL 0
#define OK 1
typedef int ElemType;
typedef struct SqList
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;
int InitList(SqList *L)
{
	L->elem=(ElemType *)malloc(sizeof(ElemType));
	if(!L->elem)
		exit(ERROR);
	L->length=0;
	L->listsize=MAXSIZE;
	return OK;
}

ElemType GetElem(SqList L,int i)
{
	int temp;
	if(i<1||i>L.length)  return ERROR;
	temp=L.elem[i-1];
	return temp;
}
int LocateElem(SqList L,ElemType e)
{
	int i;
	for(i=0;i<L.length;i++)
		if(L.elem[i]==e)
			return i+1;
		return 0;
}
int ListInsert(SqList *L,int i,ElemType e)
{
	int j;
	if((i<1)||(i>L->length+1))
		return ERROR;
	if(L->length==MAXSIZE)
		return ERROR;
	for(j=L->length-1;j>=i-1;j--)
		L->elem[j+1]=L->elem[j];
	L->elem[i-1]=e;
	++L->length;
	return OK;
}
int ListDelete(SqList *L,int i)
{
	int j;
	if((i<1)||(i>L->length+1))
		return ERROR;
	for(j=i;j<=L->length-1;j++)
		L->elem[j-1]=L->elem[j];
	--L->length;
	return OK;
}
int Print(SqList L)
{
	int j;
	printf("顺序表L:");
	for(j=1;j<=L.length;j++)
		printf("%d\t",L.elem[j-1]);
	printf("\n");
	return OK;
}
int main()
{
	SqList *pL=(SqList *)malloc(sizeof(SqList));
	InitList(pL);
	int a,i;
	ElemType data;
	while(1)  
    {  
        printf("\n\n/*********欢迎使用本系统**********/\n\n");  
        printf("\n1.创建一个顺序表表\n");  
        printf("\n2.输出顺序表中的所有数据\n");  
        printf("\n3.查询顺序表表中某个位置的数据\n");  
        printf("\n4.查询与数据匹配的元素的位置\n");  
        printf("\n5.向顺序表表中插入数据\n");  
        printf("\n6.删除顺序表表中的数据\n");  
        printf("\n0.退出\n");  
        printf("\n输入1-6，选择您需要的功能:");  
        scanf("%d",&a);  
        printf("\n您选择的功能号为：%d\n",a);  
  
        switch(a)  
        {  
            case 1:InitList(pL);printf("\n创建成功\n");break;  
            case 2:Print( *pL);break;  
            case 3:printf("\n请输入您需要查询的元素的编号1-%d:",pL->length);  
                   scanf("%d",&i);  
                   data=GetElem(*pL,i);  
                   printf("\n您查询的数据为%d\n",data);  
                   break;  
            case 4:printf("\n请输入您需要查询的数据元素:\n");  
                   scanf("%d",&data);  
                   if(LocateElem(*pL,data)) printf("\n您查询的元素的位置是:%d\n",LocateElem(*pL,data));  
                   else printf("\n没有查询到您输入的数据\n");  
                   break;  
            case 5:printf("\n请输入您需要插入的数据以及它的位置:");  
                   scanf("%d%d",&data,&i);  
                   printf("\n您需要插入的数据是%d\n您要插入的位置是:%d\n",data,i);  
                   if(ListInsert(pL,i,data)) printf("\n插入成功\n");  
                   printf("插入后的链表排序为:\n");  
                   Print(*pL);  
                   break;  
            case 6:printf("\n请输入您需要删除元素的位置:");  
                   scanf("%d",&i);  
                   printf("您要删除的位置是:%d\n",i);  
                   if(ListDelete(pL,i)) printf("删除成功\n");  
                   printf("删除后的链表为：\n");  
                   Print(*pL);  
                   break;  
            case 0: return OK;  
            default:break;  
  
        }  
    }  
    return 0;  
}  
