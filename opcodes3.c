#include "monty.h"

/**
*_pstr - prints string starting from top of stack
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
	{
		printf("\n");
		return;
	}

	while (ptr != NULL)
	{
		if (ptr->n > 127 || ptr->n < 0)
		{
			return;
		}
		if (ptr->n == 0)
		{
			printf("\n");
			return;
		}
		printf("%c", ptr->n);
		ptr = ptr->next;
	}
	printf("\n");
}

/**
*_sub - sub first 2 nums
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node_1 = *stack, *node_2;
	int sub;

	if (node_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		if (stack)
		{
			free_list(*stack);
		}
		exit(EXIT_FAILURE);
	}

	node_2 = node_1->next;
	sub = (node_2->n) - (node_1->n);

	_pop(stack, line_number);
	node_2->n = sub;
}


/**
*_div - divide first 2 nums
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *node_1 = *stack, *node_2;
	int div;

	if (node_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		if (stack)
		{
			free_list(*stack);
		}
		exit(EXIT_FAILURE);
	}

	node_2 = node_1->next;

	if (node_1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		if (stack)
		{
			free_list(*stack);
		}
		exit(EXIT_FAILURE);
	}
	div = (node_2->n) / (node_1->n);

	_pop(stack, line_number);
	node_2->n = div;
}



/**
*_mul - multiplies first 2 nums
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *node_1 = *stack, *node_2;
	int mul;

	if (node_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		if (stack)
		{
			free_list(*stack);
		}
		exit(EXIT_FAILURE);
	}

	node_2 = node_1->next;
	mul = (node_2->n) * (node_1->n);

	_pop(stack, line_number);
	node_2->n = mul;
}



/**
*_mod - finds mod of first 2 nums
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node_1 = *stack, *node_2;
	int mod;

	if (node_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		if (stack)
		{
			free_list(*stack);
		}
		exit(EXIT_FAILURE);
	}

	node_2 = node_1->next;

	if (node_1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		if (stack)
		{
			free_list(*stack);
		}
		exit(EXIT_FAILURE);
	}
	mod = (node_2->n) % (node_1->n);

	_pop(stack, line_number);
	node_2->n = mod;
}
