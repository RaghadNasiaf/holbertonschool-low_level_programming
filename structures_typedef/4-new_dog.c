#include "dog.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a C-string (local helper)
 * @s: source string (may be NULL)
 * Return: pointer to new string, or NULL on failure
 */
static char *_strdup(const char *s)
{
	char *p;
	size_t len = 0, i;

	if (s)
		while (s[len])
			len++;

	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		p[i] = s[i];
	p[len] = '\0';
	return (p);
}

/**
 * new_dog - creates a new dog, storing copies of name and owner
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 * Return: pointer to new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d = malloc(sizeof(*d));

	if (d == NULL)
		return (NULL);

	d->name = _strdup(name ? name : "");
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = _strdup(owner ? owner : "");
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	d->age = age;
	return (d);
}
