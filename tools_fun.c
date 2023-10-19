
#include "monty.h"

/**
 * open_file - the function to open a file
 * @file_name: file name_path
 *
 * Return: Always (0).
 *
 */
void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{
		err(2, file_name);
	}
	read_file(fd);
	fclose(fd);
}
/**
 * read_file - the function to  read a file
 * @fd: file pointer to descriptor
 *
 * Return: Always (0).
 */

void read_file(FILE *fd)
{
	int line_num = 0;
	int format = 0;
	char *buffer = NULL;
	size_t len_fd = 0;

	line_num = 1;
	while (getline(&buffer, &len_fd, fd) != -1)
	{
		format = parse_line(buffer, line_num, format);
		line_num++;
	}
	free(buffer);
}

/**
 * parse_line - Each line is separated into distinct symbols to identify
 * the function to be called
 * @buffer: the line from file
 * @line_number: the line  to number
 * @format: format string. If 0 The nodes will be entered as a stack
 * if 1 The node will be entered into the queue
 *
 * Return: Always (0)
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode;
	char*value;
	const char *delim = "\n ";

	if (buffer == NULL)
	{
		err(4);
	}
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
	{
		return (format);
	}
	value = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	find_func(opcode, value, line_number, format);

	return (format);
}

/**
 * find_func - the function to find the appropriate function for the opcode
 * @opcode: it is opcode
 * @value: argument to the opcode
 * @ln: line number
 * @format: format string. If 0 The nodes will be entered as a stack
 * if 1 The node will be entered into the queue
 * Return: Always (0)
 */

void find_func(char *opcode, char *value, int ln, int format)
{
	int x;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;

	for (flag = 1, x = 0; func_list[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, func_list[x].opcode) == 0)
		{
			call_fun(func_list[x].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}

/**
 * call_fun - the function to Calls the required function
 * @func: The pointer to function  is about to be called
 * @op: string  It  is represents opcode
 * @val: string it is representing a numeric value
 * @ln: line numeber
 * @format: format string. If 0 The nodes will be entered as a stack
 * if 1 The node will be entered into the queue
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int x;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		x = 0;
		while (val[x] != '\0')
		{
			if (isdigit(val[x]) == 0)
				err(5, ln);
			x++;
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
