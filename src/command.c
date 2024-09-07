#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024

enum COMMANDS
{
	CD		= 0,
	PWD		= 1,
	EXTERNAL 	= 99,
};

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

void change_directory()
{
}

void parse_command(char* cmd)
{
	switch(cmd)
	{
		case "cd"
	}
}

void run_command(char *cmd) {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    
    if (pid == 0) {
        // Child process
        char *argv[] = { "/bin/sh", "-c", cmd, NULL };
        execvp(argv[0], argv);
        
        // If execvp fails
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

