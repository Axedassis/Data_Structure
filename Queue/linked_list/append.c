#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct st_node
{
	int number;
	struct st_node *next;
} node;

int main(int argc, char const *argv[])
{
	if(argc > 1)
	{
		int value;
		node *list = NULL;
		node *n;
		for (int i = 0; i < (argc - 1); i++)
		{
			value = atoi(argv[i+1]);
			n = (node *)malloc(sizeof(node));
			if(n == NULL)
			{
				printf("failure to allocate memory");
				return(EXIT_FAILURE);
			}
			n->number = value*10;
			n->next = NULL;
			if(list == NULL)
			{
				list = n;
				continue;
			}
			node *tmp = list;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = n;
		}
		node *tmp;
		while (list != NULL)
		{
			tmp = list;
			printf("Value: %d\n", list->number);
			list = list->next;
			free(tmp);
		}
		
	}
	write(1, "\n", 1);
	return 0;
}
