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



/**
 * spaces - this function checks a string for spaces and null characters.
 * @input: string to check
 *
 * Return: 1 if the string is just spaces and 0 if not
 */
int spaces(char *input)
{
	if (input == NULL)
		return (1);

	while (*input != '\0')
	{
		if (!is_space(*input))
			return (0);
		input++;
	}
	return (1);
}



/**
 * is_space - this function checks if a character is a whitespace
 * @c: character to check
 *
 * Return: 1 if character is a whitespace and 0 if not
 */
int is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' ||
					c == '\r')
		return (1);
	else
		return (0);
	return (1);
}




/**
 * remove_hash - this function checks for hash inbetween a line
 * @line: the line to check
 *
 * Return: new string if there is a hash
 */
char *remove_hash(char *line)
{
	char *hash;
	
	hash = strchr(line, '#');

	if (hash != NULL)
		*hash = '\0';
	return (line);
}




/**
 * fix_string - this function checks if a line has multiple spaces between words
 * @line: the string to check
 *
 * Return: new string wuth normal spacing between words
 */
char *fix_string(char *line)
{
	char *normal, *token = line;
	bool firstNonSpace = false;
	char *buffer = malloc(strlen(line) + 1);
	
	if (buffer == NULL)
		return (NULL);

	if (spaces(line) != 1)
	{
		normal = buffer;
		while (*token)
		{
			if (!isspace(*token))
			{
				*normal = *token;
				normal++;
				firstNonSpace = true;
			}
			else if (firstNonSpace)
			{
				*normal = ' ';
				normal++;
				while (isspace(*(token + 1)))
					token++;
			}
			token++;
		}
		*normal = '\0';
		return (normal);
	}
	else
		return (NULL);

	return (normal);
}
