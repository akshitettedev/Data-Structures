#pragma once

typedef struct BinaryTreeNode {
    int value;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

BinaryTreeNode* createBinaryTreeNode(int value);
BinaryTreeNode* buildTreeFromPreorder(const int values[], int length, int* index, int nullMarker);
void preorderTraversal(const BinaryTreeNode* root);
void inorderTraversal(const BinaryTreeNode* root);
void postorderTraversal(const BinaryTreeNode* root);
void levelOrderTraversal(const BinaryTreeNode* root);
int countTreeNodes(const BinaryTreeNode* root);
void freeBinaryTree(BinaryTreeNode* root);
