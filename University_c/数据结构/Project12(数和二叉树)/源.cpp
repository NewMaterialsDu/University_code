#include<stdio.h>
#include<stdlib.h>
#include<iostream>

//树和二叉树
typedef char ElemType;
typedef struct TreeNode {
	ElemType data;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;
typedef TreeNode* BiTree;

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;

//递归添加
void createTree(BiTree* T) {
	ElemType ch;
	//下面一行相当于ch=str[idx];idx++;先执行再++
	ch = str[idx++];
	if (ch == '#') {
		*T = NULL;
	}
	else {
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		createTree(&(*T)->rchild);
	}
}

//递归遍历
//二叉树前序遍历--根左右
void preOrder(BiTree T) {
	if (T == NULL) {
		return;
	}
	printf("%c", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}

//中序遍历--左根右	
void inOrder(BiTree T) {
	if (T == NULL) {
		return;
	}
	inOrder(T->lchild);
	printf("%c", T->data);
	inOrder(T->rchild);
}

//后序遍历--左右根
void postOrder(BiTree T) {
	if (T == NULL) {
		return;
	}
	postOrder(T->lchild);
	postOrder(T->rchild);
	printf("%c", T->data);
}

//非递归遍历--原理就是出栈入栈

int main() {
	BiTree T;
	createTree(&T);
	printf("\n");

	preOrder(T);
	printf("\n");

	inOrder(T);
	printf("\n");

	postOrder(T);
	printf("\n");




	system("pause");
	return 0;
}