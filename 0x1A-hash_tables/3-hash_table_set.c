#include "hash_tables.h"

/**
 * create_node - create node for table
 *
 * @key: key of the node
 * @value: value of the node
 *
 * Return: new node
 */

hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	if (!new_node)
		return (NULL);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;

	return (new_node);
}
/**
 * hash_table_set - add node at index of hash table
 *
 * @ht: hash table
 * @key: the key to hash
 * @value: of the node
 *
 * Return: 1 if succeed 0 if fail
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *current = NULL;
	hash_node_t *new_node = NULL;
	unsigned long int index;

	if (!ht || !key || strcmp(key, "") == 0 || *key == '\0' || !value)
	{
		return (0);
	}
	new_node = create_node(key, value);
	if (!new_node)
	{
		return (0);
	}
	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	if (current == NULL)
	{
		ht->array[index] = new_node;
		return (1);
	}
	else if (strcmp(current->key, key) == 0)
	{
		free(current->value);
		current->value = strdup(value);

		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (1);
	}
	else
	{
		new_node->next = ht->array[index];
		ht->array[index] = new_node;
	}
	return (1);
}
