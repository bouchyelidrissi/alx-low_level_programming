#include "main.h"
#include <stdio.h>


/**
* _strstr - a function that searches a string for any of a set of bytes.
*
* @haystack: input
* @needle: input
*
* Return: needle
*/

char *_strstr(char *haystack, char *needle)
{
int i, j, length = 0, counter = 0;

while (needle[length] != '\0')
{
length++;
}

for (i = 0; haystack[i] != '\0'; i++)
{
counter = 0;

for (j = 0; needle[j] != '\0'; j++)
{
if (haystack[i + j] == needle[j])
{
counter++;
}
else
{
break;
}
}

if (counter == length)
{
return (&haystack[i]);
}
}

return (NULL);
}
