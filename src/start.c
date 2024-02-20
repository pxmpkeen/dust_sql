#include "main.h"

/**
 * start - entry point to database
 * Return: 
 */
int start(void)
{
	char *query;
    int status = 0;
    char **t_query;

    query = malloc(QURRY_BUF_SIZE);
    status = readcom(&query);

    if (!status)
        t_query = parse(query);
    else
        return (1);
    if (t_query == NULL)
        return (1);
    return 0;
}
