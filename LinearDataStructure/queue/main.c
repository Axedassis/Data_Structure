#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Queue
{
	int front, rear, size;
	unsigned int capacity;
	int *array;
} Queue;

Queue* createQueue(unsigned capacity)
{
	Queue* q = (Queue *)malloc(sizeof(Queue));
	q->capacity = capacity;
	q->front = q->size = 0;
	q->rear = capacity - 1;
	q->array = (int *)malloc(q->capacity * sizeof(int));
	return (q);
} 

int isFull(Queue *queue)
{
	return (queue->size == queue->capacity);
}

int isEmpty(Queue *queue)
{
	return (queue->size == 0);
}

void enqueue(Queue *queue, int item)
{
	if(isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	/*
	capity = 5
	size = 4
	arrear = 4
	append more 1 element to queue 
	(4 + 1) % 5 = 0. the rear backs to the initial position

	(3 + 1) % 5 = 4 the rear still < 5, indicate that queue still had space
	*/
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("%d enqueued to queue\n", item);
}

int dequeue(Queue *queue)
{
	if(isEmpty(queue))
		return (INT_MIN);
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return (item);
}

int front(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

int rear(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

int main()
{
    Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    return (0);
}