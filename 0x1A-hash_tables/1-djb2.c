#include "hash_tables.h"

/**
 * hash_djb2 - djb2 hashing algorithm.
 *
 * @str: value to hash
 *
 * Return: returns the hash index
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;

	while ((c = *str++))
	{
		/* hash * 33 + c */
		hash = ((hash << 5) + hash) + c;
	}

	return (hash);
}
