#include <stdio.h>
#include <stdlib.h>

// 链表结点定义
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 合并两个升序链表（带头结点），返回合并后的链表头指针
LinkList Merge(LinkList A, LinkList B) {
    // 健壮性处理：如果其中一个为空，直接返回另一个（并释放空链表的头结点？）
    // 但为了保持统一，这里保留原逻辑；如果 A 或 B 为空，while 不会执行，直接接上非空链表。
    // 注意：调用者应确保 A 和 B 都是带头结点的链表，且数据部分升序。

    LNode *pa = A->next;      // A 的第一个数据结点
    LNode *pb = B->next;      // B 的第一个数据结点
    LNode *pc = A;            // pc 指向合并后链表的尾结点（初始为 A 的头结点）

    // 1. 轮流比较，将较小结点链接到 pc 后面
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }

    // 2. 当某一条链表遍历完，将另一条剩余的结点直接接上
    //    这里用 if-else 简化，实际上若 pa 非空则接 pa，否则接 pb（可能为 NULL）
    pc->next = (pa != NULL) ? pa : pb;

    // 3. 释放 B 的头结点（因为 B 的头结点不再使用）
    free(B);

    // 4. 返回 A 的头结点作为新链表的头
    return A;
}

// 辅助函数：创建带头结点的链表（从数组构建）
LinkList CreateList(int arr[], int n) {
    LinkList head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL;
    LNode *tail = head;
    for (int i = 0; i < n; i++) {
        LNode *newNode = (LNode*)malloc(sizeof(LNode));
        newNode->data = arr[i];
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

// 辅助函数：打印链表（带头结点，跳过头结点）
void PrintList(LinkList L) {
    LNode *p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 辅助函数：释放链表（释放所有结点，包括头结点）
void FreeList(LinkList L) {
    LNode *p = L;
    while (p) {
        LNode *tmp = p;
        p = p->next;
        free(tmp);
    }
}

// 主函数测试
int main() {
    int arrA[] = {1, 3, 5, 7, 9};
    int arrB[] = {2, 4, 6, 8, 10};
    LinkList A = CreateList(arrA, 5);
    LinkList B = CreateList(arrB, 5);

    printf("A: ");
    PrintList(A);
    printf("B: ");
    PrintList(B);

    LinkList merged = Merge(A, B);  // 合并后 A 的头指针被重用，B 的头结点已释放
    printf("Merged: ");
    PrintList(merged);

    // 释放合并后的链表（注意：B 的头结点已释放，但 B 的数据结点已合并到 merged 中，所以只需释放 merged）
    FreeList(merged);

    return 0;
}