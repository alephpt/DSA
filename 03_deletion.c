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

struct Node* findPrev(struct Node* current)
{
	return current->prev;
}

struct Node* findNext(struct Node* current)
{
	return current->next;
}

struct Node* findValue(struct Node** head_r, char* q_data)
{
	struct Node *cursor = *head_r;
	while (cursor != NULL){
		if (cursor->data == *q_data){
			return cursor;
		} else {
			cursor = cursor->next;
		}
	}
	printf("Requested Value not found in List using findValue.");
}

struct Node* findIndex(struct Node** head_r, int i_data)
{
	struct Node *cursor = *head_r;
	while (cursor != NULL){
		if (cursor->index == i_data){
			return cursor;
		} else {
			cursor = cursor->next;
		}
	}
	printf("Index not found in List using findIndex.");
}

/*
struct Node* findNode(struct Node* base)
{
	struct Node *search_n 
}
*/

void incrementFollowing(struct Node* increase)
{
	// set index to the node we want to increase from
	struct Node *temp = increase->next;
	while (temp != NULL){
		temp->index = temp->index + 1;
		temp = temp->next;		
	}
}

void decrementFollowing(struct Node* decrease)
{
	// set index to the node we want to increase from
	struct Node *temp = decrease->next;
	while (temp != NULL){
		temp->index = temp->index - 1;
		temp = temp->next;		
	}
}



int pushValue(struct Node** head_r, char* new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	

	new_node->prev = NULL;
	new_node->index = 0;		// set index to 0
	new_node->data = *new_data;	// push new data
	
	if(*head_r != NULL){		// if the head is not null
		new_node->next = (*head_r);	// set new.next to current.head
		(*head_r)->prev = new_node;	// set head.prev to new
		incrementFollowing(new_node);   // increment index of following nodes
	}

	(*head_r) = new_node;		// set current head to new node

	return 0;
}

int appendValue(struct Node** head_r, char* new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *head_r;

	new_node->data = *new_data;
	new_node->next = NULL;

	if (*head_r == NULL)
	{
		*head_r = new_node;
		return 0;
	}

	while (last->next != NULL)
		last = last->next;

	new_node->prev = last;
	new_node->index = last->index + 1;
	last->next = new_node;
	return 0;
}

int insertAfter(struct Node* prev_n, char* new_data)
{
	if (prev_n == NULL)
	{
		printf("the given previous node cannot be NULL");
		return 1;
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
	return 0;
}

int insertBefore(struct Node* next_n, char* new_data)
{
	if (next_n == NULL){
		printf("The given next node cannot be null.");
		return 1;
	}

	if (next_n->prev == NULL) {
		pushValue(&next_n, new_data);
		return 0;
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
	return 0;
}

int deleteNode(struct Node* del_n){
	struct Node* prev_n = del_n->prev;
	struct Node* next_n = del_n->next;
	prev_n->next = next_n;
	next_n->prev = prev_n;
	decrementFollowing(del_n);
	return 0;
}

void printL(struct Node *node)
{
	while (node != NULL){
		printf("%d - %c\n", node->index, node->data);
		node = node->next;
	}
}

void prompt_opts(){
	// prompt user for input options
	printf("\n\t\tWELCOME TO DICK'S LIST BUILDER\n\n");
	printf("\tOptions:\n"); 
	printf("\t push \t\t - Insert Value at the Head of the List.\n"); 			// option 1
	printf("\t append \t - Insert Value at the end of the List.\n"); 			// option 2
	printf("\t insert \t - Inserts Value after a specified Value or at a Certain Index.\n");// option 3
	printf("\t delete \t - Deletes a Specified Value from the List.\n");			// option 4
	printf("\t exit \t\t - Exits the program.\n");
	printf("\nWhat would you like to do? "); 
}


int input_loop(struct Node* head_r)
{
	char func_i[7]; // options (push, append, insert, delete, exit)
	char val_i[5]; // input values
	char exit[4] = "exit";
	char push[4] = "push";
	char append[6] = "append";
	char insert[6] = "insert";
	char delete[6] = "delete";
	char * t;
	int scan_input = 0;
	int option = 0;


	// check for user input
	while (scan_input == 0){
		// prompt user for input
		prompt_opts();
		scanf("%s", func_i);

		// check for exit loop
		for (int i = 0; i < 4; i++){
			if (func_i[i] == exit[i]) {
				scan_input =  1;
				// printf("comparitor succeeded\n");
			} else {
				// printf("exit failed\n");
				scan_input = 0;
				break;
			}
		}

		if (scan_input == 1) { return scan_input; };

	
		// check for push
		for (int i = 0; i < 4; i++){
			// check push string to input
			if(push[i] == func_i[i]){
				// printf("comparitor match\n");
				option = 1; // if it's a match - op1
			} else { 
				// printf("comparitor mismatch\n");
				option = 0; // set option to 0 if it's not a match
				break; // and exit
			}
		}
		
		if (option == 1) { 
			// printf("Op1 worked!");
			scan_input = 1; // kill loop if it's a match 
			break;  // and exit
		};
			
		// check for append
		for (int i = 0; i < 6; i++){
			// check append string to input
			if(append[i] == func_i[i]){
				// printf("comparitor match\n");
				option = 2; // if it's a match - op2
			} else { 
				// printf("comparitor mismatch\n");
				option = 0; // set option to 0 if it's not a match
				break; // and exit
			}
		}
		
		if (option == 2) { 
			// printf("Op2 worked!");
			scan_input = 1; // kill loop if it's a match 
			break;  // and exit
		};
		
		// check for insert
		for (int i = 0; i < 6; i++){
			// check insert string to input
			if(insert[i] == func_i[i]){
				// printf("comparitor match\n");
				option = 3; // if it's a match - op3
			} else { 
				// printf("comparitor mismatch\n");
				option = 0; // set option to 0 if it's not a match
				break; // and exit
			}
		}
		
		if (option == 3) { 
			// printf("Op3 worked!");
			scan_input = 1; // kill loop if it's a match 
			break;  // and exit
		};

		// check for delete
		for (int i = 0; i < 6; i++){
			// check delete string to input
			if(delete[i] == func_i[i]){
				// printf("comparitor match\n");
				option = 4; // if it's a match - op4
			} else { 
				// printf("comparitor mismatch\n");
				option = 0; // set option to 0 if it's not a match
				break; // and exit
			}
		}
		
		if (option == 4) { 
			// printf("Op4 worked!");
			scan_input = 1; // kill loop if it's a match 
			break;  // and exit
		};

		printf("\nInvalid Input: \n - %s is not a valid option. Please try again. ", func_i);
	
	}

	switch(option){
		case 0:
			printf("This shouldn't happen.");
			break;
		case 1: // push
			printf("What value would you like to push?");
			scanf("%s", val_i);
			
			if(pushValue(&head_r, val_i) == 0){
				printf("%s pushed.", val_i);
			} else {
				printf("pushing %s failed", val_i);
			}

			printL(head_r);
			break;
		case 2: // append
			printf("What value would you like to append?");
			scanf("%s", val_i);
			
			if(appendValue(&head_r, val_i) == 0){
				printf("%s appended.", val_i);
			} else {
				printf("appending %s failed.", val_i);
			}

			printL(head_r);
			break;
		case 3: // insert
			printf("What value would you like to insert?");
			scanf("%s", val_i);
			break;
		case 4: // delete
			printf("What value would you like to delete?");
			scanf("%s", val_i);
			if(deleteNode(findValue(&head_r, val_i)) == 0){
				printf("%s deleted", val_i);
			} else {
				printf("deleting %s failed.", val_i);
			}

			printL(head_r);
			break;
		default:
			printf("Undefined Behaviour.");
	}

	return 0;
}

int main()
{
	struct Node* head = NULL;
	
	while(input_loop(head) == 0){};

/*
	append(&head, "D");
	push(&head, "B");
	push(&head, "A");
	append(&head, "E");

	insertAfter(findValue(&head, "B"), "C");

	append(&head, "G");
	insertBefore(findValue(&head, "G"), "F");

	printf("Linked List contains: \n");
	printL(head);

	printf("\nLeng: %d \n", Llength(head));

	deleteNode(findValue(&head, "B"));

	printf("\nLinked List contains: \n");
	printL(head);

	return 0;
*/
}