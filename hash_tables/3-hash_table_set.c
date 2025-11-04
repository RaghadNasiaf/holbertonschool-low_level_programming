#include <string.h>
#include <stdlib.h>
#include "hash_tables.h"

/**
 * make_node - creates a new hash node
 * @key: key string
 * @value: value string
 * Return: pointer to new node, or NULL on failure
 */
static hash_node_t *make_node(const char *key, const char *value)
{
	hash_node_t *n = malloc(sizeof(*n));

	if (!n)
		return (NULL);

	n->key = strdup(key);
	if (!n->key)
	{
		free(n);
		return (NULL);
	}

	n->value = strdup(value ? value : "");
	if (!n->value)
	{
		free(n->key);
		free(n);
		return (NULL);
	}

	n->next = NULL;
	return (n);
}

/**
 * hash_table_set - adds or updates an element in the hash table
 * @ht: hash table
 * @key: key (must not be empty)
 * @value: value to store (duplicated)
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *cur;
	char *dup;

	if (!ht || !ht->array || !key || !*key || !value)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	for (cur = ht->array[idx]; cur; cur = cur->next)
	{
		if (strcmp(cur->key, key) == 0)
		{
			dup = strdup(value);
			if (!dup)
				return (0);
			free(cur->value);
			cur->value = dup;
			return (1);
		}
	}

	cur = make_node(key, value);
	if (!cur)
		return (0);

	cur->next = ht->array[idx];
	ht->array[idx] = cur;
	return (1);
}
