#include "monty.h"

stack_t *head = NULL;

/**
 * main - the entry to point
 * @argc: arguments
 * @argv: list of arguments conts
 *
 * Return: Always 0
*/

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file(argv[1]);
	free_nodes();

	return (0);
}

/**
 * create_node -the function to Creates a node
 * @n: Number to go inside the node
 *
 * Return: Always 0
 */

stack_t *create_node(int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		err(4);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;

	return (node);
}
/**
 * free_nodes - the function to frees node to the stack
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
	{
		return;
	}

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
/**
 * add_to_queue - thr function to  adds a node to queue.
 * @new_node: Pointer to new node.
 * @ln: line number
 */

void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
