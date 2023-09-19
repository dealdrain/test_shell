#include "shell.h"

int main(int argc, char **argv)
{
	int shell_mode = isatty(0);
	char *entry_buffer = NULL;
	char *prompt_message = "OurSimpleShell>$ ";
	size_t size = 0;
	ssize_t num = 0;
	int error_code = 0;

	(void)argc;
	while (1)
	{
		if (shell_mode == 1)
			print_string(prompt_message);

		num = getline(&entry_buffer, &size, stdin);
		
		if (num == -1)
		{
			free(entry_buffer);
			exit(error_code);
		}

		error_code = process_input(entry_buffer, argv, error_code);
	}

	return (error_code);
}
