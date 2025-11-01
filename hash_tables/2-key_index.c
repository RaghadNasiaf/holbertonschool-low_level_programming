#include "hash_tables.h"

/**
 * key_index - gives the index of a key
 * @key: the key (as unsigned char *)
 * @size: size of the hash table array
 * Return: index at which the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	/* size > 0 per project contract; return 0 defensively if misused */
	if (size == 0)
		return (0);

	return (hash_djb2(key) % size);
}
