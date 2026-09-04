
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

//栈的顺序结构,就是一个特殊的线性表，先进后出
#define MAXSIZE 100
typedef int ElemType;

typedef struct {
	ElemType * data;
	int top;//表示栈顶的下标
}stack;

//栈的初始化
stack * initstack() {
	stack* s = (stack*)malloc(sizeof(stack));
	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	s->top = -1;
	return s;
}

//判断栈是否为空
int isEmpty(stack* s) {
	if (s->top == -1) {
		printf("空的\n");
		return 1;
	}
	else {
		return 0;
	}
}

//进栈/压栈
int push(stack* s, ElemType e) {
	if (s->top >= MAXSIZE - 1) {
		printf("满了\n");
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}

//出栈
ElemType pop(stack* s, ElemType* e) {
	if (s->top == -1) {
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}

//获取栈顶元素
int getTop(stack* s, ElemType* e) {
	if (s->top == -1) {
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];
	return 1;
}

//

int main() {

	stack *s=initstack();
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