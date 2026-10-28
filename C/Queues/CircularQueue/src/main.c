#include <stdio.h>
#include "CircularQueue.h"

int main(void) {
    CircularQueue queue;
    int value;
    initializeCircularQueue(&queue);
    enqueueCircular(&queue, 10);
    enqueueCircular(&queue, 20);
    enqueueCircular(&queue, 30);
    displayCircularQueue(&queue);
    if (dequeueCircular(&queue, &value)) printf("Dequeued: %d\n", value);
    enqueueCircular(&queue, 40);
    displayCircularQueue(&queue);
    return 0;
}
