#pragma once

typedef struct BSTNode {
    int key;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* createBSTNode(int key);
BSTNode* insertBST(BSTNode* root, int key);
BSTNode* searchBST(BSTNode* root, int key);
BSTNode* deleteBST(BSTNode* root, int key);
void inorderBST(const BSTNode* root);
void preorderBST(const BSTNode* root);
void postorderBST(const BSTNode* root);
void levelOrderBST(const BSTNode* root);
int countBSTNodes(const BSTNode* root);
int heightBST(const BSTNode* root);
void freeBST(BSTNode* root);
