#include <stdio.h>
#include "HashTable.h"

static int hashFunction(int key) {
    int index = key % HASH_TABLE_SIZE;
    return index < 0 ? index + HASH_TABLE_SIZE : index;
}

void initializeHashTable(HashTable* table) {
    int i;
    if (table == NULL) return;
    for (i = 0; i < HASH_TABLE_SIZE; i++) {
        table->entries[i].key = 0;
        table->entries[i].state = HASH_EMPTY;
    }
}

int searchHash(const HashTable* table, int key) {
    int index, checked;
    if (table == NULL) return -1;
    index = hashFunction(key);
    for (checked = 0; checked < HASH_TABLE_SIZE; checked++) {
        const HashEntry* entry = &table->entries[index];
        if (entry->state == HASH_EMPTY) return -1;
        if (entry->state == HASH_OCCUPIED && entry->key == key) return index;
        index = (index + 1) % HASH_TABLE_SIZE;
    }
    return -1;
}

int insertHash(HashTable* table, int key) {
    int index, checked, firstDeleted = -1;
    if (table == NULL) return 0;
    if (searchHash(table, key) >= 0) return 0; /* Duplicate keys are rejected. */
    index = hashFunction(key);
    for (checked = 0; checked < HASH_TABLE_SIZE; checked++) {
        HashEntry* entry = &table->entries[index];
        if (entry->state == HASH_DELETED && firstDeleted < 0) firstDeleted = index;
        if (entry->state == HASH_EMPTY) {
            if (firstDeleted >= 0) entry = &table->entries[firstDeleted];
            entry->key = key;
            entry->state = HASH_OCCUPIED;
            return 1;
        }
        index = (index + 1) % HASH_TABLE_SIZE;
    }
    if (firstDeleted >= 0) {
        table->entries[firstDeleted].key = key;
        table->entries[firstDeleted].state = HASH_OCCUPIED;
        return 1;
    }
    printf("Hash table is full.\n");
    return 0;
}

int deleteHash(HashTable* table, int key) {
    int index = searchHash(table, key);
    if (index < 0) return 0;
    table->entries[index].state = HASH_DELETED; /* Keep the probe chain intact. */
    return 1;
}

void displayHashTable(const HashTable* table) {
    int i;
    if (table == NULL) return;
    printf("Index\tKey\tState\n");
    for (i = 0; i < HASH_TABLE_SIZE; i++) {
        printf("%d\t", i);
        if (table->entries[i].state == HASH_OCCUPIED)
            printf("%d\tOccupied\n", table->entries[i].key);
        else if (table->entries[i].state == HASH_DELETED)
            printf("-\tDeleted marker\n");
        else printf("-\tEmpty\n");
    }
}
