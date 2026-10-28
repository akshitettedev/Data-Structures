#include <stdio.h>
#include "Queue.h"

void initializeQueue(Queue* queue) {
    if (queue == NULL) return;
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

int isQueueEmpty(const Queue* queue) { return queue == NULL || queue->count == 0; }
int isQueueFull(const Queue* queue) { return queue != NULL && queue->rear == QUEUE_CAPACITY - 1; }

int enqueue(Queue* queue, int value) {
    if (queue == NULL || isQueueFull(queue)) {
        printf("Queue overflow! (This linear queue does not reuse freed positions.)\n");
        return 0;
    }
    queue->items[++queue->rear] = value;
    queue->count++;
    return 1;
}

int dequeue(Queue* queue, int* value) {
    if (queue == NULL || value == NULL || isQueueEmpty(queue)) {
        printf("Queue underflow!\n");
        return 0;
    }
    *value = queue->items[queue->front++];
    queue->count--;
    if (queue->count == 0) {
        queue->front = 0;
        queue->rear = -1;
    }
    return 1;
}

int queueFront(const Queue* queue, int* value) {
    if (queue == NULL || value == NULL || isQueueEmpty(queue)) return 0;
    *value = queue->items[queue->front];
    return 1;
}

void displayQueue(const Queue* queue) {
    int i;
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front -> ");
    for (i = queue->front; i <= queue->rear; i++) printf("%d ", queue->items[i]);
    printf("<- Rear\n");
}
