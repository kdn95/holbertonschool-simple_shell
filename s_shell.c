#include "ssh_header.h"
#define MAX_COMMAND_LENGTH 100
/**
 * main - simple shell interative entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
char *command = NULL;
size_t len = 0;
char *args[] = {NULL};
char *delimeter = " \n";
char *token;
pid_t pid;
int status;
while (1)
{
printf("$ ");
fflush(stdout);
if (getline(&command, &len, stdin) == -1)
{
printf("\n");
free(command);
break;
}
int argc = 0;
token = strtok(command, delimeter);
while (token != NULL && argc < MAX_COMMAND_LENGTH)
{
args[argc++] = token;
token = strtok(NULL, delimeter);
}
args[argc] = NULL;
pid = fork();
if (pid == -1)
{
perror("fork");
free(command);
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execv(command, args) == -1)
{
perror("execv");
exit(EXIT_FAILURE);
}
}
else
{
if (wait(&status) == -1)
{
perror("wait");
free(command);
exit(EXIT_FAILURE);
}
}
}
free(command);
return (0);
}
