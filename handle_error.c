#include "monty.h"


/**
 * usage_error - prints to stderr when program isn't correctly used
 *
 * Return: nothing
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_error - writes to standard error
 *
 * @filename: name of file containing monty commands
 *
 * Return: nothing
 */
void file_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}


/**
 * malloc_error - writes to standard error when malloc fails
 *
 * Return: nothing
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
