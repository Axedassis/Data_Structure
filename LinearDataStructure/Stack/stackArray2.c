#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Stack
{
	int top; //also "Head"
	unsigned capacity;
	int* array;
} st_stack;


st_stack *createStack(unsigned capacity)
{
	st_stack *stack = (st_stack*)malloc(sizeof(st_stack));
	if(stack == NULL)
	{
		printf("unable to allocated memory");
		exit (EXIT_FAILURE);
	}
	stack->capacity = capacity;
	stack->top = -1; //because we are handling with an array index;
	stack->array = (int *)malloc(sizeof(int) * capacity);

	return (stack);
} 

int isEmpty(st_stack *stack)
{
	return stack->top == -1;	
}

int isFull(st_stack *stack)
{
	return stack->top == (stack->capacity - 1);
}

void push(st_stack *stack, int value)
{
	if(isFull(stack))
	{
		printf("OverflowE Error Stack\n");
		return;
	}
	stack->top = stack->top + 1;
	stack->array[stack->top] = value;
}

int pop(st_stack *stack)
{
	if(isEmpty(stack))
	{
		printf("Underflow Error Stack\n");
		return INT_MIN;
	}
	return (stack->array[stack->top--]);
}

int peek(st_stack *stack)
{
	if(isEmpty(stack))
	{
		printf("Underflow Error Stack\n");
		return INT_MIN;
	}
	return (stack->array[stack->top]);
}

int main(void)
{
	st_stack *int_stack = createStack(5);
	push(int_stack, 10);
	push(int_stack, 20);
	printf("TOP value: %d\n", peek(int_stack));
	push(int_stack, 30);
	push(int_stack, 40);
	printf("TOP value: %d\n", peek(int_stack));
	printf("REMOVE value: %d\n", pop(int_stack));
	printf("TOP value: %d\n", peek(int_stack));
	push(int_stack, 60);
	printf("TOP value: %d\n", peek(int_stack));
	return 0;
}