#include "main.h"

/**
* _strncat - function that concatenates two strings
* @dest: distination
* @src: source
* @n: n number of source
* Return: destination
*/

char *_strncat(char *dest, char *src, int n)
{

int i = 0;
int j;


while (dest[i] != '\0')
{
i++;
}

for (j = 0; src[j] != '\0' && j < n ; j++)
{
dest[i] = src[j];
i++;
}

return (dest);
}
