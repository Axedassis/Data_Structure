#include <stdio.h>
#include <unistd.h>
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
	q->rear = q->capacity - 1;
	q->array = (int *)malloc(sizeof(int) * q->capacity);
	return (q);
} 
