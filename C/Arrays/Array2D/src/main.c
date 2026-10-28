#include <stdio.h>
#include "array2D.h"

int main() {
    IntMatrix myMatrix;

    printf("Enter number of rows: ");
    scanf_s("%d", &myMatrix.row);
    printf("Enter number of columns: ");
    scanf_s("%d", &myMatrix.col);

    createMatrix(&myMatrix);
    fillMatrix(&myMatrix);
    printMatrix(&myMatrix);
    freeMatrix(&myMatrix);

    return 0;
}