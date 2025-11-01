#include <string.h>
#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_get - retrieves the value associated with a key
 * @ht: hash table to look into
 * @key: key string to search
 *
 * Return: pointer to value (do not free), or NULL if not found/invalid
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *cur;

	if (!ht || !ht->array || !key || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);

	for (cur = ht->array[idx]; cur; cur = cur->next)
	{
		if (strcmp(cur->key, key) == 0)
			return (cur->value);
	}
	return (NULL);
}
