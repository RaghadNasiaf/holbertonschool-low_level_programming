#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at a given index in a dlist
 * @head: address of pointer to head node
 * @index: index to delete (starting at 0)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node, *next_node;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	node = *head;

	/* delete head */
	if (index == 0)
	{
		next_node = node->next;
		if (next_node != NULL)
			next_node->prev = NULL;
		*head = next_node;
		free(node);
		return (1);
	}

	/* move to index */
	while (node != NULL && i < index)
	{
		node = node->next;
		i++;
	}

	if (node == NULL)
		return (-1);

	/* unlink node */
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;

	free(node);
	return (1);
}
