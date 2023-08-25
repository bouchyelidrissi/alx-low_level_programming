#include "hash_tables.h"

/**
 * key_index - get index for buckets
 *
 * @key: the key to hash
 * @size: size of the hash table
 *
 * Return: index
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
