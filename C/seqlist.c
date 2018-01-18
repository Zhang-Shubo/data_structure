#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int DataType;
typedef struct
{
	DataType data[MaxSize];
	int length;
}SeqList;

//��ʼ�����Ա� 
void InitList(SeqList *L)
{
	L->length=0;
}

//�������Ա� 
int CreatList(SeqList *L,DataType a[],int n)
{
    int i = 0;
	if (n>MaxSize)
	{
	    printf("˳���ռ䲻�����޷�����˳���\n");
		return 0;
	}

	for(i=0; i<n; i++)
	   L->data[i]=a[i];
    L-> length=n;
    return 1;
}

//�ж��Ƿ��ǿձ� 
int Empty(SeqList *L)
{
	if(L->length == 0) return 1;
	else return 0;
}

//�������Ա�ĳ���
int Length(SeqList *L)
{
	return L->length;
}

//������Ա�������ֵ 
void PrintList(SeqList *L)
{
	int i=0;
	for (i=0; i<L->length;i++)
	{
		printf("%d\n",L->data[i]);
	}
}

//�������Ա�����ֵ��λ�� 
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

//�������Ա� 
int Get(SeqList *L,int i,DataType *ptr)
{
	if (i<1 || i>L->length){printf("����ʧ��\n");return 0;}
	else {*ptr = L->data[i-1];return 1;}
} 

//�������� 
int Insert(SeqList *L,int i, DataType x)
{
	int j=0;
	if(L->length>=MaxSize) {printf("��������������ʧ��\n");return 0;}
	if(i<1||i>L->length) {printf("λ�ô��󡢲���ʧ��\n");return 0;}
	for(j=L->length;j>=i;j--)
	{
		L->data[j]=L->data[j-1];
	}
	L->data[i-1]=x;
	L->length++;
	return 1;
}

//��ɾ������ 
int Delete(SeqList *L, int i)
{
	int j= 0;
    if(L->length==0) {printf("���пա�ɾ��ʧ��\n");return 0;}
	if(i<1||i>L->length) {printf("λ�ô���ɾ��ʧ��\n");return 0;}
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
	printf("��ǰ���Ա�����Ϊ��\n");
	PrintList(&L); 
	Insert(&L,3,8);
	PrintList(&L); 
	Delete(&L,4);
	PrintList(&L); 
}
