#pragma once

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} LinkedStack;

void initializeLinkedStack(LinkedStack* stack);
int isLinkedStackEmpty(const LinkedStack* stack);
int pushLinkedStack(LinkedStack* stack, int value);
int popLinkedStack(LinkedStack* stack, int* value);
int peekLinkedStack(const LinkedStack* stack, int* value);
void displayLinkedStack(const LinkedStack* stack);
void destroyLinkedStack(LinkedStack* stack);
