#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int DataType;
typedef struct
{
	DataType data[MaxSize];
	int length;
}SeqList;

//初始化线性表 
void InitList(SeqList *L)
{
	L->length=0;
}

//创建线性表 
int CreatList(SeqList *L,DataType a[],int n)
{
    int i = 0;
	if (n>MaxSize)
	{
	    printf("顺序表空间不够，无法建立顺序表\n");
		return 0;
	}

	for(i=0; i<n; i++)
	   L->data[i]=a[i];
    L-> length=n;
    return 1;
}

//判断是否是空表 
int Empty(SeqList *L)
{
	if(L->length == 0) return 1;
	else return 0;
}

//返回线性表的长度
int Length(SeqList *L)
{
	return L->length;
}

//输出线性表所有数值 
void PrintList(SeqList *L)
{
	int i=0;
	for (i=0; i<L->length;i++)
	{
		printf("%d\n",L->data[i]);
	}
}

//返回线性表中数值的位置 
int Locate(SeqList *L,DataType x)
{
	int i =0;
	for (i=0;i<L->length;i++)
	{
		if (L->data[i]==x)
		return i+1; 
	}
	return 0;
}

//查找线性表 
int Get(SeqList *L,int i,DataType *ptr)
{
	if (i<1 || i>L->length){printf("查找失败\n");return 0;}
	else {*ptr = L->data[i-1];return 1;}
} 

//表插入操作 
int Insert(SeqList *L,int i, DataType x)
{
	int j=0;
	if(L->length>=MaxSize) {printf("序列溢满、插入失败\n");return 0;}
	if(i<1||i>L->length) {printf("位置错误、插入失败\n");return 0;}
	for(j=L->length;j>=i;j--)
	{
		L->data[j]=L->data[j-1];
	}
	L->data[i-1]=x;
	L->length++;
	return 1;
}

//表删除操作 
int Delete(SeqList *L, int i)
{
	int j= 0;
    if(L->length==0) {printf("序列空、删除失败\n");return 0;}
	if(i<1||i>L->length) {printf("位置错误、删除失败\n");return 0;}
	for(j=i;j<L->length;j++)
	    L->data[j-1]=L->data[j];
    L->length--;
    return 1;	     
}

int main()
{
	int r[5]={1,2,3,4,5},i,x;
	SeqList L;
	CreatList(&L,r,5);
	printf("当前线性表数据为：\n");
	PrintList(&L); 
	Insert(&L,3,8);
	PrintList(&L); 
	Delete(&L,4);
	PrintList(&L); 
}
