#include "monty.h"

/**
*add_node - adds node to start of list
*@stack: pointer to the top of the stack/list
*@arg: number data of node
*Return: nothing
*/
stack_t *add_node(stack_t **stack, int arg)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (stack)
		{
			free_list(*stack);
		}
		exit(EXIT_FAILURE);
	}

	new->n = arg;
	new->next = *stack;
	new->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	*stack = new;
	return (new);
}

/**
*free_list - frees list
*@stack: pointer to the top of the stack
*Return: nothing
*/
void free_list(stack_t *stack)
{
	stack_t *ptr = stack, *tmp;

	while (ptr != NULL)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}

/**
*node_len - gets length of list
*@stack: pointer to the top of the stack
*Return: length of list
*/
int node_len(stack_t *stack)
{
	stack_t *ptr = stack;
	int len = 0;

	while (ptr != NULL)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}
