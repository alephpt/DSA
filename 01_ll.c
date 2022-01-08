#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node* next;
	char data[];
};

void Lprint(struct Node* n)
{
	while (n != NULL) {
		printf("%s \n", n->data);
		n = n->next;
	}
}

int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	head = (struct Node*)malloc(sizeof(struct Node)+6*sizeof(char*));
	second = (struct Node*)malloc(sizeof(struct Node)+8*sizeof(char*));
	third = (struct Node*)malloc(sizeof(struct Node)+9*sizeof(char*));

	head->data[0] = 'F';
	head->data[1] = 'i';
	head->data[2] = 'r';
	head->data[3] = 's';
	head->data[4] = 't';
	head->data[5] = '\0';
	head->next = second;

	second->data[0] = 'S';
	second->data[1] = 'e';
	second->data[2] = 'g';
	second->data[3] = 'u';
	second->data[4] = 'n';
	second->data[5] = 'd';
	second->data[6] = 'a';
	second->data[7] = '\0';
	second->next = third;

	third->data[0] = 'T';
	third->data[1] = 'e';
	third->data[2] = 'r';
	third->data[3] = 't';
	third->data[4] = 'i';
	third->data[5] = 'a';
	third->data[6] = 'r';
	third->data[7] = 'y';
	third->data[8] = '\0';
	third->next = NULL;

	Lprint(head);

	return 0;
}
