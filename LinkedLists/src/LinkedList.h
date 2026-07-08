#pragma once

typedef struct {
	int value;
	int* next;
}node;

node* createNode(int value);
void printList(node* head);
node* insertAtHead(node** head, node* node_to_insert);
node* findNode(node* head, int value);
void insertAfterNode(node* node_to_insert_after, node* new_node);
void deleteNode(node** head, node* node_to_delete);
