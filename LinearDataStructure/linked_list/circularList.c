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

Node* insertAtbeginning(Node* last, int value)
{
	Node *node = createNode(value);
	if(node == NULL)
	{
		printf("Unable to allocated memory");
		exit (EXIT_FAILURE);
	}

	if(last == NULL)
	{
		node->next = node;
		return(node);
	}

	node->next = last->next;
	last->next = node;

	return (last);
}

void printList(Node* node)
{
	Node *tmp = node;

	while(1)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
		if(tmp == node) break;
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

    last = insertAtbeginning(last, 5);
	
    printf("\nList after inserting 5 at the beginning: ");
    printList(last);
	return 0;
}
