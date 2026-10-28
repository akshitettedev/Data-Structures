#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ExpressionTree.h"

static int isOperator(char value) {
    return value == '+' || value == '-' || value == '*' || value == '/' || value == '^';
}

static ExpressionNode* createExpressionNode(char value) {
    ExpressionNode* node = (ExpressionNode*)malloc(sizeof(ExpressionNode));
    if (node == NULL) return NULL;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

ExpressionNode* buildExpressionTree(const char* postfix) {
    ExpressionNode* stack[256];
    int top = -1;
    size_t i;
    if (postfix == NULL) return NULL;
    for (i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];
        ExpressionNode* node;
        if (isspace((unsigned char)token)) continue;
        node = createExpressionNode(token);
        if (node == NULL) goto fail;
        if (isOperator(token)) {
            if (top < 1) { free(node); goto fail; }
            node->right = stack[top--];
            node->left = stack[top--];
        } else {
            if (!isalnum((unsigned char)token) || top >= 254) { free(node); goto fail; }
        }
        if (top >= 254) { freeExpressionTree(node); goto fail; }
        stack[++top] = node;
    }
    if (top != 0) goto fail;
    return stack[top];

fail:
    while (top >= 0) freeExpressionTree(stack[top--]);
    printf("Invalid postfix expression or expression too long.\n");
    return NULL;
}

void preorderExpression(const ExpressionNode* root) {
    if (root == NULL) return;
    printf("%c ", root->value);
    preorderExpression(root->left);
    preorderExpression(root->right);
}
void inorderExpression(const ExpressionNode* root) {
    if (root == NULL) return;
    if (isOperator(root->value)) printf("(");
    inorderExpression(root->left);
    printf("%c", root->value);
    inorderExpression(root->right);
    if (isOperator(root->value)) printf(")");
}
void postorderExpression(const ExpressionNode* root) {
    if (root == NULL) return;
    postorderExpression(root->left);
    postorderExpression(root->right);
    printf("%c ", root->value);
}
void freeExpressionTree(ExpressionNode* root) {
    if (root == NULL) return;
    freeExpressionTree(root->left); freeExpressionTree(root->right); free(root);
}
