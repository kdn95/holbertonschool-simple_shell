#ifndef _SS_LIB_H
#define _SS_LIB_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void parse_command(char *command, char *args[]);
void execute_command(char *command, char *args[]);
void non_interactive_mode(FILE *input_file);


#endif