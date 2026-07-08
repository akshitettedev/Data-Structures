#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

node* createNode(int value) {
	node* result;
	result = calloc(1,sizeof(node));
	if (result == NULL) return NULL;
	result->value = value;
	result->next = NULL;
	return result;
}

node* insertAtHead(node** head, node* node_to_insert) {
	node_to_insert->next = *head;
	*head = node_to_insert;
	return node_to_insert;
}

void insertAfterNode(node* node_to_insert_after, node* new_node) {
	new_node->next = node_to_insert_after->next;
	node_to_insert_after->next = new_node;
}

node* findNode(node* head, int value) {
	node* temp = head;

	while (temp != NULL) {
		if (temp->value == value) {
			return temp;
		}
		temp = temp->next;
	}

	return NULL;
}

void printList(node* head) {
	node* temp = head;

	while (temp != NULL) {
		printf("%d -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL\n");
}

void deleteNode(node** head, node* node_to_delete) {
	if (head == NULL || *head == NULL || node_to_delete == NULL) return;

	if (*head == node_to_delete) {
		*head = node_to_delete->next; 
		node_to_delete->next = NULL;
		free(node_to_delete);
		return;
	}

	node* temp = *head;

	while (temp->next != NULL && temp->next != node_to_delete) {
		temp = temp->next; 
	}

	if (temp->next == node_to_delete) {
		temp->next = node_to_delete->next;
		node_to_delete->next = NULL;
		free(node_to_delete);
	}
}