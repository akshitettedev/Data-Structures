#include <stdio.h>
#include "Deque.h"

int main(void) {
    Deque deque;
    int value;
    initializeDeque(&deque);
    insertRear(&deque, 20);
    insertRear(&deque, 30);
    insertFront(&deque, 10);
    displayDeque(&deque);
    if (deleteRear(&deque, &value)) printf("Removed from rear: %d\n", value);
    if (deleteFront(&deque, &value)) printf("Removed from front: %d\n", value);
    displayDeque(&deque);
    return 0;
}
