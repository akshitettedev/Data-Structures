#include <stdio.h>
#include "MinHeap.h"

int main(void) {
    MinHeap heap;
    int value;
    if (!initializeMinHeap(&heap, 20)) {
        printf("Could not initialize the heap.\n");
        return 1;
    }

    insertMinHeap(&heap, 40);
    insertMinHeap(&heap, 10);
    insertMinHeap(&heap, 30);
    insertMinHeap(&heap, 5);
    printf("Min-heap array: ");
    displayMinHeap(&heap);

    if (peekMinHeap(&heap, &value)) printf("Highest-priority item (minimum): %d\n", value);
    if (extractMinHeap(&heap, &value)) printf("Removed minimum: %d\n", value);
    printf("After extraction: ");
    displayMinHeap(&heap);
    destroyMinHeap(&heap);
    return 0;
}
