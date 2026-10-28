#pragma once

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value);
void insertAtHead(Node** head, Node* newNode);
void insertAtTail(Node** head, Node* newNode);
void insertAfterNode(Node* nodeToInsertAfter, Node* newNode);
Node* findNode(Node* head, int value);
int deleteValue(Node** head, int value);
void printList(Node* head);
void freeList(Node** head);
