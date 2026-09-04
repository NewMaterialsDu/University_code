// zuoye.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//



#include <iostream>
#include <cstdlib>
#include <ctime>

    using namespace std;

    int main01() {
        // 设置随机数种子，确保每次运行生成不同的随机数
        srand(time(0));

        // 生成1到100之间的随机数
        int secretNumber = rand() % 100 + 1;
        int guess;
        int attempts = 0;

        cout << "欢迎来到猜数字游戏!" << endl;
        cout << "我已经想好了一个1到100之间的数字。" << endl;
        cout << "请你猜猜这个数字是多少？" << endl;

        // 循环直到猜对为止
        do {
            cout << "请输入你的猜测: ";
            cin >> guess;
            attempts++; // 每次猜测计数加1

            // 根据猜测结果给出提示
            if (guess > secretNumber) {
                cout << "太大了！再试试小一点的数字。" << endl;
            }
            else if (guess < secretNumber) {
                cout << "太小了！再试试大一点的数字。" << endl;
            }
            else {
                // 猜对了，显示结果
                cout << "恭喜你，猜对了！" << endl;
                cout << "你一共猜了 " << attempts << " 次。" << endl;

                // 根据猜测次数给出评价
                if (attempts <= 5) {
                    cout << "太厉害了！简直是猜数字大师！" << endl;
                }
                else if (attempts <= 10) {
                    cout << "很不错，继续加油！" << endl;
                }
                else {
                    cout << "还可以更好哦，下次试试更少的次数！" << endl;
                }
            }
        } while (guess != secretNumber); // 条件不满足时退出循环

        return 0;
    }




	

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
