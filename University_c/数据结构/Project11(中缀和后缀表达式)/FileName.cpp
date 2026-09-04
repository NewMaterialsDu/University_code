#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

//枚举，默认值从0开始，以此类推，即mon的默认值为0，wed的默认值为1
//当给mon=1时，那么后面就是从1开始了，即wed为2
//像结构体一样，就是一个复合数据类型，可以typedef起别名，原来的位置可以不写名字
typedef enum weekday{
	mon=1,tue,wed,thu,fri,sat,sun
}weekday;
//就像下面这个一样
//enum bool{
	//false,true
//};

//后缀表达式求值:
//比如：82/2+56*-  \0（相当于一个字符串）
//数值1 符号 数值2 = 结果
//遇到数字就压栈，遇到符号就计算，出栈的第一个数值放在数值2位置，第二个出栈数值放在数值1位置，计算出结果再压栈
#define MAXSIZE 100
typedef int ElemType;

typedef struct {
	ElemType* data;
	int top;
}Stack;

//做这个枚举是为了识别字符串中的类型
//下面分别表示：（，），+，-，*，/，%，\0，数字
typedef enum {
	LEFT_PARE,RIGHT_PARE,
	ADD,SUB,MUL,DIV,MOD,
	EOS,NUM
}contentType;

char expr[] = "82/2+56*-";

//初始化
Stack* initStack() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	s->top = -1;
	return s;
}

//入栈
void push(Stack* s, ElemType data) {
	if (s->top == MAXSIZE) {
		printf("栈已满\n");
	}
	else {
		s->top++;
		s->data[s->top] = data;
	}
}

//出栈
void pop(Stack* s, ElemType *data) {
	if (s->top == -1) {
		printf("栈为空\n");
	}
	else {
		*data = s->data[s->top];
		s->top--;
	}
}

contentType getToken(char* symbol, int* index) {
	*symbol = expr[*index];
	*index = *index + 1;
	switch (*symbol) {
	case '(':
		return LEFT_PARE;
	case ')':
		return RIGHT_PARE;
	case '+':
		return ADD;
	case '-':
		return SUB;
	case '*':
		return MUL;
	case '/':
		return DIV;
	case '%':
		return MOD;
	case '\0':
		return EOS;
	default:
		return NUM;
	}
}

int eval(Stack* s) {
	char symbol;
	int op1, op2;
	int index = 0;
	contentType token;
	token = getToken(&symbol, &index);
	ElemType result;
	while (token != EOS) {
		if (token == NUM) {
			//这里因为字符串是'8'，而栈是int，所以这样'8'-'0'就可以得到数字8
			push(s, symbol - '0');
		}
		else {
			pop(s, &op2);
			pop(s, &op1);
			switch (token) {
			case ADD:
				push(s, op1 + op2);
				break;
			case SUB:
				push(s, op1 - op2);
				break;
			case MUL:
				push(s, op1 * op2);
				break;
			case DIV:
				push(s, op1 / op2);
				break;
			case MOD:
				push(s, op1 % op2);
				break;
			default:
				break;
			}
		}
		token = getToken(&symbol, &index);
	}
	pop(s, &result);
	printf("%d\n", result);
	return 1;
}

//中缀表达式(日常生活写的数学计算)转后缀表达式：
/*按从左到右扫描中缀表达式，遇到不同的元素这样处理：
元素	                 操作
操作数	                 直接输出（放进结果队列）
左括号(                  压入运算符栈
右括号)	                 重复弹出栈顶运算符并输出，直到遇到左括号(，然后把这对括号都丢弃
运算符（ + -× ÷）	     和栈顶运算符比优先级：• 如果栈为空 或 栈顶是(或 当前运算符优先级 大于 栈顶优先级 → 当前运算符入栈• 否则（当前优先级 ≤ 栈顶优先级），反复弹出栈顶运算符并输出，直到满足上述条件，再把当前运算符入栈
扫描结束（\0 ）          把栈中剩下的所有运算符依次弹出输出
*/
char expr01[] = "82/2+56*-";

int print_token(contentType token) {
	switch (token) {
	case ADD:
		printf("+");
		break;
	case SUB:
		printf("-");
		break;
	case MUL:
		printf("*");
		break;
	case DIV:
		printf("/");
		break;
	case MOD:
		printf("%%");
		break;
	default:
		return 0;
	}
	return 1;
}

void postfix(Stack* s) {
	//下面两行数组写的是栈里栈外优先级，这个顺序刚好对应上面枚举，枚举里面的数可以当下标用，因为是数字
	int in_stack[] = { 0,19,12,12,13,13,13,0,0 };
	int out_stack[] = { 20,19,12,12,13,13,13,0,0 };
	contentType token;
	int index = 0;
	//这里预先放一个最低级（0）在栈底
	s->data[0] = EOS;
	s->top = 0;
	char symbol;
	ElemType e;
	token = getToken(&symbol, &index);
	while (token != EOS) {
		if (token == NUM) {
			printf("%c", symbol);
		}
		else if (token == RIGHT_PARE) {
			while (s->data[s->top] != LEFT_PARE) {
				pop(s, &e);
				print_token(contentType(e));
			}
			pop(s, &e);
		}
		else {
			//这个顺序刚好对应上面枚举，枚举里面的数可以当下标用，因为是数字
			while (in_stack[s->data[s->top]] >= out_stack[token]) {
				pop(s, &e);
				print_token(contentType(e));
			}
			push(s, token);
		}
		token = getToken(&symbol, &index);
	}
	while (s->data[s->top] != EOS) {
		pop(s, &e);
		print_token(contentType(e));
	}
}

	int main() {
	
	enum weekday a;
	a = mon;
	weekday b;
	b = tue;
	printf("%d\n",a);
	printf("%d\n", b);

	Stack* s = initStack();
	eval(s);

	Stack* s1 = initStack();
	printf("%s\n", expr01);
	postfix(s1);



	system("pause");
	return 0;
}