#include <stdio.h>
#include "CircularQueue.h"

void initializeCircularQueue(CircularQueue* queue) {
    if (queue == NULL) return;
    queue->front = 0;
    queue->count = 0;
}

int isCircularQueueEmpty(const CircularQueue* queue) { return queue == NULL || queue->count == 0; }
int isCircularQueueFull(const CircularQueue* queue) { return queue != NULL && queue->count == CIRCULAR_QUEUE_CAPACITY; }

int enqueueCircular(CircularQueue* queue, int value) {
    int rear;
    if (queue == NULL || isCircularQueueFull(queue)) {
        printf("Circular queue overflow!\n");
        return 0;
    }
    rear = (queue->front + queue->count) % CIRCULAR_QUEUE_CAPACITY;
    queue->items[rear] = value;
    queue->count++;
    return 1;
}

int dequeueCircular(CircularQueue* queue, int* value) {
    if (queue == NULL || value == NULL || isCircularQueueEmpty(queue)) {
        printf("Circular queue underflow!\n");
        return 0;
    }
    *value = queue->items[queue->front];
    queue->front = (queue->front + 1) % CIRCULAR_QUEUE_CAPACITY;
    queue->count--;
    return 1;
}

int circularQueueFront(const CircularQueue* queue, int* value) {
    if (queue == NULL || value == NULL || isCircularQueueEmpty(queue)) return 0;
    *value = queue->items[queue->front];
    return 1;
}

void displayCircularQueue(const CircularQueue* queue) {
    int i;
    if (isCircularQueueEmpty(queue)) {
        printf("Circular queue is empty.\n");
        return;
    }
    printf("Front -> ");
    for (i = 0; i < queue->count; i++)
        printf("%d ", queue->items[(queue->front + i) % CIRCULAR_QUEUE_CAPACITY]);
    printf("<- Rear\n");
}
