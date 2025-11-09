#include "lists.h"

/**
 * print_dlistint - prints all elements of a dlistint_t list
 * @h: pointer to head of the list
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;
	const dlistint_t *node = h;

	while (node)
	{
		printf("%d\n", node->n);
		count++;
		node = node->next;
	}
	return (count);
}
