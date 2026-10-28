typedef struct node {
	int value;
	struct node* next;
	struct node* prev;
}node;

node* createNode(int value);
void printList(node* head);
void insertAtHead(node** head, node* node_to_insert);
node* findNode(node* head, int value);
void insertAfterNode(node* node_to_insert_after, node* new_node);
void deleteNode(node** head, node* node_to_delete);