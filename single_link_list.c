#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node *next;
} Node;

Node *InitList()
{
	Node *first = (Node *)malloc(sizeof(Node));
	first->next=NULL;
	return first;
}

int EmptyNode(Node *first)
{
	if (first->next == NULL) return 1;
	else return 0;
}

void PrintList(Node *first)
{
	Node *p=first->next;
	while(p){printf("%d\n",p->data);p=p->next;}

}

int Length(Node *first)
{
	int count = 1;
	Node *p=first->next;
	while(p)
	{
		p=p->next;
		count++;
	}
	return count;
}

int Locate(Node *first,DataType x)
{
	Node *p=first->next;
	int count = 1;
	while(p)
	{
		if(p->data==x) return count;
		p=p->next;
		count++;
	}
	return 0; 
}

int Insert(Node *first,int i,DataType x)
{
	Node *s=NULL,*p=first;
	int count =0;
	while (p!=NULL&&count<i-1)
	{
		p=p->next;
		count++;
	}
	if(p==NULL){printf("Î´Öª´íÎó¡¢²åÈëÊ§°Ü\n");return 0;}
	else {
	    s=(Node*)malloc(sizeof(Node));
	    s->data=x;
	    s->next=p->next;
	    p->next=s;
	    return 1;
	}
}

Node *CreatList(DataType a[],int n)
{
	int i=0;
	Node *s=NULL;
	Node *first=(Node *)malloc(sizeof(Node));
	first->next=NULL;
	for(i=0;i<n;i++)
	{
		s=(Node*)malloc(sizeof(Node));
		s->data=a[i];
		s->next=first->next;
		first->next=s;
	}
	return first;
}

int Delete(Node* first,int i)
{
	Node* p=first;Node* q=NULL;
	int count=0;
	while(p!=NULL&&count<i-1)
	{
		p=p->next;
		count++;
	}	
	if(p==NULL&&p->next==NULL)
	{
		printf("Î´Öª´íÎó¡¢É¾³ýÊ§°Ü\n");
	}
	else{
		q=p->next;
		p->next=q->next;
		free(q);return 1;
	}
}

void DestroyList(Node *first)
{
	Node* p=first;
	while(first!=NULL)
	{
		first=first->next;
		free(p);
		p=first;
	}
}
int main()
{
	int r[5]={1,2,3,4,5},i,x;
	Node *first=NULL;
	first=CreatList(r,5); 
	PrintList(first);
	Delete(first,3);
	PrintList(first);
	Insert(first,3,8);
	PrintList(first);
}
