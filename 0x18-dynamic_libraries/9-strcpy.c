#include "main.h"

/**
* _strcpy -  that copies the string to another distination
* @dest: distination
* @src: source
* Return: destination
*/

char *_strcpy(char *dest, char *src)
{
int i = 0;

while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}

dest[i] = '\0';

return (dest);
}
