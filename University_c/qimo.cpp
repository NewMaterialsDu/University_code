#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct riqi {
	int nian;
	int yue;
	int ri;
};
struct student {
	char mingzi[15];
	char banji[15];
	int xuehao;
};
struct riqi demo1[50];
struct student shu[50];
void input_i() {
	printf("请输入要编入的学生信息数（1-50）：\n");
	int n = 0;
	scanf_s("%d", &n);

	if (n < 1 || n > 50) {
		printf("输入错误，请输入1-50之间的数！\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		printf("请输入学生的班级：\n");
		scanf_s("%s", shu[i].banji, 15);
		printf("请输入学生的姓名：\n");
		scanf_s("%s", shu[i].mingzi, 15);
		printf("请输入学生的学号：\n");
		scanf_s("%d", &shu[i].xuehao);
		printf("请输入学生的的生日（年）：\n");
		scanf_s("%d", &demo1[i].nian);
		printf("请输入学生的的生日（月）：\n");
		scanf_s("%d", &demo1[i].yue);
		printf("请输入学生的的生日（日）：\n");
		scanf_s("%d", &demo1[i].ri);
		printf("学生信息录入成功！\n");

	}


}
void xuigai() {
	printf("请选择要通过哪种方式修改学生信息（0.返回 1.姓名 2.班级 3.学号 4.生日）：\n");
	int choice = 0;
	scanf_s("%d", &choice);
	switch (choice) {
	case 0:
		return;
	case 1: {
		char name[15];
		printf("请输入要修改的学生姓名：\n");
		scanf_s("%s", name, 15);
		int found = 0;
		for (int i = 0; i < 50; i++) {
			if (strcmp(shu[i].mingzi, name) == 0) {
				found = 1;
				printf("找到学生：姓名：%s 班级：%s 学号：%d 生日：%d年%d月%d日\n", shu[i].mingzi, shu[i].banji, shu[i].xuehao, demo1[i].nian, demo1[i].yue, demo1[i].ri);
				printf("请选择要修改的项（1.姓名 2.班级 3.学号 4.生日 0.取消）：\n");
				int opt = 0;
				scanf_s("%d", &opt);
				if (opt == 1) {
					printf("请输入新的姓名：\n");
					scanf_s("%s", shu[i].mingzi, 15);
					printf("修改成功！\n");
				} else if (opt == 2) {
					printf("请输入新的班级：\n");
					scanf_s("%s", shu[i].banji, 15);
					printf("修改成功！\n");
				} else if (opt == 3) {
					printf("请输入新的学号：\n");
					scanf_s("%d", &shu[i].xuehao);
					printf("修改成功！\n");
				} else if (opt == 4) {
					printf("请输入新的生日（年）：\n");
					scanf_s("%d", &demo1[i].nian);
					printf("请输入新的生日（月）：\n");
					scanf_s("%d", &demo1[i].yue);
					printf("请输入新的生日（日）：\n");
					scanf_s("%d", &demo1[i].ri);
					printf("修改成功！\n");
				} else {
					printf("取消修改。\n");
				}
				break;
			}
			
		}
		if (!found) printf("未找到该学生信息！\n");
		break;
	}
	case 2: {
		char ban[15];
		printf("请输入要修改的学生班级：\n");
		scanf_s("%s", ban, 15);
		int found = 0;
		for (int i = 0; i < 50; i++) {
			if (strcmp(shu[i].banji, ban) == 0) {
				//比较字符串是否相等，相等返回0
				found = 1;
				printf("找到学生：姓名：%s 班级：%s 学号：%d 生日：%d年%d月%d日\n", shu[i].mingzi, shu[i].banji, shu[i].xuehao, demo1[i].nian, demo1[i].yue, demo1[i].ri);
				printf("请选择要修改的项（1.姓名 2.班级 3.学号 4.生日 0.取消）：\n");
				int opt = 0;
				scanf_s("%d", &opt);
				if (opt == 1) {
					printf("请输入新的姓名：\n");
					scanf_s("%s", shu[i].mingzi, 15);
					printf("修改成功！\n");
				} else if (opt == 2) {
					printf("请输入新的班级：\n");
					scanf_s("%s", shu[i].banji, 15);
					printf("修改成功！\n");
				} else if (opt == 3) {
					printf("请输入新的学号：\n");
					scanf_s("%d", &shu[i].xuehao);
					printf("修改成功！\n");
				} else if (opt == 4) {
					printf("请输入新的生日（年）：\n");
					scanf_s("%d", &demo1[i].nian);
					printf("请输入新的生日（月）：\n");
					scanf_s("%d", &demo1[i].yue);
					printf("请输入新的生日（日）：\n");
					scanf_s("%d", &demo1[i].ri);
					printf("修改成功！\n");
				} else {
					printf("取消修改。\n");
				}
				break;
			}
		}
		if (!found) { printf("未找到该学生信息！\n"); };
		break;
	}
	case 3: {
		printf("请输入要修改的学生的学号：\n");
		int m = 0;
		scanf_s("%d", &m);
		int found = 0;
		for (int i = 0; i < 50; i++) {
			if (shu[i].xuehao == m) {
				found = 1;
				printf("找到学生：姓名：%s 班级：%s 学号：%d 生日：%d年%d月%d日\n", shu[i].mingzi, shu[i].banji, shu[i].xuehao, demo1[i].nian, demo1[i].yue, demo1[i].ri);
				printf("请选择要修改的项（1.姓名 2.班级 3.学号 4.生日 0.取消）：\n");
				int opt = 0;
				scanf_s("%d", &opt);
				if (opt == 1) {
					printf("请输入新的姓名：\n");
					scanf_s("%s", shu[i].mingzi, 15);
					printf("修改成功！\n");
				} else if (opt == 2) {
					printf("请输入新的班级：\n");
					scanf_s("%s", shu[i].banji, 15);
					printf("修改成功！\n");
				} else if (opt == 3) {
					printf("请输入新的学号：\n");
					scanf_s("%d", &shu[i].xuehao);
					printf("修改成功！\n");
				} else if (opt == 4) {
					printf("请输入新的生日（年）：\n");
					scanf_s("%d", &demo1[i].nian);
					printf("请输入新的生日（月）：\n");
					scanf_s("%d", &demo1[i].yue);
					printf("请输入新的生日（日）：\n");
					scanf_s("%d", &demo1[i].ri);
					printf("修改成功！\n");
				} else {
					printf("取消修改。\n");
				}
				break;
			}
		}
		if (!found) printf("未找到该学生信息！\n");
		break;
	}
	case 4: {
		int year, month, day;
		printf("请输入要修改的生日（年）：\n");
		scanf_s("%d", &year);
		printf("请输入要修改的生日（月）：\n");
		scanf_s("%d", &month);
		printf("请输入要修改的生日（日）：\n");
		scanf_s("%d", &day);
		int found = 0;
		for (int i = 0; i < 50; i++) {
			if (demo1[i].nian == year && demo1[i].yue == month && demo1[i].ri == day) {
				found = 1;
				printf("找到学生：姓名：%s 班级：%s 学号：%d 生日：%d年%d月%d日\n", shu[i].mingzi, shu[i].banji, shu[i].xuehao, demo1[i].nian, demo1[i].yue, demo1[i].ri);
				printf("请选择要修改的项（1.姓名 2.班级 3.学号 4.生日 0.取消）：\n");
				int opt = 0;
				scanf_s("%d", &opt);
				if (opt == 1) {
					printf("请输入新的姓名：\n");
					scanf_s("%s", shu[i].mingzi, 15);
					printf("修改成功！\n");
				} else if (opt == 2) {
					printf("请输入新的班级：\n");
					scanf_s("%s", shu[i].banji, 15);
					printf("修改成功！\n");
				} else if (opt == 3) {
					printf("请输入新的学号：\n");
					scanf_s("%d", &shu[i].xuehao);
					printf("修改成功！\n");
				} else if (opt == 4) {
					printf("请输入新的生日（年）：\n");
					scanf_s("%d", &demo1[i].nian);
					printf("请输入新的生日（月）：\n");
					scanf_s("%d", &demo1[i].yue);
					printf("请输入新的生日（日）：\n");
					scanf_s("%d", &demo1[i].ri);
					printf("修改成功！\n");
				} else {
					printf("取消修改。\n");
				}
				break;
			}
		}
		if (!found) printf("未找到该学生信息！\n");
		break;
	}
	default:
		printf("无效选项\n");
		break;
	}
}
void chazhao() {
	printf("请选择要输入的学生关键信息（0.返回 1.输入姓名 2.输入班级 3.输入学号 4.输入生日）：\n");
	int i = 0;
	scanf_s("%d", &i);
	switch (i) {
	case 1:{
		char name[15];
		printf("请输入学生姓名：\n");
		scanf_s("%s", name, 15);
		for (int i = 0; i < 50; i++) {
			if (strcmp(shu[i].mingzi, name) == 0) {
				printf("姓名：%s\n", shu[i].mingzi);
				printf("班级：%s\n", shu[i].banji);
				printf("学号：%d\n", shu[i].xuehao);
				printf("生日：%d年%d月%d日\n", demo1[i].nian, demo1[i].yue, demo1[i].ri);
				break;
			}
			else {
				printf("未找到该学生信息！\n");
				break;
			}
		}

		break;
	}
	case 2:{
		char ban[15];
		printf("请输入学生的班级：\n");
		scanf_s("%s", ban, 15);
		for (int i = 0; i < 50; i++) {
			if (strcmp(shu[i].banji, ban) == 0) {
				printf("姓名：%s\n", shu[i].mingzi);
				printf("班级：%s\n", shu[i].banji);
				printf("学号：%d\n", shu[i].xuehao);
				printf("生日：%d年%d月%d日\n", demo1[i].nian, demo1[i].yue, demo1[i].ri);
				break;
			}
			else {
				printf("未找到该学生信息！\n");
				break;
			}
		}
		break;
	}
	case 3: {
		printf("请输入要查找的学生的学号：\n");
		int m = 0;
		scanf_s("%d", &m);
		for (int i = 0; i < 50; i++)
		{
			if (shu[i].xuehao == m)
			{
				printf("姓名：%s\n", shu[i].mingzi);
				printf("班级：%s\n", shu[i].banji);
				printf("学号：%d\n", shu[i].xuehao);
				printf("生日：%d年%d月%d日\n", demo1[i].nian, demo1[i].yue, demo1[i].ri);
				break;
			}
			else {
				printf("未找到该学生信息！\n");
				break;
			}
		}
		break;
	}
	case 4: {
		int year, month, day;
		printf("请输入生日（年）：\n");
		scanf_s("%d", &year);
		
		printf("请输入生日（月）：\n");
		scanf_s("%d", &month);
		printf("请输入生日（日）：\n");
		scanf_s("%d", &day);
		for (int i = 0; i < 50; i++) {
			if (demo1[i].nian == year && demo1[i].yue == month && demo1[i].ri == day) {
				printf("===== 找到匹配学生 =====\n");
				printf("姓名：%s\n", shu[i].mingzi);
				printf("班级：%s\n", shu[i].banji);
				printf("学号：%d\n", shu[i].xuehao);
				printf("生日：%d年%d月%d日\n", demo1[i].nian, demo1[i].yue, demo1[i].ri);
				break;
			}
			else {
				printf("未找到该学生信息！\n");
				break;
			}
		}
		break;
	}


	}
}
int main() {

	while (1) {
		printf("欢迎回来，管理员！\n");
		printf("请输入要执行的操作（0.退出 1.录入学生信息 2.查询学生信息 3.修改学生信息）：\n");
		int a = 0;
		scanf_s("%d", &a);

		if (a == 1) {
			input_i();
		}
		else if (a == 2) {
			chazhao();
		}
		else if (a == 3) {
			xuigai();
		}
		else if (a == 0) {
			printf("退出程序，欢迎下次使用！\n");
			break;
		}
		else {

			printf("输入有误，请输入0、1或2！\n");
		}
	}
	return 0;
}
