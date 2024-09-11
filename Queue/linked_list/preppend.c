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
	int		arg;
	node	*list = NULL;

	if(argc != 1)
	{
		node	*n;
		for (int i = 0; i < (argc - 1); i++)
		{
			arg = atoi(argv[i + 1]);
			n = (node *)malloc(sizeof(node));
			if(n == NULL)
			{
				printf("failure to allocate memory");
				return (EXIT_FAILURE);
			}
			n->number = arg * 10;
			n->next = list;
			list = n;
		}
		while(list != NULL)
		{
			node *tmp;
			tmp = list;
			printf("Values: %d\n", list->number);
			list = list->next;
			free(tmp);
		}
	}
	write(1, "\n", 1);	
	return 0;
}

