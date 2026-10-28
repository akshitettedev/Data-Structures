#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

void initializeLinkedStack(LinkedStack* stack) {
    if (stack != NULL) stack->top = NULL;
}
int isLinkedStackEmpty(const LinkedStack* stack) { return stack == NULL || stack->top == NULL; }

int pushLinkedStack(LinkedStack* stack, int value) {
    StackNode* node;
    if (stack == NULL) return 0;
    node = (StackNode*)malloc(sizeof(StackNode));
    if (node == NULL) { printf("Memory allocation failed!\n"); return 0; }
    node->value = value;
    node->next = stack->top;
    stack->top = node;
    return 1;
}

int popLinkedStack(LinkedStack* stack, int* value) {
    StackNode* oldTop;
    if (stack == NULL || value == NULL || stack->top == NULL) {
        printf("Stack underflow!\n"); return 0;
    }
    oldTop = stack->top;
    *value = oldTop->value;
    stack->top = oldTop->next;
    free(oldTop);
    return 1;
}

int peekLinkedStack(const LinkedStack* stack, int* value) {
    if (stack == NULL || value == NULL || stack->top == NULL) return 0;
    *value = stack->top->value;
    return 1;
}

void displayLinkedStack(const LinkedStack* stack) {
    const StackNode* current;
    if (isLinkedStackEmpty(stack)) { printf("Stack is empty.\n"); return; }
    printf("Top -> ");
    current = stack->top;
    while (current != NULL) { printf("%d -> ", current->value); current = current->next; }
    printf("NULL\n");
}

void destroyLinkedStack(LinkedStack* stack) {
    StackNode* current;
    if (stack == NULL) return;
    current = stack->top;
    while (current != NULL) {
        StackNode* next = current->next;
        free(current);
        current = next;
    }
    stack->top = NULL;
}
