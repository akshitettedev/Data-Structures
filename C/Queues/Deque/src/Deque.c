#include <stdio.h>
#include "Deque.h"

void initializeDeque(Deque* deque) {
    if (deque == NULL) return;
    deque->front = 0;
    deque->count = 0;
}
int isDequeEmpty(const Deque* deque) { return deque == NULL || deque->count == 0; }
int isDequeFull(const Deque* deque) { return deque != NULL && deque->count == DEQUE_CAPACITY; }

int insertFront(Deque* deque, int value) {
    if (deque == NULL || isDequeFull(deque)) return 0;
    deque->front = (deque->front - 1 + DEQUE_CAPACITY) % DEQUE_CAPACITY;
    deque->items[deque->front] = value;
    deque->count++;
    return 1;
}

int insertRear(Deque* deque, int value) {
    int rear;
    if (deque == NULL || isDequeFull(deque)) return 0;
    rear = (deque->front + deque->count) % DEQUE_CAPACITY;
    deque->items[rear] = value;
    deque->count++;
    return 1;
}

int deleteFront(Deque* deque, int* value) {
    if (deque == NULL || value == NULL || isDequeEmpty(deque)) return 0;
    *value = deque->items[deque->front];
    deque->front = (deque->front + 1) % DEQUE_CAPACITY;
    deque->count--;
    return 1;
}

int deleteRear(Deque* deque, int* value) {
    int rear;
    if (deque == NULL || value == NULL || isDequeEmpty(deque)) return 0;
    rear = (deque->front + deque->count - 1) % DEQUE_CAPACITY;
    *value = deque->items[rear];
    deque->count--;
    return 1;
}

int getDequeFront(const Deque* deque, int* value) {
    if (deque == NULL || value == NULL || isDequeEmpty(deque)) return 0;
    *value = deque->items[deque->front];
    return 1;
}

int getDequeRear(const Deque* deque, int* value) {
    int rear;
    if (deque == NULL || value == NULL || isDequeEmpty(deque)) return 0;
    rear = (deque->front + deque->count - 1) % DEQUE_CAPACITY;
    *value = deque->items[rear];
    return 1;
}

void displayDeque(const Deque* deque) {
    int i;
    if (isDequeEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Front -> ");
    for (i = 0; i < deque->count; i++)
        printf("%d ", deque->items[(deque->front + i) % DEQUE_CAPACITY]);
    printf("<- Rear\n");
}
