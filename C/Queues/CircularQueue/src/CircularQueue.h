#pragma once
#define CIRCULAR_QUEUE_CAPACITY 100

typedef struct {
    int items[CIRCULAR_QUEUE_CAPACITY];
    int front;
    int count;
} CircularQueue;

void initializeCircularQueue(CircularQueue* queue);
int isCircularQueueEmpty(const CircularQueue* queue);
int isCircularQueueFull(const CircularQueue* queue);
int enqueueCircular(CircularQueue* queue, int value);
int dequeueCircular(CircularQueue* queue, int* value);
int circularQueueFront(const CircularQueue* queue, int* value);
void displayCircularQueue(const CircularQueue* queue);
