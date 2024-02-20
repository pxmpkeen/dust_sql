#include "main.h"

/**
 * main - entry point to Dust Database Management System
 * @argc: count of arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
    char *query = malloc(512);
    int ret;
	ret = start();
	return (ret);
}
