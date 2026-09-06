#include<stdio.h>
#include<stdlib.h>
int main03() {
    /*
    for (int i = 1; i <= 4; i++) {
        
        for (int j = 4 - i; j > 0; j--) {
            printf(" ");
        }
        
        for (int k = 0; k < 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
    printf("   *\n");
    printf("   *\n");

    */

    int one;
    printf("请问第一个月兔子生了多少对：\n");
    scanf_s("%d", &one);
    int two = one;
    for (int i=1; i < 20;i++) {
        int hou = one + two;
        printf("%d\n",hou);
        one = two;
        two = hou;
    }
    //printf("%d", hou);





	system("pause");
	return 0;
}
