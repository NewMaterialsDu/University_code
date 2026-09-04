
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define MAXSIZE 100

typedef int ElemType;

//队列的顺序结构，动态内存分布,循环队列
typedef struct {
	ElemType* data;
	int front;
	int rear;
}Queue;

//初始化
Queue* initQueue() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->data = (ElemType*)malloc(sizeof(ElemType));
	q->front = 0;
	q->rear = 0;
	return q;
}

//入队:这个判断满的方式有bug，当只有一个空位时，会被判断满
//但是如果最后一个位置也装上元素，然后指针向后移一位，两个指针就会重叠，这样的话，就无法判断队列是满还是空
//对于这个问题，常见的替代方案是：1.加一个count储存队列中的元素个数 或者 2.加一个tag记录上一次的操作是入队还是出队，
// 每次入队就让tag=true，出队就让他为false，当front==rear时，看tag，tag==0则为空，tag==1则为满
int equeue(Queue* Q, ElemType e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front) {
		printf("满了\n");
		return 0;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 1;
}

//出队：
int dequeue(Queue* Q, ElemType* e) {
	if (Q->front == Q->rear) {
		printf("空的\n");
		return 0;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return 1;
}

//获取对头元素：
int getHead(Queue* Q, ElemType* e) {
	if (Q->front == Q->rear) {
		printf("空的\n");
		return 0;
	}
	*e = Q->data[Q->front];
	return 1;
}

int main() {
	Queue* q = initQueue();
	equeue(q, 10);
	equeue(q, 20);
	equeue(q, 30);
	equeue(q, 40);
	equeue(q, 50);

	ElemType e;
	dequeue(q, &e);
	printf("%d\n", e);
	dequeue(q, &e);
	printf("%d\n", e);

	getHead(q, &e);
	printf("%d\n", e);


	system("pause");
	return 0;
}