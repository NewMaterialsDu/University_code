#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
	//二维数组
	int arr[2][3] = { {1,2,3},{4,5,6} };
	cout << arr[0][0] << endl;
	//外层循环控制行，内层循环控制列
	for (int i = 0; i < 2; i++) {
		for(int j=0;j<3;j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;

}
