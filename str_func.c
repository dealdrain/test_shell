#include "shell.h"

#define SIZE_OF_INPUT 100

/**
 * print_string - Print a string and count the number of characters printed
 * @str: The string to print
 * Return: The number of characters printed
 */

int print_string(char *str)
{
	int x = 0;
	int num = 0;

	while (str[x])
	{
		num += write(1, &str[x], 1);
		x++;
	}
	return (num);
}

/**
 * _puts - prints a given string
 * @str: This is the string to be printed
 * Return: Void
 *
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}

/**
 * _putchar - Prints a character to standard error
 * @ch: This is the character to be printed
 * Return: An integer
 */

int _putchar(char ch)
{
	return (write(2, &ch, 1));
}

/**
 * check_delim - this checks if character is a delimeter or not
 * @c: the character to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int check_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
