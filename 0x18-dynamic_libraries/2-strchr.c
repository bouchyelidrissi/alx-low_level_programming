#include "main.h"
#include <stdio.h>

/**
* _strchr - searching for c in s
*
* @s: input
* @c: input
*
* Return: string dest
*/

char *_strchr(char *s, char c)
{


int i;


for (i = 0; s[i] != '\0'; i++)
{
if (s[i] == c)
{
return (s + i);
}
}

if (c == '\0')
{
return (s + i);
}


return (NULL);
}
