/*
  mmmm    m                  #             ""#      "           #            
 #"   " mm#mm   mmm    mmm   #   m           #    mmm    m mm   #   m   mmm  
 "#mmm    #    "   #  #"  "  # m"            #      #    #"  #  # m"   #"  # 
     "#   #    m"""#  #      #"#             #      #    #   #  #"#    #"""" 
 "mmm#"   "mm  "mm"#  "#mm"  #  "m           "mm  mm#mm  #   #  #  "m  "#mm" 
                                                                             
                                                                             
                                                                             
     #         ""#      "             m                                      
  mmm#           #    mmm     mmm   mm#mm                                    
 #" "#           #      #    #   "    #                                      
 #   #           #      #     """m    #                                      
 "#m##           "mm  mm#mm  "mmm"    "mm  
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Stack
{
	int value, data;
	struct Stack *next;
} Stack;


Stack *create_stack(int data)
{
	if(data != NULL)
	{
		Stack *stack = (Stack *)malloc(sizeof(Stack));
		if(stack == NULL)
		{
			printf("Unable t allocate memory");
			return;
		}
		stack->data = data;
		stack->next = NULL;
		return(stack);
	}
	printf("Invalid capacity rande");
	exit(EXIT_FAILURE);
}

int isEmpty(Stack *root)
{
	return !root;
}

void push(Stack *root, int value)
{
	Stack *node = create_stack(value);
	node->next = root->next;
	root = node;
	printf("Pushed %d into stack\n", value);
}

int pop(Stack *root)
{
	if(isEmpty(root))
		return INT_MIN;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
