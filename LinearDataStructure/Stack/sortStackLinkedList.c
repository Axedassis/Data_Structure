/*
 mmmm                  m            mmmm    m                  #            
 #"   "  mmm    m mm  mm#mm         #"   " mm#mm   mmm    mmm   #   m        
 "#mmm  #" "#   #"  "   #           "#mmm    #    "   #  #"  "  # m"         
     "# #   #   #       #               "#   #    m"""#  #      #"#          
 "mmm#" "#m#"   #       "mm         "mmm#"   "mm  "mm"#  "#mm"  #  "m        
                                                                             
                                                                             
                                                                             
 m       ""           #                 #         m        "             m   
 #      mmm    m mm   #   m   mmm    mmm#         #      mmm     mmm   mm#mm 
 #        #    #"  #  # m"   #"  #  #" "#         #        #    #   "    #   
 #        #    #   #  #"#    #""""  #   #         #        #     """m    #   
 #mmmmm mm#mm  #   #  #  "m  "#mm"  "#m##         #mmmmm mm#mm  "mmm"    "mm 

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct NodeStack
{
	int data;
	struct NodeStack *next;
} NodeStack;

NodeStack *createNode(int data)
{
	NodeStack *node = (NodeStack *)malloc(sizeof(NodeStack));
	if(node == NULL)
	{
		printf("Unable to allocate memory");
		exit (EXIT_FAILURE);
	}
	node->next = NULL;
	node->data = data;
	return (data);
}

void swap(NodeStack *bottomNode, NodeStack *topNode)
{
	NodeStack *tmp = bottomNode;
	bottomNode->next = topNode->next;
	topNode->next = tmp;
}

int isEmpty(NodeStack *root)
{
	return !root;
}

void push(NodeStack **root, int data)
{
	if(isEmpty(root))
		return INT_MIN;
	NodeStack *node = createNode(data);
	(*root)->next = node;
	*root = node;
}

int pop(NodeStack **root)
{
	if(isEmpty(root))
		return INT_MIN;
	NodeStack *tmp = *root;
	int poppedVal = tmp->data;
	*root = (*root)->next;
	free(tmp);

	return(poppedVal);
}
void sortLinkedListStack(NodeStack* root)
{
	if(!root)
		return INT_MIN;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(root->next != NULL)
	{
		
	}
}