#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node *next;
}Node;

typedef struct
{
	Node *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue* Q)
{
	Node* s=(Node*)malloc(sizeof(Node));
	s->next=NULL;
	Q->front=Q->rear=s;
}

void DestroyQueue(LinkQueue *Q)
{
	Node* p=Q->front,*temp;
	while (p!=NULL)
	{
		temp=p->next;
		free(p);
		p=temp;
	}
}

void EnQueue(LinkQueue *Q,DataType x)
{
	Node *s = (Node*)malloc(sizeof(Node));
	s->data = x;s->next=NULL;
	Q->rear->next=s;Q->rear=s; 
}

int DeQueue(LinkQueue *Q,DataType *ptr)
{
	Node *p=NULL;
	if(Q->rear==Q->front){return 0;}
	p=Q->front->next;*ptr=p->data;
	Q->front->next=p->next;
	if(p->next=NULL)
	    Q->rear=Q->front;
    free(p);return 1;
}

int GetHead(LinkQueue *Q,DataType *ptr)
{
	Node *p=NULL;
	if(Q->rear==Q->front){return 0;}
	p=Q->front->next;*ptr=p->data;
	return 1;
}

int main()
{
	DataType x;
	LinkQueue Q;
	InitQueue(&Q);
	EnQueue(&Q,5);
	EnQueue(&Q,8);
	if(GetHead(&Q,&x)==1) 
	    printf("当前对头元素为：%d\n",x);
    DeQueue(&Q,&x);
    if(GetHead(&Q,&x)==1) 
	    printf("当前对头元素为：%d\n",x);
}
