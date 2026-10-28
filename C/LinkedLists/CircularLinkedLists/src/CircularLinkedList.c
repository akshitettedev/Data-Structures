#include <stdio.h>
#include <stdlib.h>
#include "CircularLinkedList.h"

Node* createNode(int value) {
    Node* result = (Node*)calloc(1, sizeof(Node));
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    result->value = value;
    result->next = result;
    return result;
}

void insertAtHead(Node** head, Node* newNode) {
    Node* tail;
    if (head == NULL || newNode == NULL) return;
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    tail = *head;
    while (tail->next != *head) tail = tail->next;
    newNode->next = *head;
    tail->next = newNode;
    *head = newNode;
}

void insertAtTail(Node** head, Node* newNode) {
    Node* tail;
    if (head == NULL || newNode == NULL) return;
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    tail = *head;
    while (tail->next != *head) tail = tail->next;
    tail->next = newNode;
    newNode->next = *head;
}

void insertAfterNode(Node* nodeToInsertAfter, Node* newNode) {
    if (nodeToInsertAfter == NULL || newNode == NULL) return;
    newNode->next = nodeToInsertAfter->next;
    nodeToInsertAfter->next = newNode;
}

Node* findNode(Node* head, int value) {
    Node* current;
    if (head == NULL) return NULL;
    current = head;
    do {
        if (current->value == value) return current;
        current = current->next;
    } while (current != head);
    return NULL;
}

int deleteValue(Node** head, int value) {
    Node* current;
    Node* previous;
    if (head == NULL || *head == NULL) return 0;

    current = *head;
    previous = *head;
    while (previous->next != *head) previous = previous->next;

    do {
        if (current->value == value) {
            if (current->next == current) {
                *head = NULL;
            } else {
                previous->next = current->next;
                if (current == *head) *head = current->next;
            }
            free(current);
            return 1;
        }
        previous = current;
        current = current->next;
    } while (current != *head);
    return 0;
}

void printList(Node* head) {
    Node* current;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    current = head;
    do {
        printf("%d -> ", current->value);
        current = current->next;
    } while (current != head);
    printf("(back to head)\n");
}

void freeList(Node** head) {
    Node* current;
    Node* next;
    if (head == NULL || *head == NULL) return;
    current = (*head)->next;
    while (current != *head) {
        next = current->next;
        free(current);
        current = next;
    }
    free(*head);
    *head = NULL;
}
