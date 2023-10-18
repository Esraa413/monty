#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * err - Print appropriate error messages that are identified by their 
 * error code.
 * @error_code: The error codes are as follows:
 * (1) => user is does not give any one or more files to the program
 * (2) => provided is file is not a file that can be opened and read
 * (3) => file is provided contains invalid instructions
 * (4) => When program is unable to provide or malloc more memory
 * (5) => When parameter is passed to the "Push" instruction not an "int"
 * (6) => When stack is empty for pints
 * (7) => When stack it is empty for pop
 * (8) => When stack is too short to run
 *
 */

void err(int error_code, ...)
{
	va_list code;
	char *op;
	int num1;

	va_start(code, error_code);
	switch (error_code)
	{
		case (1):
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case (2):
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(code, char *));
			break;
		case (3):
			num1 = va_arg(code, int);
			op = va_arg(code, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num1, op);
			break;
		case (4):
			fprintf(stderr, "Error: malloc failed\n")
				break;
		case (5):
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(code, int));
			break;
		default:
			break;
	}
	exit(EXIT_FAILURE);
}

