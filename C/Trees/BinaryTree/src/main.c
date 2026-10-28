#include <stdio.h>
#include "BinaryTree.h"

int main(void) {
    /* Preorder encoding: value, left subtree, right subtree; -1 means NULL. */
    const int values[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;
    BinaryTreeNode* root = buildTreeFromPreorder(values, (int)(sizeof(values) / sizeof(values[0])), &index, -1);

    printf("Preorder: "); preorderTraversal(root); printf("\n");
    printf("Inorder: "); inorderTraversal(root); printf("\n");
    printf("Postorder: "); postorderTraversal(root); printf("\n");
    printf("Level order (BFS): "); levelOrderTraversal(root); printf("\n");
    printf("Number of nodes: %d\n", countTreeNodes(root));

    freeBinaryTree(root);
    return 0;
}
