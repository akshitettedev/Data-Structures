#include<stdio.h>
#include<stdlib.h>
#include"DoublyLinkedList.h"

node* createNode(int value){
    node* result;
    result = calloc(1,sizeof(node));

    if(result == NULL) return NULL;

    result->value = value;
    result->next = NULL;
    result->prev = NULL;

    return result;
}

void printList(node* head){
    node* temp = head;

    while(temp != NULL){
        printf("%d <-> ",temp->value);
        temp = temp->next;
    }

    printf("NULL\n");
}

void insertAtHead(node** head, node* node_to_insert){
    if (node_to_insert == NULL) return;
    
    node_to_insert->next = *head;
    node_to_insert->prev = NULL;
    
    if (*head != NULL) {
        (*head)->prev = node_to_insert;
    }

    *head = node_to_insert;
}

node* findNode(node* head, int value){
    node* temp = head;

    while(temp != NULL){
        if(temp->value == value){
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

void insertAfterNode(node* node_to_insert_after, node* new_node){
    if(node_to_insert_after == NULL || new_node == NULL) return;

    new_node->next = node_to_insert_after->next;
    new_node->prev = node_to_insert_after;

    if (node_to_insert_after->next != NULL) {
        node_to_insert_after->next->prev = new_node;
    }

    node_to_insert_after->next = new_node;
}

void deleteNode(node** head, node* node_to_delete){
    if (head == NULL || *head == NULL || node_to_delete == NULL) return;

    if (*head == node_to_delete) {
        *head = node_to_delete->next; 
    }
    
    if (node_to_delete->prev != NULL) {
        node_to_delete->prev->next = node_to_delete->next;
    }

    if (node_to_delete->next != NULL) {
        node_to_delete->next->prev = node_to_delete->prev;
    }

    free(node_to_delete);
}