#include "monty.h"

/**
*_add - adds first 2 nums
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *node_1 = *stack, *node_2;
	int sum;

	if (node_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		if (stack)
		{
			free_list(*stack);
		}
		exit(EXIT_FAILURE);
	}

	node_2 = node_1->next;
	sum = (node_1->n) + (node_2->n);

	_pop(stack, line_number);
	node_2->n = sum;

}


/**
*_nop- does nothing
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _nop(__attribute__ ((unused))stack_t **stack,
__attribute__ ((unused))unsigned int line_number)
{
	;
}


/**
*_rotr - rotates stack
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *ptr = *stack, *new;
	stack_t *new_stack = NULL;
	int arg;

	if (ptr == NULL)
	{
		return;
	}

	while (ptr != NULL)
	{
		arg = ptr->n;
		new = add_node(&new_stack, arg);
		ptr = ptr->next;
	}
	free_list(*stack);
	*stack = new;
}

/**
*_rotl - sends 1st element to last
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int arg;

	if (ptr == NULL || node_len(*stack) == 1)
	{
		return;
	}
	arg = ptr->n;
	add_end(stack, arg);
	_pop(stack, line_number);
}


/**
*_pchar - prints first character
*@stack: pointer to the top of the stack
*@line_number: the index of the current line
*Return: nothing
*/
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int letter;

	if (ptr == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		if (stack)
		{
			free_list(*stack);
		}
		exit(EXIT_FAILURE);
	}
	letter = ptr->n;

	if (letter > 127 || letter < 0)
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		if (stack)
		{
			free_list(*stack);
		}
		exit(EXIT_FAILURE);
	}
	printf("%c\n", letter);
}

