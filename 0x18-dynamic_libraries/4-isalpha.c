#include "main.h"

/**
 * _isalpha - checks if c is letetr or something else.
 * @c: input.
 * Return: Returns 1 if c is letter , Returns 0 otherwise.
 */

int _isalpha(int c)
{

	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
	{
		return (1);

	}
	else
	{
		return (0);
	}

}
