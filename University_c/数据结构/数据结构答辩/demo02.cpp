#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 日期结构体
struct riqi {
    int nian;
    int yue;
    int ri;
};

// 学生节点结构体
struct student_node {
    char mingzi[15];
    char banji[15];
    int xuehao;
    struct riqi birthday;
    struct student_node* next;
};

// 全局链表
struct student_node* head = NULL;

// 录入学生信息
void input_i() {
    printf("请输入要编入的学生信息数（1-50）：\n");
    int n = 0;
    scanf_s("%d", &n);

    if (n < 1 || n > 50) {
        printf("输入错误，请输入1-50之间的数！\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        struct student_node* new_node = (struct student_node*)malloc(sizeof(struct student_node));
        new_node->next = NULL;

        printf("请输入学生的班级：\n");
        scanf_s("%s", new_node->banji, 15);
        printf("请输入学生的姓名：\n");
        scanf_s("%s", new_node->mingzi, 15);
        printf("请输入学生的学号：\n");
        scanf_s("%d", &new_node->xuehao);
        printf("请输入学生的生日（年）：\n");
        scanf_s("%d", &new_node->birthday.nian);
        printf("请输入学生的生日（月）：\n");
        scanf_s("%d", &new_node->birthday.yue);
        printf("请输入学生的生日（日）：\n");
        scanf_s("%d", &new_node->birthday.ri);

        // 尾插法
        if (head == NULL) {
            head = new_node;
        }
        else {
            struct student_node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        printf("学生信息录入成功！\n");
    }
}

// 修改学生信息
void xuigai() {
    printf("请选择要通过哪种方式查找要修改学生信息（0.返回 1.姓名 2.班级 3.学号 4.生日）：\n");
    int choice = 0;
    scanf_s("%d", &choice);
	//用来存储找到的学生
    struct student_node* found = NULL; 

    switch (choice) {
    case 0:
        return;
    case 1: {
        char name[15];
        printf("请输入要修改的学生的姓名：\n");
        scanf_s("%s", name, 15);
        struct student_node* p = head;
        while (p != NULL) {
            if (strcmp(p->mingzi, name) == 0) {
                found = p;
                break;
            }
            p = p->next;
        }
        break;
    }
    case 2: {
        char ban[15];
        printf("请输入要修改的学生的班级：\n");
        scanf_s("%s", ban, 15);
        struct student_node* p = head;
        while (p != NULL) {
            if (strcmp(p->banji, ban) == 0) {
                found = p;
                break;
            }
            p = p->next;
        }
        break;
    }
    case 3: {
        int m = 0;
        printf("请输入要修改的学生的学号：\n");
        scanf_s("%d", &m);
        struct student_node* p = head;
        while (p != NULL) {
            if (p->xuehao == m) {
                found = p;
                break;
            }
            p = p->next;
        }
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
        struct student_node* p = head;
        while (p != NULL) {
            if (p->birthday.nian == year && p->birthday.yue == month && p->birthday.ri == day) {
                found = p;
                break;
            }
            p = p->next;
        }
        break;
    }
    default:
        printf("无效选项\n");
        return;
    }

    if (found == NULL) {
        printf("未找到该学生信息！\n");
        return;
    }

    // 显示找到的学生信息
    printf("找到学生：姓名：%s 班级：%s 学号：%d 生日：%d年%d月%d日\n",
        found->mingzi, found->banji, found->xuehao,
        found->birthday.nian, found->birthday.yue, found->birthday.ri);

    printf("请选择要修改的项（1.姓名 2.班级 3.学号 4.生日 0.取消）：\n");
    int opt = 0;
    scanf_s("%d", &opt);

    switch (opt) {
    case 1:
        printf("请输入新的姓名：\n");
        scanf_s("%s", found->mingzi, 15);
        printf("修改成功！\n");
        break;
    case 2:
        printf("请输入新的班级：\n");
        scanf_s("%s", found->banji, 15);
        printf("修改成功！\n");
        break;
    case 3:
        printf("请输入新的学号：\n");
        scanf_s("%d", &found->xuehao);
        printf("修改成功！\n");
        break;
    case 4:
        printf("请输入新的生日（年）：\n");
        scanf_s("%d", &found->birthday.nian);
        printf("请输入新的生日（月）：\n");
        scanf_s("%d", &found->birthday.yue);
        printf("请输入新的生日（日）：\n");
        scanf_s("%d", &found->birthday.ri);
        printf("修改成功！\n");
        break;
    case 0:
        printf("取消修改。\n");
        break;
    default:
        printf("无效选项\n");
    }
}

// 查询学生信息
void chazhao() {
    printf("请选择要输入的学生关键信息（0.返回 1.输入姓名 2.输入班级 3.输入学号 4.输入生日）：\n");
    int choice = 0;
    scanf_s("%d", &choice);

    struct student_node* p = head;
    // 标记是否找到
    int found_flag = 0;  

    switch (choice) {
    case 0:
        return;
    case 1: {
        char name[15];
        printf("请输入学生姓名：\n");
        scanf_s("%s", name, 15);
        p = head;
        while (p != NULL) {
            if (strcmp(p->mingzi, name) == 0) {
                printf("姓名：%s\n", p->mingzi);
                printf("班级：%s\n", p->banji);
                printf("学号：%d\n", p->xuehao);
                printf("生日：%d年%d月%d日\n", p->birthday.nian, p->birthday.yue, p->birthday.ri);
                found_flag = 1;
                break;
            }
            p = p->next;
        }
        if (!found_flag) printf("未找到该学生信息！\n");
        break;
    }
    case 2: {
        char ban[15];
        printf("请输入学生的班级：\n");
        scanf_s("%s", ban, 15);
        p = head;
        while (p != NULL) {
            if (strcmp(p->banji, ban) == 0) {
                printf("姓名：%s\n", p->mingzi);
                printf("班级：%s\n", p->banji);
                printf("学号：%d\n", p->xuehao);
                printf("生日：%d年%d月%d日\n", p->birthday.nian, p->birthday.yue, p->birthday.ri);
                found_flag = 1;
                break;
            }
            p = p->next;
        }
        if (!found_flag) printf("未找到该学生信息！\n");
        break;
    }
    case 3: {
        int m = 0;
        printf("请输入要查找的学生的学号：\n");
        scanf_s("%d", &m);
        p = head;
        while (p != NULL) {
            if (p->xuehao == m) {
                printf("姓名：%s\n", p->mingzi);
                printf("班级：%s\n", p->banji);
                printf("学号：%d\n", p->xuehao);
                printf("生日：%d年%d月%d日\n", p->birthday.nian, p->birthday.yue, p->birthday.ri);
                found_flag = 1;
                break;
            }
            p = p->next;
        }
        if (!found_flag) printf("未找到该学生信息！\n");
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
        p = head;
        while (p != NULL) {
            if (p->birthday.nian == year && p->birthday.yue == month && p->birthday.ri == day) {
                printf("找到学生：\n");
                printf("姓名：%s\n", p->mingzi);
                printf("班级：%s\n", p->banji);
                printf("学号：%d\n", p->xuehao);
                printf("生日：%d年%d月%d日\n", p->birthday.nian, p->birthday.yue, p->birthday.ri);
                found_flag = 1;
                break;
            }
            p = p->next;
        }
        if (!found_flag) printf("未找到该学生信息！\n");
        break;
    }
    default:
        printf("无效选项\n");
    }
}

// 释放链表内存
void free_list() {
    struct student_node* p = head;
    while (p != NULL) {
        struct student_node* temp = p;
        p = p->next;
        free(temp);
    }
    head = NULL;
}

int main02() {
    while (1) {
        printf("欢迎回来，管理员！\n");
        printf("请输入要执行的操作：\n0.退出\n1.录入学生信息\n2.查询学生信息\n3.修改学生信息\n");
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
            free_list();  
            break;
        }
        else {
            printf("输入有误，请输入0、1或2！\n");
        }
    }
    return 0;
}