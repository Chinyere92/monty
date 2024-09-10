#include "monty"
/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: The line number in the Monty file
 *
 * Description: Adds the top two elements and stores the result in the second
 * top element. The top element is then removed. If the stack has fewer than
 * two elements, prints an error message and exits.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	h = (*stack)->next;
	h->n += (*stack)->n;
	free(*stack);
	h->prev = NULL;
	*stack = h
}
/**
 * nop - Does nothing.
 * @stack: Pointer to head of the stack (unused)
 * @line_number: Line number from Monty file (unused)
 *
 * Description: This function performs no operation. It's essentially
 * a placeholder instruction in the Monty bytecode language.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
