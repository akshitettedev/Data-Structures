#include <stdio.h>
#include "ExpressionTree.h"

int main(void) {
    const char postfix[] = "ab+c*"; /* (a + b) * c */
    ExpressionNode* root = buildExpressionTree(postfix);
    if (root == NULL) return 1;
    printf("Postfix: %s\n", postfix);
    printf("Prefix: "); preorderExpression(root); printf("\n");
    printf("Infix: "); inorderExpression(root); printf("\n");
    printf("Postorder: "); postorderExpression(root); printf("\n");
    freeExpressionTree(root);
    return 0;
}
