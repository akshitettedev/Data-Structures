#pragma once

typedef struct {
	int* data;
	int size;
} IntArray;

void createIntArray(IntArray* arr);
void fillArray(IntArray* arr);
void printArray(IntArray arr);