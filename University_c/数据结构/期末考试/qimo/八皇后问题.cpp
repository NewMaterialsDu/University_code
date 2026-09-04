#include <stdio.h>

#define N 8

//queens数组用于存储每一行皇后的位置，queens[i]=col表示第i行皇后所在第col列
int queens[N];
//totalSolutions用于统计总的解法数
int totalSolutions = 0;

//绝对值函数
int myAbs(int x) {
    if (x < 0) return -x;
    else return x;
}

//检查当前位置是否安全
int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
		//检查同一列是否有皇后
        if (queens[i] == col) return 0;
		//检查对角线是否有皇后
        if (myAbs(queens[i] - col) == myAbs(i - row)) return 0;
    }
    return 1;
}

void backtrack(int row) {
	//如果所有行都放置了皇后，说明找到了一种解法
    if (row == N) {
        totalSolutions++;
        return;
    }
    for (int col = 0; col < N; col++) {
		//检查当前位置是否安全，安全则放置皇后并继续递归
        if (isSafe(row, col)) {
            queens[row] = col;
            backtrack(row + 1);
        }
    }
}

int main() {
    backtrack(0);
    printf("方案总数：%d\n", totalSolutions);
    return 0;
}