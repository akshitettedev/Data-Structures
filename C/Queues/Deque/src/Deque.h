#pragma once
#define DEQUE_CAPACITY 100

typedef struct {
    int items[DEQUE_CAPACITY];
    int front;
    int count;
} Deque;

void initializeDeque(Deque* deque);
int isDequeEmpty(const Deque* deque);
int isDequeFull(const Deque* deque);
int insertFront(Deque* deque, int value);
int insertRear(Deque* deque, int value);
int deleteFront(Deque* deque, int* value);
int deleteRear(Deque* deque, int* value);
int getDequeFront(const Deque* deque, int* value);
int getDequeRear(const Deque* deque, int* value);
void displayDeque(const Deque* deque);
