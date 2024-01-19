#include "monty.h"

stack_t *head = NULL;

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg;
    int value;

    if (!stack || !*stack)
    {
        fprintf(stderr, "L%d: stack not found\n", line_number);
        exit(EXIT_FAILURE);
    }

    arg = strtok(NULL, " \t\n");

    if (!arg || !isdigit(*arg) && (*arg != '-' && !isdigit(*(arg + 1))))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);

    if (!push_node(stack, value))
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * push_node - Pushes a new node with a given value onto the stack.
 * @stack: Double pointer to the head of the stack
 * @n: Value to be pushed onto the stack
 * Return: A pointer to the newly created node
 */
stack_t *push_node(stack_t **stack, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (!new_node)
        return (NULL);

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;

    return (new_node);
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

