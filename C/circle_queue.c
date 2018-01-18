#include <stdio.h>
#include <stdlib.h>

#define QueueSize 100
typedef int DataType;
typedef struct 
{
	DataType data[QueueSize];
	int front,rear;
}CirQueue;

void InitQueue(CirQueue *Q)
{
	Q->front=Q->rear=QueueSize-1;
}

int EnQueue(CirQueue *Q,DataType x)
{
	if((Q->rear+1)%QueueSize==Q->front)
	{
		printf("������󣬲���ʧ��\n");
		return 0;
	}
	Q->rear=(Q->rear+1)%QueueSize;
	Q->data[Q->rear]=x;
	return 1;
}

int DeQueue(CirQueue* Q,DataType *ptr)
{
	if(Q->rear==Q->front)
	   {printf("�������ɾ��ʧ��\n");return 0;}
    Q->front=(Q->front+1)%QueueSize;
    *ptr=Q->data[Q->front];
}

int GetHead(CirQueue *Q,DataType *ptr)
{
	int i;
	if(Q->rear==Q->front)
	   {printf("�������ɾ��ʧ��\n");return 0;}
    i=(Q->front+1)%QueueSize;
    *ptr=Q->data[i];return 1;
}

int Empty(CirQueue *Q)
{
	if(Q->rear==Q->front) return 1;
	else return 0;
}

int main()
{
	DataType x;
	CirQueue Q;
	InitQueue(&Q);
	EnQueue(&Q,5);
	EnQueue(&Q,8);
	if(GetHead(&Q,&x)==1)
	printf("��ǰ��ͷԪ��Ϊ��%d\n",x);
	DeQueue(&Q,&x);
	if(GetHead(&Q,&x)==1)
	printf("��ǰ��ͷԪ��Ϊ��%d\n",x); 
}
