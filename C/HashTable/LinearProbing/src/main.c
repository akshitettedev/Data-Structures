#include <stdio.h>
#include "HashTable.h"

int main(void) {
    HashTable table;
    int index;
    initializeHashTable(&table);
    insertHash(&table, 22);
    insertHash(&table, 33); /* Collision: both initially map to slot 0. */
    insertHash(&table, 44);
    insertHash(&table, 18);
    displayHashTable(&table);

    index = searchHash(&table, 33);
    if (index >= 0) printf("Key 33 found at index %d.\n", index);
    if (deleteHash(&table, 33)) printf("Deleted key 33.\n");
    insertHash(&table, 55);
    displayHashTable(&table);
    return 0;
}
