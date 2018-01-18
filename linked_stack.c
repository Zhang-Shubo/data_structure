#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node *next;
} Node;

void InitStack(Node *top)
{
	top=NULL;
}

void DestroyStack(Node *top)
{
	Node *p=top;
	while (top!=NULL)
	{
		top=top->next;
		free(p);
		p=top;
	}
}

void Push(Node *top,DataType x)
{
	Node *s=(Node*)malloc(sizeof(Node));
	s->data=x;
	s->next=top;top=s;
}

int Pop(Node *top,DataType *ptr)
{
	Node *p=top;
	if(top==NULL){printf("ÉÏÒç´íÎó£¬³öÕ»Ê§°Ü\n"); return 0;}
	*ptr=top->data;
	top=top->next;
    free(p);return 1;
}

int GetTop(Node *top,DataType *ptr)
{
	if(top==NULL){printf("ÉÏÒç´íÎó£¬È¡Õ»Ê§°Ü\n"); return 0;}
	*ptr=top->data;return 1;
}

int main()
{
	DataType x;
	Node *top=NULL;
	InitStack(top);
	Push(top,10);
	Push(top,3);
	if(GetTop(top,&x)==1)
	    printf("Õ»¶¥ÔªËØÎª£º%d\n",x);
	Pop(top,&x) ;
	if(GetTop(top,&x)==1)
        printf("Õ»¶¥ÔªËØÎª£º%d\n",x);
    DestroyStack(top);
    return 0;
}
