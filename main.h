#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

void executeCommand(char *command);
char *readCommand();
void displayPrompt(void);

#endif /* MAIN_H */
