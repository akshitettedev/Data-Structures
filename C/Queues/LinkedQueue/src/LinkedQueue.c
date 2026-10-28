#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

void initializeLinkedQueue(LinkedQueue* queue) {
    if (queue == NULL) return;
    queue->front = NULL;
    queue->rear = NULL;
}
int isLinkedQueueEmpty(const LinkedQueue* queue) { return queue == NULL || queue->front == NULL; }

int enqueueLinked(LinkedQueue* queue, int value) {
    QueueNode* node;
    if (queue == NULL) return 0;
    node = (QueueNode*)malloc(sizeof(QueueNode));
    if (node == NULL) { printf("Memory allocation failed!\n"); return 0; }
    node->value = value;
    node->next = NULL;
    if (queue->rear == NULL) queue->front = node;
    else queue->rear->next = node;
    queue->rear = node;
    return 1;
}

int dequeueLinked(LinkedQueue* queue, int* value) {
    QueueNode* oldFront;
    if (queue == NULL || value == NULL || queue->front == NULL) {
        printf("Queue underflow!\n"); return 0;
    }
    oldFront = queue->front;
    *value = oldFront->value;
    queue->front = oldFront->next;
    if (queue->front == NULL) queue->rear = NULL;
    free(oldFront);
    return 1;
}

int linkedQueueFront(const LinkedQueue* queue, int* value) {
    if (queue == NULL || value == NULL || queue->front == NULL) return 0;
    *value = queue->front->value;
    return 1;
}

void displayLinkedQueue(const LinkedQueue* queue) {
    const QueueNode* current;
    if (isLinkedQueueEmpty(queue)) { printf("Queue is empty.\n"); return; }
    current = queue->front;
    printf("Front -> ");
    while (current != NULL) { printf("%d -> ", current->value); current = current->next; }
    printf("NULL <- Rear\n");
}

void destroyLinkedQueue(LinkedQueue* queue) {
    QueueNode* current;
    if (queue == NULL) return;
    current = queue->front;
    while (current != NULL) {
        QueueNode* next = current->next;
        free(current);
        current = next;
    }
    queue->front = NULL;
    queue->rear = NULL;
}
