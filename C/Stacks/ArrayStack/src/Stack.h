#pragma once
#define STACK_CAPACITY 100

typedef struct {
    int items[STACK_CAPACITY];
    int top;
} Stack;

void initializeStack(Stack* stack);
int isStackEmpty(const Stack* stack);
int isStackFull(const Stack* stack);
int push(Stack* stack, int value);
int pop(Stack* stack, int* value);
int peek(const Stack* stack, int* value);
void displayStack(const Stack* stack);
