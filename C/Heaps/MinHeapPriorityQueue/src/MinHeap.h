#pragma once

typedef struct {
    int* items;
    int size;
    int capacity;
} MinHeap;

int initializeMinHeap(MinHeap* heap, int capacity);
int insertMinHeap(MinHeap* heap, int value);
int peekMinHeap(const MinHeap* heap, int* value);
int extractMinHeap(MinHeap* heap, int* value);
void displayMinHeap(const MinHeap* heap);
void destroyMinHeap(MinHeap* heap);
