#include <stdio.h>
#include <stdlib.h>
#include "MinHeap.h"

static void swap(int* a, int* b) { int temp = *a; *a = *b; *b = temp; }

int initializeMinHeap(MinHeap* heap, int capacity) {
    if (heap == NULL || capacity <= 0) return 0;
    heap->items = (int*)malloc((size_t)capacity * sizeof(int));
    if (heap->items == NULL) {
        heap->size = 0;
        heap->capacity = 0;
        return 0;
    }
    heap->size = 0;
    heap->capacity = capacity;
    return 1;
}

int insertMinHeap(MinHeap* heap, int value) {
    int index;
    if (heap == NULL || heap->items == NULL || heap->size >= heap->capacity) return 0;
    index = heap->size++;
    heap->items[index] = value;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->items[parent] <= heap->items[index]) break;
        swap(&heap->items[parent], &heap->items[index]);
        index = parent;
    }
    return 1;
}

int peekMinHeap(const MinHeap* heap, int* value) {
    if (heap == NULL || value == NULL || heap->size == 0) return 0;
    *value = heap->items[0];
    return 1;
}

int extractMinHeap(MinHeap* heap, int* value) {
    int index = 0;
    if (heap == NULL || value == NULL || heap->size == 0) return 0;
    *value = heap->items[0];
    heap->size--;
    if (heap->size == 0) return 1;
    heap->items[0] = heap->items[heap->size];
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        if (left < heap->size && heap->items[left] < heap->items[smallest]) smallest = left;
        if (right < heap->size && heap->items[right] < heap->items[smallest]) smallest = right;
        if (smallest == index) break;
        swap(&heap->items[index], &heap->items[smallest]);
        index = smallest;
    }
    return 1;
}

void displayMinHeap(const MinHeap* heap) {
    int i;
    if (heap == NULL || heap->size == 0) {
        printf("Heap is empty.\n");
        return;
    }
    for (i = 0; i < heap->size; i++) printf("%d ", heap->items[i]);
    printf("\n");
}

void destroyMinHeap(MinHeap* heap) {
    if (heap == NULL) return;
    free(heap->items);
    heap->items = NULL;
    heap->size = 0;
    heap->capacity = 0;
}
