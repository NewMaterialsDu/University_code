
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

//栈的链式结构
typedef int ElemType;

typedef struct stack {
	ElemType data;
	struct stack* next;
}Stack;

//初始化
stack* initstack() {
	stack* s = (stack*)malloc(sizeof(stack));
	s->data = 0;
	s->next = NULL;
	return s;
}

//判断栈是否为空
int isEmpty(stack* s) {
	if (s->next = NULL) {
		printf("空的\n");
		return 1;
	}
	else {
		return 0;
	}
}

//进栈/压栈
int push(stack* s, ElemType e) {
	stack* p = (stack*)malloc(sizeof(stack));
	p->data = e;
	p->next = s->next;
	s->next = p;
	return 1;
}

//出栈
int pop(stack* s, ElemType* e) {
	if (s->next == NULL) {
		printf("空的\n");
		return 0;
	}
	*e = s->next->data;
	stack* q = s->next;
	s->next = q->next;
	free(q);
	return 1;
}

//获取栈顶元素
int getTop(stack* s, ElemType* e) {
	if (s->next == NULL) {
		printf("空的\n");
		return 0;
	}
	*e = s->next->data;
	return 1;
}

int main() {
	stack* s = initstack();
	push(s, 10);
	push(s, 20);
	push(s, 30);
	ElemType e;
	pop(s, &e);
	printf("%d\n", e);
	getTop(s, &e);
	printf("%d\n", e);



	system("pause");
	return 0;
}