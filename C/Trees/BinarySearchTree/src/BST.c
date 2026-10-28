#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

BSTNode* createBSTNode(int key) {
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BSTNode* insertBST(BSTNode* root, int key) {
    if (root == NULL) return createBSTNode(key);
    if (key < root->key) root->left = insertBST(root->left, key);
    else if (key > root->key) root->right = insertBST(root->right, key);
    /* Duplicate keys are ignored to keep each key unique. */
    return root;
}

BSTNode* searchBST(BSTNode* root, int key) {
    while (root != NULL) {
        if (key == root->key) return root;
        root = key < root->key ? root->left : root->right;
    }
    return NULL;
}

static BSTNode* minimumBST(BSTNode* root) {
    while (root != NULL && root->left != NULL) root = root->left;
    return root;
}

BSTNode* deleteBST(BSTNode* root, int key) {
    BSTNode* successor;
    if (root == NULL) return NULL;
    if (key < root->key) root->left = deleteBST(root->left, key);
    else if (key > root->key) root->right = deleteBST(root->right, key);
    else {
        if (root->left == NULL) {
            BSTNode* right = root->right;
            free(root);
            return right;
        }
        if (root->right == NULL) {
            BSTNode* left = root->left;
            free(root);
            return left;
        }
        successor = minimumBST(root->right);
        root->key = successor->key;
        root->right = deleteBST(root->right, successor->key);
    }
    return root;
}

void inorderBST(const BSTNode* root) {
    if (root == NULL) return;
    inorderBST(root->left); printf("%d ", root->key); inorderBST(root->right);
}
void preorderBST(const BSTNode* root) {
    if (root == NULL) return;
    printf("%d ", root->key); preorderBST(root->left); preorderBST(root->right);
}
void postorderBST(const BSTNode* root) {
    if (root == NULL) return;
    postorderBST(root->left); postorderBST(root->right); printf("%d ", root->key);
}

int countBSTNodes(const BSTNode* root) {
    if (root == NULL) return 0;
    return 1 + countBSTNodes(root->left) + countBSTNodes(root->right);
}

void levelOrderBST(const BSTNode* root) {
    int capacity, front = 0, rear = 0;
    BSTNode** queue;
    if (root == NULL) { printf("Tree is empty.\n"); return; }
    capacity = countBSTNodes(root);
    queue = (BSTNode**)malloc((size_t)capacity * sizeof(BSTNode*));
    if (queue == NULL) { printf("Could not allocate traversal queue.\n"); return; }
    queue[rear++] = (BSTNode*)root;
    while (front < rear) {
        BSTNode* current = queue[front++];
        printf("%d ", current->key);
        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }
    free(queue);
}

int heightBST(const BSTNode* root) {
    int leftHeight, rightHeight;
    if (root == NULL) return 0;
    leftHeight = heightBST(root->left);
    rightHeight = heightBST(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void freeBST(BSTNode* root) {
    if (root == NULL) return;
    freeBST(root->left);
    freeBST(root->right);
    free(root);
}
