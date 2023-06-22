#include "monty.h"
/**
*_atoi - turns string to number
*@str: string argument
*Return: number
*/
int _atoi(char *str)
{
	int num = 0;

	while (*str != '\0')
	{
		if (*str > 57 || *str < 48)
		{
			return (NOT_STRING);
		}

		num = num * 10 + (*str - 48);
		str++;
	}
	return (num);
}


/**
*read_file- reads a file
*@str: name of file
*@buffer: array that stores content of file
*Return: nothing
*/
void read_file(char *str, char *buffer)
{
	int fd;
	ssize_t bytesread;

	fd = open(str, O_RDONLY);

	if (fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}
	bytesread = read(fd, buffer, 1024);

	if (bytesread == -1)
	{
		fprintf(stderr, "Error: could not read file %s\n", str);
		exit(EXIT_FAILURE);
	}
	if (buffer[bytesread - 1] == '\n')
	{
		buffer[bytesread - 1] = '\0';
	}
	else
	{
		buffer[bytesread] = '\0';
	}
	close(fd);

}

/**
*parse_file - parses file
*@buffer: array with file content
*@string_array: array that stores parsed strings from file
*Return: nothing
*/
void parse_file(char *buffer, char **string_array)
{
	int i = 0, j = 0;
	char *ptr;

	while (buffer[i] != '\0')
	{
		if (buffer[i] == ' ' || buffer[i] == '\n')
		{
			while (buffer[i + 1] == ' ' || buffer[i + 1] == '\n')
			{
				buffer[i] = '\0';
				i++;
			}
			if (buffer[i + 1] == '\0')
			{
				break;
			}
			buffer[i] = '\0';
			i++;
			ptr = &buffer[i];
			string_array[j++] = ptr;
		}
		else
		{
			i++;
		}
	}
	string_array[j] = NULL;
}

/**
*check_bytecode - checks and executes bytecode instructions
*@stack: pointer to the top of the stack
*Return: nothing
*/
void check_bytecode(stack_t **stack)
{
	int line_number = 1, i = 0;
	instruction_t opcodes[] = {
	{"pall", _pall}, {"push", _push}, {"pint", _pint}, {"pop", _pop},
	{"swap", _swap}, {"add", _add}, {"sub", _sub}, {"mul", _mul},
	{"div", _div}, {"rotr", _rotr}, {"mod", _mod}, {"rotl", _rotl},
	{"pstr", _pstr}, {"pchar", _pchar}, {"nop", _nop},
	{NULL, NULL}
	};

		while (*g_str != NULL)
		{
			if (strcmp(opcodes[i].opcode, *g_str) == 0)
			{
				opcodes[i].f(stack, line_number);
				line_number++;
				g_str++;
				i = 0; /* reset value of i after finding function */
			}
			else
			{
				i++;
			}
			if (opcodes[i].opcode == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, *g_str);
				exit(EXIT_FAILURE);
			}
		}
}









/**
*add_end - adds node to end of a linked list
*@stack: pointer to the top of the stack
*@n: number element in node
*Return: nothing
*/
void add_end(stack_t **stack, int n)
{
	stack_t *ptr = *stack;
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	while (ptr != NULL)
	{
		if (ptr->next == NULL)
		{
			new->next = NULL;
			new->prev = ptr;
			ptr->next = new;
			return;
		}
		ptr = ptr->next;
	}
}
