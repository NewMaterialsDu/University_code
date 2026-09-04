#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
	//continue 语句 ：跳过本次循环未执行的语句，执行下一次循环

	for (int i = 0; i <= 100; i++) {
		//只输出奇数，不输出偶数
		if (i%2==0) {
			continue;
		}
		cout << i << endl;

	}

	cout << "1. xxx" << endl;
	goto FLAG;
	cout << "2. xxx" << endl;
	cout << "3. xxx" << endl;
	cout << "4. xxx" << endl;
	cout << "5. xxx" << endl;
	FLAG:
	cout << "6. xxx" << endl;
	cout << "7. xxx" << endl;
	cout << "8. xxx" << endl;


	system("pause");
	return 0;
}