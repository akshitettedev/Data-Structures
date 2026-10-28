#include <stdio.h>
#include "LinkedQueue.h"

int main(void) {
    LinkedQueue queue;
    int value;
    initializeLinkedQueue(&queue);
    enqueueLinked(&queue, 10);
    enqueueLinked(&queue, 20);
    enqueueLinked(&queue, 30);
    displayLinkedQueue(&queue);
    if (dequeueLinked(&queue, &value)) printf("Dequeued: %d\n", value);
    displayLinkedQueue(&queue);
    destroyLinkedQueue(&queue);
    return 0;
}
