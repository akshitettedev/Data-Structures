#include <stdio.h>
#include "Stack.h"

int main(void) {
    Stack stack;
    int value;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    displayStack(&stack);

    if (peek(&stack, &value)) printf("Top element: %d\n", value);
    if (pop(&stack, &value)) printf("Popped: %d\n", value);
    displayStack(&stack);
    return 0;
}
