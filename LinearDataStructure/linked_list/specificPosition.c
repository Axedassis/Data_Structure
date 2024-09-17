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

Node* insertAtPosition(Node *last, int value, unsigned int psc)
{
	if(last == NULL)
	{
		if(psc != 1)
		{
			printf("Invalid position!\n");
			return last;
		}
		Node *newNode = createNode(value);
		newNode->next = newNode;
		last = newNode;
		return (last);
	}
	Node *newNode = createNode(value); //new node
	Node *curr = last->next; //first node

	if(psc == 1)
	{
		newNode->next = curr;
		last->next = newNode;
		return last;
	}

	for (int i = 1; i < psc - 1; i++)
	{
		curr = curr->next;

		if(curr == last->next)
		{
			printf("Invalid position!\n");
			return last;
		}
	}
	newNode->next = curr->next;
	curr->next = newNode;

	if(curr == last) last = newNode;
	
	return last;
}