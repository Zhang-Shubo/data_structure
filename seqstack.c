#include <stdio.h>
#include <stdlib.h>

#define StackSize 100 
typedef int DataType;
typedef struct
{
	DataType data[StackSize];
	int top;
}SeqStack;

void InitStack(SeqStack *S)
{
	S->top=-1;
}

int Push(SeqStack *S,DataType x)
{
	if(S->top==StackSize-1)
	   {printf("Õ»Òç³ö£¬ÈëÕ»Ê§°Ü£¡\n");return 0;}
    S->data[++S->top]=x;
    return 1;
}

int Pop(SeqStack *S,DataType *ptr)
{
	if(S->top==-1)
	   {printf("Õ»¿Õ¡¢³öÕ»Ê§°Ü£¡\n");return 0;}
    *ptr=S->data[S->top--];return 1;
}

int GetTop(SeqStack *S,DataType *ptr)
{
	if(S->top==-1)
	   {printf("Õ»¿Õ¡¢È¡Õ»Ê§°Ü£¡\n");return 0;}
    *ptr=S->data[S->top];return 1;	
}

int Empty(SeqStack *S)
{
	if(S->top==-1) return 1;
	else return 0;
} 

int main()
{
	DataType x;
	SeqStack S;
	InitStack(&S);
	Push(&S,10);
	Push(&S,3);
	if (GetTop(&S,&x)==1)
	    printf("µ±Ç°Õ»¶¥ÔªËØ%d\n",x);
    Pop(&S,&x);
	if (GetTop(&S,&x)==1)
	    printf("µ±Ç°Õ»¶¥ÔªËØ%d\n",x);    
	
}
