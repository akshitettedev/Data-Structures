#include <stdio.h>
#include "CircularLinkedList.h"

int main(void) {
    Node* head = NULL;

    insertAtTail(&head, createNode(10));
    insertAtTail(&head, createNode(20));
    insertAtTail(&head, createNode(30));
    printf("Circular linked list: ");
    printList(head);

    if (findNode(head, 20) != NULL) printf("20 was found.\n");
    if (deleteValue(&head, 20)) printf("Deleted 20.\n");
    printf("After deletion: ");
    printList(head);

    freeList(&head);
    return 0;
}
