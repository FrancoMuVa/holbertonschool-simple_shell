#include "shell.h"

/**
 * status - check if found a file.
 * @buff: buffer.
 *
 * Return: 0 if file found, -1 otherwise.
 */

int status(char **buff)
{
	struct stat st;

	if (stat(buff[0], &st) == 0)
		return (0);
	else
		return (-1);
}

/**
 * _getenv - Get an PATH enviroment variable.
 *
 * Return: String with the value of the PATH environment variable.
 */

char *_getenv(void)
{
	const char *path = "PATH", *delim = "=\n";
	char *token = NULL, *env_cpy = NULL, *fin_token = NULL;
	int i = 0;

	/*search "PATH" in environ*/
	env_cpy = strdup(environ[i]);
	token = strtok(env_cpy, delim);
	while (token != NULL)
	{
		if (strcmp(token, path) == 0)
		{
			break;
		}
		i++;
		if (environ[i] == NULL)
		{
			free(env_cpy);
			return (NULL);
		}
		free(env_cpy);
		env_cpy = strdup(environ[i]);
		token = strtok(env_cpy, delim);
	}
	/*save the value of the PATH*/
	token = strtok(NULL, delim);
	if (token == NULL)
		return (NULL);
	else
	{
		fin_token = strdup(token);
		free(env_cpy);
		return (fin_token);
	}
}

/**
 * allocate_mem - allocate memory for check string.
 * @buff: user input.
 * @token: token.
 * @path: path.
 * @path_cpy: cpoy of the path.
 *
 * Return: String to check.
*/

char *allocate_mem(char **buff, char *token, char *path, char *path_cpy)
{
	char *test = NULL;

	test = malloc(sizeof(char) * (strlen(token) + strlen(buff[0]) + 2));
	if (test == NULL)
	{
		free(path);
		free(path_cpy);
		free(buff);
		exit(-1);
	}
	strcpy(test, token);
	return (test);
}

/**
 * _which - find a file in the PATH.
 * @buff: path of executable to find.
 * @path: value of PATH enviroment variable.
 *
 * Return: Path of executable (if found), NULL Otherwise.
 */

char *_which(char **buff, char *path)
{
	const char *delim = ":\n";
	struct stat st;
	char *path_cpy, *token = NULL, *test = NULL;

	/*if @path is NULL = PATH doesnt exist in the "environ"*/
	if (path == NULL)
		return (NULL);

	/*creates a new string (path) in @buff[0] to find in the @path the command*/
	path_cpy = strdup(path);
	token = strtok(path_cpy, delim);
	while (token != NULL)
	{
		test = allocate_mem(buff, token, path, path_cpy);
		strcat(test, "/");
		strcat(test, buff[0]);
		/*check if the path created exist*/
		if (stat(test, &st) == 0)
		{
			free(buff[0]);
			buff[0] = malloc(sizeof(char) * strlen(test) + 1);
			if (buff[0] == NULL)
			{
				free(path_cpy);
				free(test);
				free(buff);
				exit(-1);
			}
			strcpy(buff[0], test);
			free(path_cpy);
			free(test);
			return (buff[0]);
		}
		free(test);
		token = strtok(NULL, delim);
	}
	free(path_cpy);
	free(buff[0]);
	return (NULL);
}
