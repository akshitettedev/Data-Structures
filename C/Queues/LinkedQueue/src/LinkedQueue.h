#pragma once

typedef struct QueueNode {
    int value;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} LinkedQueue;

void initializeLinkedQueue(LinkedQueue* queue);
int isLinkedQueueEmpty(const LinkedQueue* queue);
int enqueueLinked(LinkedQueue* queue, int value);
int dequeueLinked(LinkedQueue* queue, int* value);
int linkedQueueFront(const LinkedQueue* queue, int* value);
void displayLinkedQueue(const LinkedQueue* queue);
void destroyLinkedQueue(LinkedQueue* queue);
