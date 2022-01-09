#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int index;
	char data;
	struct Node *next;
	struct Node *prev;
};

int Llength(struct Node* list)
{
	int count = 0;
	while (list != NULL){
		list = list->next;
		count++;
	}
	return count;
}

struct Node* findNode(struct Node** head_r, char* q_data)
{
	struct Node *cursor = *head_r;
	while (cursor != NULL){
		if (cursor->data == *q_data){
			return cursor;
		} else {
			cursor = cursor->next;
		}
	}
	printf("Requested Value not found in List using findNode.");
}

struct Node* findHead(struct Node* current)
{
	while(current->prev != NULL){
		current = current->prev;
	}
	return current;
}

struct Node* findTail(struct Node* current)
{
	while(current->next != NULL){
		current = current->next;
	}
	return current;
}

void incrementFollowing(struct Node* increase)
{
	// set index to the node we want to increase from
	int increment = increase->index;
	struct Node *temp = increase->next;
	while (temp != NULL){
		increment = increment + 1;
		temp->index = increment;
		temp = temp->next;		
	}
}

void decrementFollowing(struct Node* decrease)
{
	// set index to the node we want to increase from
	int decrement = decrease->index;
	struct Node *temp = decrease->next;
	while (temp != NULL){
		decrement = decrement - 1;
		temp->index = decrement;
		temp = temp->next;		
	}
}

void push(struct Node** head_r, char* new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	
	new_node->prev = NULL;
	new_node->index = 0;		// set index to 0
	new_node->data = *new_data;	// push new data
	new_node->next = (*head_r);	// set next to head
	(*head_r)->prev = new_node;	// set prev of head to new
	(*head_r) = new_node;		// set current head to new
	incrementFollowing(new_node);   // increment index of following 
}

void append(struct Node** head_r, char* new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *head_r;

	new_node->data = *new_data;
	new_node->next = NULL;

	if (*head_r == NULL)
	{
		*head_r = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	new_node->prev = last;
	new_node->index = last->index + 1;
	last->next = new_node;
	return;
}

void insertAfter(struct Node* prev_n, char* new_data)
{
	if (prev_n == NULL)
	{
		printf("the given previous node cannot be NULL");
		return;
	}

	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data  = *new_data;	// set data of new
	new_node->next = prev_n->next;	// set next to the prev next
	new_node->prev = prev_n;
	prev_n->next = new_node;	// set next of prev to current
	struct Node *next_n = new_node->next;		
	next_n->prev = new_node;	// set prev of next to current
	new_node->index = next_n->index;// set index of new node to next index
	incrementFollowing(new_node); 	// increment index after current node
}

void insertBefore(struct Node* next_n, char* new_data)
{
	if (next_n == NULL){
		printf("The given next node cannot be null.");
		return;
	}

	if (next_n->prev == NULL) {
		push(&next_n, new_data);
		return;
	}
	
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = *new_data;
	new_node->prev = next_n->prev;
	new_node->next = next_n;
	next_n->prev = new_node;
	struct Node* prev_n = new_node->prev;
	prev_n->next = new_node;
	new_node->index = next_n->index;
	incrementFollowing(new_node);
}

void printL(struct Node *node)
{
	while (node != NULL){
		printf("%d - %c\n", node->index, node->data);
		node = node->next;
	}
}

int main()
{
	struct Node* head = NULL;
	append(&head, "D");
	push(&head, "B");
	push(&head, "A");
	append(&head, "E");

	insertAfter(findNode(&head, "B"), "C");

	append(&head, "G");
	insertBefore(findNode(&head, "G"), "F");

	printf("Linked List contains: \n");
	printL(head);

	printf("\nLeng: %d \n", Llength(head));

	return 0;
}
