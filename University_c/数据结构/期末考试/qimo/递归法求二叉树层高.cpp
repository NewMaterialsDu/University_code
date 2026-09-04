/**
 * 递归法计算二叉树层高（节点数定义）
 * 空树高度为0，只有根节点高度为1
 * 编译：gcc height_recursive.c -o height_recursive
 * 运行：./height_recursive
 */

#include <stdio.h>
#include <stdlib.h>

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

// 递归计算层高
int getHeightRecursive(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getHeightRecursive(root->left);
    int rightHeight = getHeightRecursive(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 测试主函数
int main06() {
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

    int h = getHeightRecursive(root);
    printf("递归法计算层高: %d\n", h);  // 期望输出 3

    // 测试空树
    printf("空树层高 (递归): %d\n", getHeightRecursive(NULL)); // 输出 0

    // 释放内存（此处省略，实际项目需遍历释放）
    return 0;
}