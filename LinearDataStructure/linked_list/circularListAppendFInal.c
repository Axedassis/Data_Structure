#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

Node* createNode(int value)
{
	Node* node = (Node *)malloc(sizeof(Node));
	if(node == NULL)
	{
		printf("Unable to allocated memory");
		exit (EXIT_FAILURE);
	}
	node->data = value;
	node->next = NULL;
	
	return (node);
}

Node* insertAtEnd(Node* tail, int value)
{
	Node *newNode = createNode(value);
	if(tail == NULL)
	{
		tail = newNode;
		newNode->next = newNode;
		return (tail);
	}
	newNode->next = tail->next;
	tail->next = newNode;
	//trocando o ponteiro para realmente apontar para o novo tail
	tail = newNode;
	
	return (tail); 
}

void printList(Node* node)
{
	if (node == NULL)
		return ;
	Node *last = node ->next;
	while(1)
	{
		printf("%d ", last->data);
		last = last->next;
		if(last == node->next) break;
	}
}

int main(int argc, char const *argv[])
{
	Node *first = createNode(2);
	first->next = createNode(3);
	first->next->next = createNode(4);

	Node *last = first->next->next;
	last->next = first;

	printf("Original list: ");
	printList(last);

	// Insert elements at the end of the circular linked list
	last = insertAtEnd(last, 5);
	last = insertAtEnd(last, 6);

	printf("List after inserting 5 and 6: ");
	printList(last);
	return 0;
}
