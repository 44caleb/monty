#include "monty.h"

/**
*_push - adds number to stack
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _push(stack_t **stack, unsigned int line_number)
{
	int arg;

	if (*(g_str + 1) == NULL || (_atoi(*(g_str + 1)) == NOT_STRING))
	{
		printf("ERROR currently at instruction ....%s\n", *g_str);
		printf("ERROR and the next instruction is ....%s\n", *(g_str + 1));
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		g_str++;
		arg = _atoi(*(g_str));
		*stack = add_node(stack, arg);
	}
}

/**
*_pall - prints stack
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
	{
		return;
	}

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
*_swap - swaps top 2 elements of stack
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node_1 = *stack, *node_2, *node_3;

	if (node_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node_3 = (node_1->next)->next;
	node_2 = node_1->next;
	node_2->next = node_1;
	node_2->prev = NULL;
	node_1->prev = node_2;
	node_1->next = node_3;

	if (node_3 != NULL)
	{
		node_3->prev = node_1;
	}

	*stack = node_2;
}


/**
*_pop - removes first element from stack
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node_1 = *stack, *node_2;

	if (node_1 == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	node_2 = node_1->next;

	if (node_2 == NULL)
	{
		*stack = node_2;
		free(node_1);
	}
	else
	{
		node_2->prev = NULL;
		*stack = node_2;
		free(node_1);
	}
}




/**
*_pint - prints first element
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *node_1 = *stack;

	if (node_1 == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", node_1->n);
}
