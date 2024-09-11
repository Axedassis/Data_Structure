#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Criando a estrutura básica de uma linked list
typedef struct  Node
{
	int data;
	struct Node *next;
} Node;

Node* createNode(int new_data)
{
	Node* new_node = (Node *)malloc(sizeof(Node));
	if(new_node == NULL)
	{
		printf("Unable to allocate memory");
		exit (EXIT_FAILURE);
	}
	new_node->data = new_data;
	new_node->next = NULL;
	return(new_node);
}

typedef struct Queue
{
	//ponteiro para o inicio e o final da LinkedLIst
	Node *front, *rear;
} Queue;

Queue* createQueue()
{
	Queue* q = (Queue *)malloc(sizeof(Queue));
	q->front = q->rear = NULL;
	return (q);
	//retorno de dois ponteiros nulos que vão indicar o fim e o início da linked List
}
//função para adicionar um elemento do tipo Node a Queue;
void enqueue(Queue *q, int new_data)
{
	Node* new_node = createNode(new_data);
	//Se nossa queue estiver vazia o primiero elemento vai ser tant o front como o rear
	if(q->rear == NULL)
	{
		q->front = q->rear = new_node;
		return;
	}
	//caso contrário, com base no rear adicionamos um elemento no next dele
	//e setamos o rear como o "new_node atual"
	q->rear->next = new_node;
	q->rear = new_node;
}

void dequeue(Queue *q)
{
	if(q->rear == NULL)
	{
		printf("Empty queue");
		return;
	}
	Node *tmp = q->front;
	q->front = q->front->next;

	//Se tiver somente 1 elemento o front se torna NULL logo teremos que setar o rear como NULL tmb
	if(q->front == NULL)
		q->rear == NULL;
	free(tmp);
}

