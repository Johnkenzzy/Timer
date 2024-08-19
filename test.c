#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>


int main(void)
{
	char *input = NULL;
	size_t input_len = 0;
	char *split_str = NULL;
	char **argv;
	pid_t pid;
	int status;
	struct stat st;

	while (1)
	{
		printf("simple_shell$ ");

		//Read user input
		ssize_t read = getline(&input, &input_len, stdin);
		if (read == -1)
		{
			free(input);
			perror("getline");
			exit(1);
		}

		//Parse the input into argument: removes whitespace, tab & newline
		int i = 0;
		char *delim = " \t\n";
		int _strlen = strlen(input);

		argv = malloc(sizeof(char *) * _strlen);
		argv[i] = strtok(input, delim);
		while(argv[i] != NULL && i < _strlen)
		{
			i++;
			argv[i] = strtok(NULL, delim);
		}
		//Null-terminate the argument list
		argv[i] = NULL;

		//Exit shell if a user types "exit"
		if (argv[0] == NULL)
		{
			continue;
		}
		else if (strcmp(argv[0], "exit") == 0)
		{
			break;
		}

		//Handle the absence of an excutable
		if (stat(argv[0], &st) == -1)
		{
			perror("stat");
			//code to restart the process. lets exit for now
			exit(1);
		}

		//Create a child process
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(1);
		}

		//Child process
		if (pid == 0)
		{
			//Execute the command conditionally
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("execve");
				exit(1);
			}
		}
		else
		{
			//Parent process
			//Waiting for the child process to finish
			if (wait(&status) == -1)
			{
				perror("wait");
				exit(1);
			}
		}

		free(input);
		input = NULL;
	}

	return (0);
}
