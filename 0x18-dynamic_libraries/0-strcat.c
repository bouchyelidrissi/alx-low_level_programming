#include "main.h"

/**
* _strcat - function that concatenates two strings
* @dest: distination
* @src: source
* Return: destination
*/

char *_strcat(char *dest, char *src)
{
int j, i = 0;

while (dest[i] != '\0')
{
i++;
}

for (j = 0; src[j] != '\0'; j++)
{
dest[i] = src[j];
i++;
}

dest[i] = '\0';

return (dest);
}
