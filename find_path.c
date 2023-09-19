#include "shell.h"

/**
 * find_path - find the full valid path
 * @paths: A string of multiple directories in the path
 * @cmd: the command
 * Return: A Pointer to full string or NULL
 */
char *find_path(char *paths, char *cmd)
{
    char **path_tokens = custom_strtok(paths, ":");
    int x = 0, i;
    size_t len = 0;
    char *fullpath = NULL;

    if (path_tokens == NULL)
        return NULL;

    while (path_tokens[x] != NULL)
    {
        len = strlen(path_tokens[x]) + strlen(cmd) + 2;
        fullpath = malloc(len);
        if (fullpath == NULL)
        {
	    for (i = 0; path_tokens[i] != NULL; i++)
                free(path_tokens[i]);
            free(path_tokens);
            return NULL;
        }

        strcpy(fullpath, path_tokens[x]);
        strcat(fullpath, "/");
        strcat(fullpath, cmd);

        if (access(fullpath, X_OK) == 0)
        {
            for (i = 0; path_tokens[i] != NULL; i++)
                free(path_tokens[i]);
            free(path_tokens);
            return fullpath;
        }

        free(fullpath);
        fullpath = NULL;
        x++;
    }

    for (i = 0; path_tokens[i] != NULL; i++)
        free(path_tokens[i]);
    free(path_tokens);
    return NULL;
}

