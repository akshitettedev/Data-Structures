#pragma once

typedef struct ExpressionNode {
    char value;
    struct ExpressionNode* left;
    struct ExpressionNode* right;
} ExpressionNode;

ExpressionNode* buildExpressionTree(const char* postfix);
void preorderExpression(const ExpressionNode* root);
void inorderExpression(const ExpressionNode* root);
void postorderExpression(const ExpressionNode* root);
void freeExpressionTree(ExpressionNode* root);
