#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "command.h"

#define MAX_INPUT 1024

void terminal_run()
{
	char input[MAX_INPUT];
	char* cwd;
	while(1)
	{
		cwd = t_getcwd();
		if(cwd != NULL)
		{
			printf("%s$",cwd);
			if(fgets(input,sizeof(input),stdin) == NULL)
			{
				perror("fgets failed");
				exit(EXIT_FAILURE);
			}
			input[strcspn(input, "\n")] = '\0';
			if(strcmp(input,"exit") == 0)
			{
				break;
			}
			parse_command(input);
		}
		else 
		{
			perror("cwd failed");
			exit(EXIT_FAILURE);
		}
	}
	free(cwd);
}
