#include "hash_tables.h"

/**
 * hash_table_get - get data from a node in the hash table
 *
 * @ht: hash table
 * @key: key of the node
 *
 * Return: value or NULL if failed
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *current = NULL;
	unsigned long int index;

	if (!ht || !key || strcmp(key, "") == 0 || *key == '\0')
	{
		return (NULL);
	}

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	if (current == NULL)
	{
		return (NULL);
	}

	while (current && strcmp(current->key, key) != 0)
	{
		current = current->next;
	}

	return (current->value);
}
