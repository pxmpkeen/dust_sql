#include "main.h"

/**
 * start - entry point to database
 * Return: 
 */
int start(void)
{
	char *query;
	size_t buffer_size = 0;

	while (true)
	{
		if (getdelim(&query, &buffer_size, ';', stdin) == -1)
			break;
		if (parse(query) == -1)
		{
			/* errno and exit */
		}
	}
	return (-1);
}
