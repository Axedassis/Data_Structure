#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
   mm                                       mmmm    m                  #     
   ##    m mm   m mm   mmm   m   m         #"   " mm#mm   mmm    mmm   #   m 
  #  #   #"  "  #"  " "   #  "m m"         "#mmm    #    "   #  #"  "  # m"  
  #mm#   #      #     m"""#   #m#              "#   #    m"""#  #      #"#   
 #    #  #      #     "mm"#   "#           "mmm#"   "mm  "mm"#  "#mm"  #  "m 
                              m"                                             
                             ""                                              
*/

typedef struct Stack
{
	unsigned int capacity;
	int top; //as rear, as index from the current element
	int* array;
} Stack;

Stack* create_stack(unsigned int capactiy)
{
	if(capactiy > 0)
	{
		Stack* stack = (Stack *)malloc(sizeof(Stack));
		if(stack == NULL)
		{
			printf("Unable to allocate memory");
			exit (EXIT_FAILURE);
		}
		stack->top = -1;
		stack->array = (int *)malloc(sizeof(int) * capactiy);
		if(stack->array == NULL)
		{
			printf("Unable to allocate memory");
			exit (EXIT_FAILURE);
		}
		stack->capacity = capactiy;
		return(stack);
	}
	printf("Invalid capacity");
	exit(EXIT_FAILURE);
}

int isFull(Stack *stack)
{
	return (stack->top == stack->capacity - 1);
}

int isEmpty(Stack *stack)
{
	return (stack->top == -1);
}

void push(Stack *stack, int value)
{
	if(isFull(stack))
	{
		printf("Full Stack");
		return;
	}
	stack->top = stack->top + 1;
	stack->array[stack->top] = value;
	printf("%d pushed to stack\n", value);
}

int pop(Stack *stack)
{
	if(stack)
	{
		if(!isEmpty(stack))
		{
			return stack->array[--stack->top];
		}
		return INT_MIN;
	}
	printf("Invalid pointer\n");
	return INT_MIN;
}

int peek(Stack *stack)
{
	if(stack)
	{
		if(!(isEmpty(stack)))
		{
		return stack->array[stack->top];
		}
		return INT_MIN;
	}
	return 0;
}
int main()
{
    Stack *stack = create_stack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d popped from stack\n", pop(stack));

    return 0;
}