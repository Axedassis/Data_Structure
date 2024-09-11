# Queue #

The most simple data structe is Queue struct, that's can be based in two way
	-Array Queue
	-Linked List

## Array Queue ##
	the array queue is not not used in practice as it is not efficient.
	The concept of an "Array Queue" is to create a struct that has values such 
	as "capacity," which defines its capacity, "front," which represents the 
	first element, and "rear," which is the index where the elements extend in the array.

	```
	struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->queue = (int*)malloc(q->capacity * sizeof(int));
    return q;
	}
	```

	The concept is to truly place it as a stack of values, where the last 
	element to be added is the first to be removed.

	Queue is Empty
 	20 <--  30 <--  40 <--  50 <-- 

	After two node deletions
 	40 <--  50 <-- 

	After one insertion
 	40 <--  50 <--  60 <-- 

## Linked List ##
	o conceito não é criar um segmentação única na memória com os valores que queremos
	mas criar um conexação entre varias estruturas do mesmo tipo dispostas na memoria,
	a coneceção dela é feita armazenando o endereço para o próximo elemento dentro 
	da estrautura.

	```
	// Node structure representing a single node in the linked
	// list
	typedef struct Node {
    int data;
    struct Node* next;
	} Node;

	// Function to create a new node
	Node* createNode(int new_data)
	{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
	}
	```
	é como se de certa forma tivessemos um array de ponteiros para uma data
	estrutura de dados, porem de forma não linear na memória como no "Array queue"

