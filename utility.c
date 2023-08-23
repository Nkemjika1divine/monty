#include "monty.h"

/**
 * _strdup - this function duplicates a string
 * @str: stribg
 *
 * Return: new strung
 */
char *_strdup(char *str)
{
	int i, length;
	char *dup;

	if (str == NULL)
		return (NULL);

	length = 0;
	while (str[length] != '\0')
		length++;

	dup = (char *)malloc(length + 1);
	if (dup == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		dup[i] = str[i];

	return (dup);
}
