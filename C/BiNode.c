#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream.h>

typedef char DataType;
typedef struct BiNode
{
	DataType data;
	struct BiNode* lchild,*rchild;
}BiNode;

void PreOrder(BiNode *root)
{
	if (root==NULL) return;
	else{
		printf("%c",root->data);
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}

BiNode* CreatBiTree(BiNode* root)
{
	char ch;
	cin << ch
	if (ch=='#') root=NULL;
	else {
		root=(BiNode*)malloc(sizeof(BiNode));
		root->data=ch;
		root->lchild=CreatBiTree(root->lchild);
		root->rchild=CreatBiTree(root->rchild);
	}
	return root;
}

void DestroyBiTree(BiNode *root)
{
	if(root==NULL) return;
	DestroyBiTree(root->lchild);
	DestroyBiTree(root->rchild);
	free(root);
}

int main()
{
  	BiNode *root=NULL;
	root = CreatBiTree(root,p);
	PreOrder(root);
	DestroyBiTree(root);
	return 0; 
}
