#pragma once
#define QUEUE_CAPACITY 100

typedef struct {
    int items[QUEUE_CAPACITY];
    int front;
    int rear;
    int count;
} Queue;

void initializeQueue(Queue* queue);
int isQueueEmpty(const Queue* queue);
int isQueueFull(const Queue* queue);
int enqueue(Queue* queue, int value);
int dequeue(Queue* queue, int* value);
int queueFront(const Queue* queue, int* value);
void displayQueue(const Queue* queue);
