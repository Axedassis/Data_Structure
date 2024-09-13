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

typedef struct StackNode
{
	int data;
	struct StackNode *next;
} StackNode;

StackNode* newNode(int data)
{
	StackNode* node = (StackNode *)malloc(sizeof(StackNode));
	if(node == NULL)
	{
		printf("Unable to allocate memory");
		exit (EXIT_FAILURE);
	}
	node->next = NULL;
	node->data = data;
	
	return (node);
}

int isEmpty(StackNode *root)
{
	return !root;
}

void push(StackNode **root, int data)
{
	StackNode* push_node = newNode(data);
	push_node->next = *root;
	*root = push_node;
	printf("push %d into stack\n", data);
}

int pop(StackNode **root)
{
	if(isEmpty(*root))
		return INT_MIN;
	StackNode* tmp = *root;
	int poppedVal = tmp->data;
	*root = (*root)->next;
	free(tmp);
	printf("popped %d of stack\n", poppedVal);
	return (poppedVal);
}

int peek(StackNode* root)
{
	if(isEmpty(root))
		return INT_MIN;
	return root->data;
}

int main(void)
{
	StackNode *list = NULL;
	push(&list, 67);
	push(&list, 22);
	push(&list, 7);
	push(&list, 25);
	printf("Peek: %d\n", peek(list));
	pop(&list);
	printf("Peek: %d\n", peek(list));
	pop(&list);
	printf("Peek: %d\n", peek(list));
	return 0;
}

