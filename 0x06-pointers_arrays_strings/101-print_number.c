#include "main.h"

/**
 * print_number - print numbers chars
 * @n: integer params
 * Return: 0
 */

void print_number(int n)
{
	unsigned int N0;

	N0 = n;

	if (n < 0)
	{
		_putchar('-');
		N0 = -n;
	}

	if (N0 / 10 != 0)
	{
		print_number(N0 / 10);
	}
	_putchar((N0 % 10) + '0');
}
