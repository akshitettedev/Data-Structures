#include<stdio.h>
#include"LinkedList.h"

int main() {
	node* head = NULL;
	node* temp;

	for (int i = 0; i < 10; i++) {
		head = insertAtHead(&head, createNode(i));
	}

	printList(head);

	insertAfterNode(findNode(head,9) ,createNode(67));

	printList(head);

	temp = findNode(head, 5);

	deleteNode(&head,temp);

	printList(head);
}