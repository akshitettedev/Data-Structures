#include <stdio.h>
#include "AVLTree.h"

int main(void) {
    AVLNode* root = NULL;
    int values[] = {30, 20, 10, 25, 28, 27, 5, 4, 3, 40, 50};
    int i;

    for (i = 0; i < (int)(sizeof(values) / sizeof(values[0])); i++)
        root = insertAVL(root, values[i]);

    printf("Inorder: "); inorderAVL(root); printf("\n");
    printf("Preorder: "); preorderAVL(root); printf("\n");
    printf("Postorder: "); postorderAVL(root); printf("\n");
    printf("Root: %d, height: %d, balance factor: %d\n",
        root != NULL ? root->key : -1, heightAVL(root), balanceFactorAVL(root));
    printf("Search 28: %s\n", searchAVL(root, 28) != NULL ? "found" : "not found");

    root = deleteAVL(root, 28);
    printf("After deleting 28: "); inorderAVL(root); printf("\n");
    freeAVL(root);
    return 0;
}
