#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct st_node
{
	int number;
	struct st_node *next;
} node;

int main(int argc, char const *argv[])
{
	if(argc != 1)
	{
		node *list = NULL;
		int value;
		node *n;
		for (int i = 0; i < (argc - 1); i++)
		{
			value = atoi(argv[i + 1]);
			n =(node *)malloc(sizeof(node));
			if(n == NULL)
			{
				printf("failure to allocate memory");
				return(EXIT_FAILURE);
			}
			n->number = value * 10;
			n->next = NULL;
			if(list == NULL)
			{
				list = n;
			}else if(n->number < list->number)
			{
				n->next = list;
				list = n;
			}
			else{
				for(node *tmp = list; tmp != NULL; tmp = tmp->next)
				{
					if(tmp->next == NULL)
					{
						tmp->next = n;
						break;	
					}
					if(n->number < tmp->next->number)
					{
						n->next = tmp->next;
						tmp->next = n;
						break;
					}
				}
			}
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
