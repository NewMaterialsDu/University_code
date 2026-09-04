#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

//把int起一个别名ElemTupe
typedef int ElemType;

typedef struct {
	ElemType * data;//储存数据的首地址(像数组一样)
	int length;//储存多少数据
}seqlist;

//动态内存分配地址初始化
seqlist* initlist() {
	seqlist* L = (seqlist*)malloc(sizeof(seqlist));//为顺序表开辟地址，顺序表储存数据的首地址和有多少这样的数据
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);//为储存的数据开辟空间，并把地址返回到顺序表中储存
	L->length = 0;
	return L;
}


//在顺序表最后插入数据
int appendElem(seqlist* L, ElemType e) {
	if (L->length == MAXSIZE) {
		printf("顺序表已满\n");
		return 0;
	}
	L->data[L->length] = e;
	L->length++;
	return 1;
}

//遍历顺序表
void listElem(seqlist* L) {
	for (int i = 0; i < L->length; i++) {
		printf("%d\n", L->data[i]);
	}
	printf("\n");
}

//在顺序表的pos位置插入一个元素
int insertElem(seqlist* L, int pos, ElemType e) {
	if (L->length >= MAXSIZE) {
		printf("表已经满了\n");
		return 0;
	}

	if (pos<1 || pos>L->length) {
		printf("插入位置不合理\n");
		return 0;
	}

	if (pos <= L->length) {
		for (int i = L->length - 1; i >= pos - 1; i--) {
			L->data[i + 1] = L->data[i];
		}
		L->data[pos - 1] = e;
		L->length++;
	}
	return 1;
}

//删除pos位置的元素,*e就是要删除的数据,*e用来返回删了什么
int deleteElem(seqlist* L, int pos, ElemType* e) {
	if (L->length == 0) {
		printf("空表\n");
		return 0;
	}

	if (pos <1 || pos>L->length) {
		printf("删除位置错误\n");
		return 0;
	}

	*e = L->data[pos - 1];
	if (pos < L->length) {
		for (int i = pos; i < L->length; i++) {
			L->data[i - 1] = L->data[i];
		}
	}
	L->length--;
	return 1;

}

//查找数据第一次出现的位置，e为要查找的数据
int findElem(seqlist* L, ElemType e) {
	if (L->length == 0) {
		printf("空列表\n");
		return 0;
	}
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] == e) {
			return i + 1;
		}
	}

	return 1;
}

int main() {


	//声明一个顺序表并初始化,返回顺序表首地址给list
	seqlist * list = initlist();
	printf("初始化成功，目前长度占用%d\n", list->length);
	printf("目前开辟储存元素的首地址为：%zu\n", list->data);
	printf("目前开辟顺序表的首地址为：%zu\n", list);


	appendElem(list, 88);
	appendElem(list, 22);
	appendElem(list, 65);
	appendElem(list, 45);
	listElem(list);
	insertElem(list, 2, 18);
	listElem(list);

	ElemType delData;
	deleteElem(list, 2, &delData);
	printf("被删除的数据为:%d\n", delData);
	listElem(list);

	printf("第一次出现的位置是：%d\n", findElem(list, 65));




	return 0;
}