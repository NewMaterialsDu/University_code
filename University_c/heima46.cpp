#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
	int arr[9] = { 4,2,8,0,5,7,1,3,9 };
	for (int i = 0; i < 9; i++) {
		cout << arr[i] << " " ;
		
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[j + 1] > arr[j]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				
			}
			
		}
		
	}
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << arr[i] << endl;
	}
	return 0;

}
