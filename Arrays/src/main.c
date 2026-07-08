#include<stdio.h>
#include"array.h"

int main() {
	IntArray arr;

	printf("Enter the number of elements in the array : ");
	scanf_s("%d",&arr.size);

	createIntArray(&arr);
	fillArray(&arr);
	printArray(arr);

	return 0;
}