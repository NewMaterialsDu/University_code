#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main02() {
	int a;
	int b;
	int c;
	cout << "请分别输入三只小猪的体重（不能相同）：" << endl;
	cin >> a >> b >> c;
	//cin >> b;
	//cin >> c;
	if (a>b) {
		if (a > c) {
			cout << "小猪a的体重最重！为：" << a << endl;
		}
		else {
			cout << "小猪c的体重最重！为：" << b << endl;
		}
	}
	else if (a>b) {
		if (a > b) {
			cout << "小猪a的体重最重！为：" << a << endl;
		}
		else {
			cout << "小猪b的体重最重！为：" << b << endl;
		}
	}
	else {
		if (b>c) {
			cout << "小猪b的体重最重！为：" << b << endl;

		}
		else {
			cout << "小猪c的体重最重！为：" << c << endl;
		}
	}




	system("pause");
	return 0;
}