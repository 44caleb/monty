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
	buffer[bytesread] = '\0';
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
	int j = 0, k = 0, i = 0;
	char delim[] = " "; char new_buffer[1024];
	char *token;

	while (buffer[j] != '\0')
	{
		if (buffer[j] == '\n')
		{
			new_buffer[k++] = buffer[j++];
			new_buffer[k++] = ' ';
		}
		if (buffer[j] != '\n' && buffer[j + 1] == '\n')
		{
			new_buffer[k++] = buffer[j++];
			new_buffer[k++] = ' ';
		}
		if (buffer[j] != '\n')
		{
			new_buffer[k++] = buffer[j++];
		}
	}
	new_buffer[k] = '\0';
	token = strtok(new_buffer, delim);
	string_array[i++] = token;

	while (token != NULL)
	{
		token = strtok(NULL, delim);
		string_array[i++] = token;
	}
	string_array[i] = NULL;
}

/**
*check_bytecode - checks and executes bytecode instructions
*@stack: pointer to the top of the stack
*@lineflag: signifies a newline if +ve, else 0
*Return: nothing
*/
void check_bytecode(stack_t **stack, int lineflag)
{
	int line_number = 1, i = 0;
	instruction_t opcodes[] = {
	{"pall", _pall}, {"push", _push}, {"pint", _pint}, {"pop", _pop},
	{"swap", _swap}, {"add", _add}, {"sub", _sub}, {"mul", _mul},
	{"div", _div}, {"rotr", _rotr}, {"mod", _mod}, {"rotl", _rotl},
	{"pstr", _pstr}, {"pchar", _pchar}, {"nop", _nop},
	{NULL, NULL}};

		while (*g_str != NULL)
		{
			if (strcmp("\n", *g_str) == 0)
			{
				lineflag++; line_number++; g_str++; i = 0; continue;
			}
			if (lineflag > 0)
			{
				while (opcodes[i].opcode != NULL)
				{
					if (strcmp(opcodes[i].opcode, *g_str) == 0)
					{
						opcodes[i].f(stack, line_number);
						lineflag = 0; i = 0; break;
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
			g_str++;
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
