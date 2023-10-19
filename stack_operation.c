#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * mul_nodes - function to add the top two elements
 * @stack: a pointer pointing to top node
 * @line_number: Interger the line number
*/

void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	s = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes - function to add the top two elements
 * @stack: a pointer pointing to top node
 * @line_number: Interger the line number
*/

void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	s = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
