/**
 * 迭代法（层序遍历）计算二叉树层高
 * 使用数组模拟队列，固定最大容量（可调整）
 * 空树高度为0
 * 编译：gcc height_iterative.c -o height_iterative
 * 运行：./height_iterative
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 1000  // 队列最大容量，根据实际节点数调整

 // 二叉树节点结构
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新节点
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        fprintf(stderr, "内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 迭代计算层高（BFS）
int getHeightIterative(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    // 用数组模拟循环队列（存储节点指针）
    TreeNode* queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;

    queue[rear++] = root;   // 根节点入队
    int height = 0;

    while (front < rear) {
        int levelSize = rear - front;   // 当前层的节点数
        height++;                       // 每处理一层，高度加1

        // 遍历当前层所有节点，并将其子节点入队
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = queue[front++];
            if (node->left != NULL) {
                queue[rear++] = node->left;
            }
            if (node->right != NULL) {
                queue[rear++] = node->right;
            }
        }
    }
    return height;
}

// 测试主函数
int main() {
    // 构建测试树：
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int h = getHeightIterative(root);
    printf("迭代法计算层高: %d\n", h);  // 期望输出 3

    // 测试空树
    printf("空树层高 (迭代): %d\n", getHeightIterative(NULL)); // 输出 0

    // 释放内存（此处省略，实际项目需遍历释放）
    return 0;
}