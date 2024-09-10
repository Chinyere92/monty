#include "monty.h"
/**
 * push - Add node to list of stack
 * @stack: pointer to head of nodes
 * @line_number: number of line read from open monty
 *
 * Description: Adds a new node to the top of the stack
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = value;
	node->prev = NULL;

	if (*stack == NULL)
	{
		node->next = NULL;
		*stack = node;
		return;
	}

	(*stack)->prev = node;
	node->next = *stack;
	*stack = node;

	(void)line_number
}
/**
 * pall - Prints all values on the stack
 * @stack: pointer to the head of the stack
 * @line_number: the line number (unused in this function)
 *
 * Description: Prints each value of the stack starting from the top.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}

	(void) line_number;
}

/**
 * pop - Removes the top element of the stack
 * @stack: Pointer to head of stack
 * @line_number: The line number in the Monty file
 *
 * Description: If the stack is empty, prints an error message and exits.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	h = (*stack)->next;
	free(*stack);
	*stack = h;

	if (h != NULL)
		h->prev = NULL;
}
/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: The line number in the Monty file
 *
 * Description: If the stack is empty, prints an error message and exits.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
 * swap - the top two elements of the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: The line number in the Monty file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int x;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = x;
}
