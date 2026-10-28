#include <stdio.h>
#include "Stack.h"

void initializeStack(Stack* stack) {
    if (stack != NULL) stack->top = -1;
}

int isStackEmpty(const Stack* stack) {
    return stack == NULL || stack->top == -1;
}

int isStackFull(const Stack* stack) {
    return stack != NULL && stack->top == STACK_CAPACITY - 1;
}

int push(Stack* stack, int value) {
    if (stack == NULL || isStackFull(stack)) {
        printf("Stack overflow!\n");
        return 0;
    }
    stack->items[++stack->top] = value;
    return 1;
}

int pop(Stack* stack, int* value) {
    if (stack == NULL || value == NULL || isStackEmpty(stack)) {
        printf("Stack underflow!\n");
        return 0;
    }
    *value = stack->items[stack->top--];
    return 1;
}

int peek(const Stack* stack, int* value) {
    if (stack == NULL || value == NULL || isStackEmpty(stack)) return 0;
    *value = stack->items[stack->top];
    return 1;
}

void displayStack(const Stack* stack) {
    int i;
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top -> ");
    for (i = stack->top; i >= 0; i--) printf("%d ", stack->items[i]);
    printf("\n");
}
