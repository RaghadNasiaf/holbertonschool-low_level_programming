#include "hash_tables.h"

/**
 * key_index - compute index for a given key using djb2
 * @key: key string (as unsigned char *)
 * @size: size of the hash table array
 *
 * Return: index in range [0, size - 1]
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	/* حماية بسيطة لو تم تمرير حجم 0 بالخطأ */
	if (size == 0)
		return (0);

	return (hash_djb2(key) % size);
}
