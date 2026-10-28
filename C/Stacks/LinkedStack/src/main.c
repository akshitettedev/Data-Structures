#include <stdio.h>
#include "LinkedStack.h"

int main(void) {
    LinkedStack stack;
    int value;
    initializeLinkedStack(&stack);
    pushLinkedStack(&stack, 10);
    pushLinkedStack(&stack, 20);
    pushLinkedStack(&stack, 30);
    displayLinkedStack(&stack);
    if (peekLinkedStack(&stack, &value)) printf("Top element: %d\n", value);
    if (popLinkedStack(&stack, &value)) printf("Popped: %d\n", value);
    displayLinkedStack(&stack);
    destroyLinkedStack(&stack);
    return 0;
}
