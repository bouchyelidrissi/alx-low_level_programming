#include "hash_tables.h"
/**
 * hash_table_delete - free hash table
 * @ht: The hash table to free
 *
 * Return: Nothing!
 */

void hash_table_delete(hash_table_t *ht)
{

	hash_node_t *current = NULL;
	hash_node_t *temp = NULL;
	unsigned long int i = 0;

	if (!ht)
		return;

	while (i < ht->size)
	{
		current = ht->array[i];

		while (current)
		{
			temp = current;
			free(temp->key);
			free(temp->value);
			free(temp);

			current = current->next;
		}
		i++;
	}
	free(ht->array);
	free(ht);
}
