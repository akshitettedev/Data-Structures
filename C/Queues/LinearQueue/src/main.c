#include <stdio.h>
#include "Queue.h"

int main(void) {
    Queue queue;
    int value;
    initializeQueue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    displayQueue(&queue);
    if (dequeue(&queue, &value)) printf("Dequeued: %d\n", value);
    displayQueue(&queue);
    if (queueFront(&queue, &value)) printf("Front element: %d\n", value);
    return 0;
}
