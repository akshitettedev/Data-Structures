#pragma once

typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

AVLNode* insertAVL(AVLNode* root, int key);
AVLNode* searchAVL(AVLNode* root, int key);
AVLNode* deleteAVL(AVLNode* root, int key);
void inorderAVL(const AVLNode* root);
void preorderAVL(const AVLNode* root);
void postorderAVL(const AVLNode* root);
int heightAVL(const AVLNode* root);
int balanceFactorAVL(const AVLNode* root);
void freeAVL(AVLNode* root);
