#include<stdio.h>
#include<stdlib.h>
#include<iostream>

//线索二叉树:有空孩子的节点，让他们指向其他节点，形成一个双向链表
//tag为0代表有孩子，ltag为1代表没孩子，左孩子指向前驱，rtag为1时，右孩子指向后继
//具体指向哪个节点要根据遍历方式
//线索化就是遍历出来一个顺序后，根据这个顺序变成一个双向链表
typedef char ElemType;
typedef struct ThreadNode {
	ElemType data;
	ThreadNode* lchild;
	ThreadNode* rchild;
	int ltag;
	int rtag;
}ThreadNode;
typedef ThreadNode* ThreadTree;

char str[] = "ABDH##I##EJ###CF##G##";
int idx = 0;
ThreadTree prev;

//创建树
void createTree(ThreadTree *T) {
	ElemType ch;
	ch = str[idx++];
	if (ch == '#') {
		*T = NULL;
	}
	else {
		//ThreadTree相当于ThreadNode*
		*T = (ThreadTree)malloc(sizeof(ThreadNode));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		if ((*T)->lchild != NULL) {
			(*T)->ltag = 0;
		}

		createTree(&(*T)->rchild);
		if ((*T)->rchild != NULL) {
			(*T)->rtag = 0;
		}
	}
}

//具体线索化
void threading(ThreadTree T) {
	if (T != NULL) {
		threading(T->lchild);
		if (T->lchild == NULL) {
			T->ltag = 1;
			T->lchild = prev;
		}
		// 第一次到这里时，prev一直指向head，在创建head时初始化rchild指向自己，不为空
		if (prev->rchild == NULL) {
			// 返回到D，prev是H，H的右孩子为空
			prev->rtag = 1;
			//H的右线索->D,然后prev变成D
			prev->rchild = T;
		}
		//从左边挖到NULL后，prev变成H
		prev = T;
		threading(T->rchild);
	}
}

//开始线索化
void inOrderThreading(ThreadTree* head, ThreadTree T) {
	//头节点
	*head = (ThreadTree)malloc(sizeof(ThreadNode));
	(*head)->ltag = 0;
	(*head)->rtag = 1;
	//这里head的rchild指向自己
	(*head)->rchild = (*head);
	if (T == NULL) {
		(*head)->lchild = *head;
	}
	else {
		(*head)->lchild = T;
		prev = (*head);
		threading(T);
		//最后一个节点线索化
		prev->rchild = *head;
		prev->rtag = 1;
		//头节点右孩子指向最后一个节点
		(*head)->rchild = prev;
	}
}

//使用线索进行中序遍历
void inOrder(ThreadTree T) {
	ThreadTree curr;
	curr = T->lchild;
	while (curr != T) {
		while (curr->ltag == 0) {
			curr = curr->lchild;
		}
		printf("%c", curr->data);
		while (curr->rtag == 1 && curr->rchild != T) {
			curr = curr->rchild;
			printf("%c", curr->data);
		}
		curr = curr->rchild;
	}
	printf("\n");
}


int main() {
	ThreadTree head;
	ThreadTree T;
	//创建
	createTree(&T);
	//线索化
	inOrderThreading(&head, T);
	//基于线索化遍历
	inOrder(head);




	system("pause");
	return 0;
}