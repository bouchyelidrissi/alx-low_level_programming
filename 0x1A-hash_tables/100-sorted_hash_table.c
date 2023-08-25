#include "hash_tables.h"
/**
 * shash_table_create - free hash table
 * @ht: The hash table to free
 *
 * Return: Nothing!
 */
shash_node_t *create_s_node(const char *key, const char *value);
shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned int i;
	shash_table_t *table = malloc(sizeof(shash_table_t));

	if (!table)
		return (NULL);

	table->size = size;

	table->array = malloc(sizeof(shash_node_t *) * size);
	if (!table->array)
		return (NULL);

	for (i = 0; i < size; i++)
		table->array[i] = NULL;

	return (table);
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**
 * create_s_node - create node for table
 *
 * @key: key of the node
 * @value: value of the node
 *
 * Return: new_node node
 */
shash_node_t *create_s_node(const char *key, const char *value)
{
	shash_node_t *new_node_node = malloc(sizeof(shash_node_t));

	if (!new_node_node)
		return (NULL);

	new_node_node->key = strdup(key);
	new_node_node->value = strdup(value);
	new_node_node->next = NULL;

	new_node_node->sprev = NULL;
	new_node_node->snext = NULL;

	return (new_node_node);
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**
 * shash_table_set - add node at index of hash table
 *
 * @ht: hash table
 * @key: the key to hash
 * @value: of the node
 *
 * Return: 1 if succeed 0 if fail
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *temp_node;
	char *val_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	val_copy = strdup(value);
	if (val_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp_node = ht->shead;
	while (temp_node)
	{
		if (strcmp(temp_node->key, key) == 0)
		{
			free(temp_node->value);
			temp_node->value = val_copy;
			return (1);
		}
		temp_node = temp_node->snext;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	{
		free(val_copy);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(val_copy);
		free(new_node);
		return (0);
	}
	new_node->value = val_copy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (ht->shead == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		temp_node = ht->shead;
		while (temp_node->snext != NULL && strcmp(temp_node->snext->key, key) < 0)
			temp_node = temp_node->snext;
		new_node->sprev = temp_node;
		new_node->snext = temp_node->snext;
		if (temp_node->snext == NULL)
			ht->stail = new_node;
		else
			temp_node->snext->sprev = new_node;
		temp_node->snext = new_node;
	}

	return (1);
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**
 * shash_table_print - print a hash table
 * @ht: The hash table to prints
 *
 * Return: Nothing!
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->shead;
	while (node != NULL)
	{
		if (first)
			first = 0;
		else
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
	}
	printf("}\n");
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**
 * shash_table_print_rev - print a hash table
 * @ht: The hash table to prints
 *
 * Return: Nothing!
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->stail;
	while (node != NULL)
	{
		if (first)
			first = 0;
		else
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
	}
	printf("}\n");
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**
 * shash_table_delete - free hash table
 * @ht: The hash table to free
 *
 * Return: Nothing!
 */
void shash_table_delete(shash_table_t *ht)
{

	shash_node_t *current = NULL;
	shash_node_t *temp = NULL;
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
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
