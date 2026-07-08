#include<stdio.h>
#include<stdlib.h>
#include"array2D.h"

void createMatrix(IntMatrix* mat) {
    if (mat == NULL) return;
    
    mat->data = calloc(mat->row * mat->col, sizeof(int));
    mat->rowindex = calloc(mat->row, sizeof(int*));

    if (mat->data == NULL || mat->rowindex == NULL) return;

    for (int i = 0; i < mat->row; i++) {
        mat->rowindex[i] = &(mat->data[i * mat->col]);
    }
}

void fillMatrix(IntMatrix* mat) {
    if (mat == NULL || mat->data == NULL || mat->rowindex == NULL) {
        printf("Matrix not initialized!\n");
        return;
    }

    printf("Enter values for a %dx%d matrix:\n", mat->row, mat->col);
    for (int r = 0; r < mat->row; r++) {
        for (int c = 0; c < mat->col; c++) {
            printf("Element [%d][%d]: ", r, c);
            scanf_s("%d", &mat->rowindex[r][c]);
        }
    }
}

void printMatrix(const IntMatrix* mat) {
    if (mat == NULL || mat->data == NULL || mat->rowindex == NULL) {
        printf("Matrix is empty or uninitialized.\n");
        return;
    }

    printf("\nYour Matrix (%dx%d):\n", mat->row, mat->col);
    for (int r = 0; r < mat->row; r++) {
        for (int c = 0; c < mat->col; c++) {
            printf("%d\t", mat->rowindex[r][c]);
        }
        printf("\n");
    }
}

void freeMatrix(IntMatrix* mat) {
    if (mat == NULL) return;

    if (mat->data != NULL) {
        free(mat->data);
        mat->data = NULL;
    }

    if (mat->rowindex != NULL) {
        free(mat->rowindex);
        mat->rowindex = NULL;
    }

    mat->row = 0;
    mat->col = 0;
}