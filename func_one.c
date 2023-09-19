#include "shell.h"

/**
 * tokenize - Tokenizes a string and returns
 * a dynamically allocated array of strings
 * @str: input entered by user
 * Return: Double pointer of the string
 */

char **tokenize(char *str)
{
    char **token_arr = custom_strtok(str, " \n");
    return token_arr;
}

/**
 * _getpath - Retrieves and duplicates the path
 * Return: A strings of the PATH Variable
 */

char *_getpath(void)
{
    int x;
    char *duplicate = NULL;
    extern char **environ;

    for (x = 0; environ[x] != NULL; x++)
    {
        if (strncmp(environ[x], "PATH", 4) == 0)
            duplicate = strdup(environ[x]);
    }
    return duplicate;
}

