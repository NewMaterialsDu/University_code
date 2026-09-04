
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

//结构体名可以不写
//typedef struct 结构体名 {


	//}别名;

typedef struct point {
	int x;
	int y;
};
//时间复杂度计算：
//01.
int fun01(int n) {
	int i = 0, sum = 0;
	//下面相当于sum = sum + （++i）
	while (sum < n) sum += ++i;
	return i;
}
//当sum = 1+2+3+...+n时，程序执行完毕，相当于等差数列求和, t*(t+1)/2 = n  所以t = n^1/2
//所以时间复杂度为：O(n^1/2)

//02.
void fun02(int n) {
	int x = 0;
	while (n >= (x + 1) * (x + 1))
		x = x + 1;
}
//当n < （x+1)^2,即：n^1/2 - 1 = x   所以时间复杂度为：O(n^1/2)

//03.
void fun03(int n) {
	int sum = 0;
	for (int i = 1; i < n; i *= 2) {
		for (int j = 0; j < i; j++) {
			sum++;
		}
	}
}
//i<=j时执行完
//i变化：1 2 4 8 16 ... n即：2^0 2^1 2^3 2^4 ... 2^n
//内层执行次数：1 , 2 , 4 , 8 ,16 , .... ,2^n
//即：i = 2^n ，化为：n = log2 i   所以时间复杂度为：O(log2 n)

//空间复杂度
//ADT

int main() {

    char str1 [10];
	/* Use secure version on MSVC to avoid C4996 deprecation error */
	//不能直接赋值，语法：strcpy（str1，str2）把str2的值赋值给str1
	strcpy_s(str1, "hello");
	


    int a = 5;
	//通配指针类型是%p,上述用%d输出的地址实际上不完整，它是将地址的十六进制转换为十进制输出，但%d是输出int，只有4个字节，会超出范围，所以会截断输出，不完整
	printf("%p\n", (void*)&a);
	printf("%d\n", &a);

	//sizeof的是%zu
	printf("%zu\n",sizeof(a));

	//sizeof(变量)
//上述返回的类型是size_t
	int a0=10;
	size_t a1 = sizeof(a0);
	//malloc返回的是一个通配的地址，下面语法为：指针类型 变量名 = （指针类型）malloc（sizeof（数据类型））；
	//void* malloc(size_t);//size_t = sizeof（数据类型）
	//void* 表示通配指针类型
	int* p = (int*)malloc(sizeof(int));
	//释放p中的地址
	free(p);

	char* s = (char*)malloc(10);//这里表示开辟十个字节的内存空间
	//strcpy(s, "hello");//不知道为什么，用strcpy就会报错

	for (int i = 0; i < 10; i++) {
		s[i] = 'h';
	}
	for (int i = 0; i < 10; i++) {
		printf("%c", s[i]);
	}
	free(s);

	//表示开辟5个int型的空间
	int* arr = (int*)malloc(5 * sizeof(int));
	//数组arr
	for (int i = 0; i < 5; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < 5; i++) {
		printf("%d\n", arr[i]);
	}
	free(arr);

	//结构体开辟
	point* q = (point*)malloc(sizeof(point));
	q->x = 10;
	q->y = 5;
	free(q);





	return 0;
}