#include "shell.h"

/**
 * free_buff - frees the allocated memory.
 * @buff: buffer to be frees.
 *
 * return: Nothing.
 */

void free_buff(char **buff)
{
	int i = 0;

	while (buff[i] != NULL)
	{
		free(buff[i++]);
	}
	free(buff[i]);
	free(buff);
}

/**
 * exit_program - kill the process.
 * @input: user input.
 * @path: path.
 *
 * Return: Nothing.
 */

void exit_program(char **buff, char *input, char *path, int ret)
{
	free(input);
	free(path);
	free_buff(buff);
	exit(ret);
}

/**
 * _getline - getline function.
 * @path: the path.
 *
 * Return: input.
 */

/**
 * not_found - Print command not found.
 * @argv: arguments.
 * @argc: Number of arguments.
 * @cmnd: input command.
 *
 * Return: Error code (command not found - 127)
 */

int not_found(char *argv[], int argc, char *cmnd)
{
	dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", argv[0], argc, cmnd);
	return (127);
}

char *_getline(char *path, int ret, int fd_isatty)
{
	ssize_t ch_read = 0;
	size_t in_size = 0;
	char *input = NULL;

	ch_read = getline(&input, &in_size, stdin);
	/*check if (getline) filed, reached EOF or exit*/
	if (ch_read == -1)
	{
		if (fd_isatty)
			printf("\n");
		free(input);
		free(path);
		exit(ret);
	}
	return (input);
}

/**
 * main - Sipmple shell main.
 *
 * Return: 0 (Success).
 */

int main(int argc, char *argv[])
{
	const char *prompt = "$ ";
	char *input = NULL, **buff = NULL, *cmnd = NULL, *path = NULL;
	int fd_isatty = 0, ret = 0;

	path = _getenv();
	while (1)/*infinite while loop for the shell*/
	{
		fd_isatty = isatty(STDIN_FILENO);
		if (fd_isatty)
			printf("%s", prompt);
		input = _getline(path, ret, fd_isatty);
		buff = create_buff(input, path);
		if (buff != NULL)
		{
			if (strcmp(buff[0], "exit") == 0)
				exit_program(buff, input, path, ret);

			else if (strcmp(buff[0], "env") == 0)
				ret = print_env();
			else 
			{
				cmnd = strdup(buff[0]);
				if (status(buff, path) == 0)
					ret = child_process(buff, path);
				else
				{
					buff[0] = _which(buff, path);
					if (buff[0] != NULL)
						ret = child_process(buff, path);
					else
						ret = not_found(argv, argc, cmnd);
				}
				free(cmnd);
			}
			free_buff(buff);
		}
		free(input);
	}
	free(path);
	exit(ret);
}
