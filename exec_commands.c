#include "shell.h"

/**
 * exec_cmd - Executes the command
 * @args: An array of user arguments
 * @argv: Array of command line arguments
 * Return: Void
 */

int exec_cmd(char **args, char **argv)
{
        pid_t child_pid;
        int status;
        extern char **environ;
        /*int error_code;*/

        child_pid = fork();
        if (child_pid < 0)
        {
                perror(argv[0]);
                exit(-1);
        }
        else if (child_pid == 0)
        {
                execve(args[0], args, environ);
                perror(argv[0]);
                exit(2);
        }
        else
        {
                wait(&status);
                if (WIFEXITED(status))
                        status = WEXITSTATUS(status);

                /*error_code = status;*/

                /*A Macro that handles correct conversion of exit status of the child*/
                free(args); /*This was a dynamically allocated array of strings*/
        }


        return (status);
}
