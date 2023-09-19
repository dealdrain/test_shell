#include "shell.h"
/**
 * custom_error - Prints custom error message
 * @prog: Program name
 * @counter: Counts the commands
 * @cmd: Command entered by user
 * Return: Void
 *
 */

void custom_error(char *prog, int counter, char *cmd)
{
        _puts(prog);
        _puts(": ");
        _putchar(counter);
        _puts(": ");
        _puts(cmd);
        _puts(": not found\n");
}      
