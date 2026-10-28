#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

static int nodeHeight(const AVLNode* node) { return node == NULL ? 0 : node->height; }
int heightAVL(const AVLNode* root) { return nodeHeight(root); }
int balanceFactorAVL(const AVLNode* root) {
    if (root == NULL) return 0;
    return nodeHeight(root->left) - nodeHeight(root->right);
}

static int maxInt(int a, int b) { return a > b ? a : b; }
static AVLNode* createNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    if (node == NULL) { printf("Memory allocation failed!\n"); return NULL; }
    node->key = key;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* middle = x->right;
    x->right = y;
    y->left = middle;
    y->height = 1 + maxInt(nodeHeight(y->left), nodeHeight(y->right));
    x->height = 1 + maxInt(nodeHeight(x->left), nodeHeight(x->right));
    return x;
}

static AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* middle = y->left;
    y->left = x;
    x->right = middle;
    x->height = 1 + maxInt(nodeHeight(x->left), nodeHeight(x->right));
    y->height = 1 + maxInt(nodeHeight(y->left), nodeHeight(y->right));
    return y;
}

static AVLNode* balanceNode(AVLNode* node) {
    int balance;
    if (node == NULL) return NULL;
    node->height = 1 + maxInt(nodeHeight(node->left), nodeHeight(node->right));
    balance = balanceFactorAVL(node);

    if (balance > 1 && balanceFactorAVL(node->left) >= 0) return rotateRight(node); /* LL */
    if (balance > 1 && balanceFactorAVL(node->left) < 0) { /* LR */
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && balanceFactorAVL(node->right) <= 0) return rotateLeft(node); /* RR */
    if (balance < -1 && balanceFactorAVL(node->right) > 0) { /* RL */
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

AVLNode* insertAVL(AVLNode* root, int key) {
    if (root == NULL) return createNode(key);
    if (key < root->key) root->left = insertAVL(root->left, key);
    else if (key > root->key) root->right = insertAVL(root->right, key);
    else return root; /* Ignore duplicate keys. */
    return balanceNode(root);
}

AVLNode* searchAVL(AVLNode* root, int key) {
    while (root != NULL) {
        if (root->key == key) return root;
        root = key < root->key ? root->left : root->right;
    }
    return NULL;
}

static AVLNode* minimumNode(AVLNode* root) {
    while (root != NULL && root->left != NULL) root = root->left;
    return root;
}

AVLNode* deleteAVL(AVLNode* root, int key) {
    if (root == NULL) return NULL;
    if (key < root->key) root->left = deleteAVL(root->left, key);
    else if (key > root->key) root->right = deleteAVL(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            AVLNode* child = root->left != NULL ? root->left : root->right;
            free(root);
            return child;
        } else {
            AVLNode* successor = minimumNode(root->right);
            root->key = successor->key;
            root->right = deleteAVL(root->right, successor->key);
        }
    }
    return balanceNode(root);
}

void inorderAVL(const AVLNode* root) {
    if (root == NULL) return;
    inorderAVL(root->left); printf("%d ", root->key); inorderAVL(root->right);
}
void preorderAVL(const AVLNode* root) {
    if (root == NULL) return;
    printf("%d ", root->key); preorderAVL(root->left); preorderAVL(root->right);
}
void postorderAVL(const AVLNode* root) {
    if (root == NULL) return;
    postorderAVL(root->left); postorderAVL(root->right); printf("%d ", root->key);
}
void freeAVL(AVLNode* root) {
    if (root == NULL) return;
    freeAVL(root->left); freeAVL(root->right); free(root);
}
