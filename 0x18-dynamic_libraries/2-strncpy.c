#include "main.h"

/**
* _strncpy - Write a function that copies a string
* @dest: distination
* @src: source
* @n: n number of source characters
*
* Return: destination
*/

char *_strncpy(char *dest, char *src, int n)
{

int j;

for (j = 0 ; src[j] != '\0' && j < n ; j++)
{
dest[j] = src[j];
}

for ( ; j < n; j++)
dest[j] = '\0';

return (dest);
}
