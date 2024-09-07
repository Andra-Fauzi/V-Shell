#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_INPUT 1024

char* t_getcwd() 
{
	char* cwd = (char*)malloc(sizeof(char) * MAX_INPUT);
	if(getcwd(cwd,MAX_INPUT) != NULL)
	{
		return cwd;
	}
		perror("getcwd() error");
		return NULL;
}

void terminal_run()
{
	char input[MAX_INPUT];
	while(1)
	{
		char* cwd = t_getcwd();
		if(cwd != NULL)
		{
			printf("%s$",cwd);
			if(fgets(input,sizeof(input),stdin) == NULL)
			{
				perror("fgets failed");
				exit(EXIT_FAILURE);
			}
		}
		else 
		{
			perror("cwd failed");
			exit(EXIT_FAILURE);
		}
		free(cwd);
	}
}
