#pragma once

typedef struct {
	int row;
	int col;
	int** rowindex;
	int* data;
}IntMatrix;

void createMatrix(IntMatrix* mat);
void fillMatrix(IntMatrix* mat);
void printMatrix(const IntMatrix* mat);
void freeMatrix(IntMatrix* mat);