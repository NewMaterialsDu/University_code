#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int ElemType;

//typedef char ElemType;

//声明一个结构体（节点），包含数据域和指针域，节点连在一起就是链表
typedef struct node {
	ElemType data;
	struct node* next;
	//双向链表
	struct node* prev;
}Node;

//初始化
Node* initList() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	head->prev = NULL;
	return head;
}

//头插法
int insertHead(Node* L, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->prev = L;
	p->next = L->next;
	if (L->next != NULL) {
		L->next->prev = p;
	}
	L->next = p;
	return 1;
}

//遍历
void listNode(Node* L) {
	Node* p = L->next;
	while (p != NULL) {
		printf("%d\n", p->data);//注意，数据域变的时候，占位符也要变
		p = p->next;
	}
	printf("\n");
}

//遍历获取尾节点地址
Node* get_tail(Node* L) {
	Node* p = L;//因为要返回最后一个节点的信息，所以要创建一个p让L赋值（L传的是地址，用L本身遍历就会把原来的链表改变了)
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}

//尾插法
Node* insertTail(Node* tail, ElemType e) {
    Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->prev = tail;
	tail->next = p;
	p->next = NULL;
	return p;
}

//在指定位置插入
int insertNode(Node* L, int pos, ElemType e) {
	Node* p = L;//指针传入，不能直接使用，会改变原来的值
	//遍历获取pos前的尾节点地址
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == NULL) {
			printf("插入位置错误！\n");
			return 0;//p为空时链表已经到头
		}
	}
	//当成一个尾插法
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
    q->prev = p;
	q->next = p->next;
	if (p->next != NULL) {
		p->next->prev = q;
	}
	p->next = q;
	return 1;
}

//删除节点
int deleteNode(Node* L, int pos) {
	Node* p = L;//指针传入，不能直接使用，会改变原来的值
	//遍历获取pos前的尾节点地址
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == NULL) {
			printf("插入位置错误！\n");
			return 0;//p为空时链表已经到头
		}
	}
	if (p->next == NULL) {
		printf("要删除的位置错误！\n");
		return 0;
	}
	Node* q = p->next;
	p->next = q->next;
	if (q->next != NULL) {
		q->next->prev = p;
	}
	free(q);
	return 1;
}




int main() {
	
	Node* list = initList();
	
	////头插法
	insertHead(list, 10);
	insertHead(list, 20);
	insertHead(list, 30);
	listNode(list);//遍历

	//尾插法
	Node* tail = get_tail(list);
	tail = insertTail(tail, 10);
	tail = insertTail(tail, 20);
	tail = insertTail(tail, 30);
	listNode(list);

	//插入指定位置
	insertNode(list, 4, 15);
	listNode(list);

	//删除指定节点
	deleteNode(list,7);
	listNode(list);
	return 0;
}