#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BinaryTreeNode* createBinaryTreeNode(int value) {
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (node == NULL) return NULL;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Build from preorder data; nullMarker (for example, -1) represents an empty child. */
BinaryTreeNode* buildTreeFromPreorder(const int values[], int length, int* index, int nullMarker) {
    BinaryTreeNode* root;
    if (values == NULL || index == NULL || *index >= length) return NULL;
    if (values[*index] == nullMarker) {
        (*index)++;
        return NULL;
    }
    root = createBinaryTreeNode(values[*index]);
    (*index)++;
    if (root == NULL) return NULL;
    root->left = buildTreeFromPreorder(values, length, index, nullMarker);
    root->right = buildTreeFromPreorder(values, length, index, nullMarker);
    return root;
}

void preorderTraversal(const BinaryTreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->value);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(const BinaryTreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->value);
    inorderTraversal(root->right);
}

void postorderTraversal(const BinaryTreeNode* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->value);
}

int countTreeNodes(const BinaryTreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countTreeNodes(root->left) + countTreeNodes(root->right);
}

void levelOrderTraversal(const BinaryTreeNode* root) {
    int count, front = 0, rear = 0;
    const BinaryTreeNode** queue;
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    count = countTreeNodes(root);
    queue = (const BinaryTreeNode**)malloc((size_t)count * sizeof(BinaryTreeNode*));
    if (queue == NULL) {
        printf("Could not allocate traversal queue.\n");
        return;
    }
    queue[rear++] = root;
    while (front < rear) {
        const BinaryTreeNode* current = queue[front++];
        printf("%d ", current->value);
        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }
    free(queue);
}

void freeBinaryTree(BinaryTreeNode* root) {
    if (root == NULL) return;
    freeBinaryTree(root->left);
    freeBinaryTree(root->right);
    free(root);
}
