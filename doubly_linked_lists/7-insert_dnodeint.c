#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given index
 * @h: pointer to head pointer of list
 * @idx: index where to insert (starting at 0)
 * @n: value for new node
 *
 * Return: address of new node, or NULL on failure/out of range
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *cur, *new_node;
	unsigned int i;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	cur = *h;
	i = 0;
	while (cur && i < idx - 1)
	{
		cur = cur->next;
		i++;
	}

	if (cur == NULL)
		return (NULL);

	if (cur->next == NULL)
		return (add_dnodeint_end(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = cur;
	new_node->next = cur->next;

	cur->next->prev = new_node;
	cur->next = new_node;

	return (new_node);
}
