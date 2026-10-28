#include<stdio.h>
#include"DoublyLinkedList.h"

int main(){
    node* head = NULL;
    node* temp;
    int n, t;

    printf("Enter number of elements in the List : ");
    scanf("%d",&n);

    for(int i = 1; i <= n; i++){
        printf("Enter the value of %d element : ",i);
        scanf("%d",&t);
        temp = createNode(t);
        insertAtHead(&head, temp);
    }

    printList(head);

    printf("Enter the value you want to find : ");
    scanf("%d",&n);

    temp = findNode(head, n);

    if(temp == NULL){
        printf("Value not Found\n");
    }
    else {
        printf("Value Found\n");
    }

    printf("Enter the node you want to delete : ");
    scanf("%d", &n);

    deleteNode(&head, findNode(head, n));

    printList(head);

    return 0;
}