#include "main.h"

/**
 * _abs - Returns absolute number
 * @n: input.
 * Return: Returns absolute number.
 */

int _abs(int n)
{
	if (n < 0)
	{

		return (n -= n * 2);

	}
	else
	{
		return (n);
	}

}
