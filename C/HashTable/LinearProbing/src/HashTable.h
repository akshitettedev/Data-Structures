#pragma once
#define HASH_TABLE_SIZE 11
#define HASH_EMPTY 0
#define HASH_OCCUPIED 1
#define HASH_DELETED 2

typedef struct {
    int key;
    int state;
} HashEntry;

typedef struct {
    HashEntry entries[HASH_TABLE_SIZE];
} HashTable;

void initializeHashTable(HashTable* table);
int insertHash(HashTable* table, int key);
int searchHash(const HashTable* table, int key);
int deleteHash(HashTable* table, int key);
void displayHashTable(const HashTable* table);
