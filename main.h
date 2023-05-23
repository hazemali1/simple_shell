#ifndef _HEADER_
#define _HEADER_
#define BUFSIZE 1024

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
void strtoken(char *, int);
void resetFunc(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
