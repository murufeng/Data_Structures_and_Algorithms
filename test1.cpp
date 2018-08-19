#include <stdio.h>
#define NULL 0
typedef int Elemtype;
typedef struct slnode
  {
	Elemtype  data;
	struct slnode *next;
  }L,slnodetype;

slnodetype *inti(slnodetype *head)
{
 head=(slnodetype *)malloc(sizeof(slnodetype));
 head->next=NULL;
 return  head;
}

slnodetype *create(slnodetype *head)
{
  slnodetype *p,*q;
  Elemtype  x;
  head=(slnodetype *)malloc(sizeof(slnodetype));
  head->next=NULL;
  q=head;
  scanf("%d",&x);
  while (x!=-1)
	{
	 p=(slnodetype *)malloc(sizeof(slnodetype));
	 p->data=x;
	 q->next=p;
	 q=p;
	 scanf("%d",&x);
	}
  p->next=NULL;
  return  head;
}

slnodetype *find(slnodetype *head,Elemtype x)
{
  slnodetype *p;

  p=head->next;
  while ((p!=NULL)&&(p->data!=x))
	 p=p->next;
  return  p;
}


slnodetype *get(slnodetype *head,int i)
{
  slnodetype *p;
  int j;
  j=0;
  p=head;
  while ((p!=NULL)&&(j<i))
	{
	 p=p->next;
	 j++;
	}
  return  p;
}

slnodetype *insert(slnodetype *head,int i,Elemtype x)
{
  slnodetype *p,*q;

  int j;
  j=1;
  p=head;
  while ((p!=NULL)&&(j<i))
	{
	 p=p->next;
	 j++;
	}
  if (j!=i||p==NULL) return  head;
  else {
	  q=(slnodetype *)malloc(sizeof(slnodetype));
	  q->data=x;
	  q->next=p->next;
	  p->next=q;
	  return  head;
	}
  
}

slnodetype *delete(slnodetype *head,int i)
{
  slnodetype *p,*q;
  int j;
  j=0;
  p=head;
  while ((p->next!=NULL)&&(j<i-1))
	{
	 p=p->next;
	 j++;
	}
  if (j==i-1&&p->next!=NULL)
	{
	  q=p->next;
	  p->next=p->next->next;
	  free(q);
	}
  return  head;
}

void print(slnodetype  *head)
{
 slnodetype  *p;
 p=head->next;
 while (p!=NULL)
  {
	 printf("%d  ",p->data);
	 p=p->next;
  }
 printf("\n");
}


main()
{
  int s,i;
  Elemtype  x;
  slnodetype *head,*p;
  //clrscr();
  while (1)
  {
	printf("0-------exit\n");
	printf("1-------inti\n");
	printf("2-------create\n");
	printf("3-------find\n");
	printf("4-------get\n");
	printf("5-------insert\n");
	printf("6-------delete\n");
	printf("7-------print\n");
	printf("------------------\n");
	printf("please input s=");
	scanf("%d",&s);
	printf("\n");
	switch (s)
	 {
	  case 0:exit(0);break;
	  case 1:head=inti(head);
				break;
	  case 2:head=create(head);
				print(head);
				break;
	  case 3:scanf("%d",&x);
				p=find(head,x);
				if (p!=NULL)
					printf("%d\n",p->data);
				else
					printf("no find!\n");
				break;
	  case 4:scanf("%d",&i);
				p=get(head,i);
				if (p!=NULL)
					printf("%d\n",p->data);
				else
					printf("no find!\n");
				break;
	  case 5:scanf("%d%d",&i,&x);
				head=insert(head,i,x);
				print(head);
				break;
	  case 6:scanf("%d",&i);
				head=delete(head,i);
				print(head);
				break;
	  case 7:print(head);
				break;
	  }
  }
}
