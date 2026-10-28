#include <stdio.h>
#include "BST.h"

int main(void) {
    BSTNode* root = NULL;
    int values[] = {30, 20, 10, 15, 25, 23, 39, 35, 42};
    int i;

    for (i = 0; i < (int)(sizeof(values) / sizeof(values[0])); i++)
        root = insertBST(root, values[i]);

    printf("Inorder (sorted order): "); inorderBST(root); printf("\n");
    printf("Preorder: "); preorderBST(root); printf("\n");
    printf("Postorder: "); postorderBST(root); printf("\n");
    printf("Level order: "); levelOrderBST(root); printf("\n");
    printf("Node count: %d; height (in nodes): %d\n", countBSTNodes(root), heightBST(root));
    printf("Search for 23: %s\n", searchBST(root, 23) != NULL ? "found" : "not found");

    root = deleteBST(root, 20);
    printf("After deleting 20: "); inorderBST(root); printf("\n");
    freeBST(root);
    return 0;
}
