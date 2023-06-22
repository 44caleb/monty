#include "monty.h"

char **g_str;

/**
*main - executes monty byte code files
*@argc: argument count
*@argv: array of command line inputs
*Return: 0 success
*/
int main(int argc, char **argv)
{
	char *file_name;
	char buffer[1024];
	char *string_array[200];
	stack_t *stack = NULL;

	if (argc != 2)
	{
	printf("USAGE: monty file\n");
	exit(EXIT_FAILURE);
	}
	file_name = argv[1];
	g_str = string_array;

	read_file(file_name, buffer);
	parse_file(buffer, g_str);
	check_bytecode(&stack);
	free_list(stack);
	return (0);
}
