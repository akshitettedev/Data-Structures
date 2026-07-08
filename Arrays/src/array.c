#include<stdlib.h>
#include"array.h"

void createIntArray(IntArray* arr) {
    if (arr == NULL) return;

    arr->data = calloc(arr->size , sizeof(int));

    // Safety check: Make sure calloc didn't fail
    if (arr->data == NULL) {
        printf("Memory allocation failed!\n");
        arr->size = 0;
    }
}

void fillArray(IntArray* arr) {
    // Safety check: ensure the pointer isn't NULL and memory was allocated
    if (arr == NULL || arr->data == NULL) {
        printf("Array is not initialized!\n");
        return;
    }

    printf("Enter %d integers:\n", arr->size);
    for (int i = 0; i < arr->size; i++) {
        printf("Element [%d]: ", i);
        scanf_s("%d", &arr->data[i]);
    }
}

void printArray(IntArray arr) {
    for (int i = 0; i < arr.size; i++) {
        printf("%d\t", arr.data[i]);
    }
    printf("\n");
}