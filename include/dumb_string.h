#ifndef DUMB_STRING_H
#define DUMB_STRING_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int dumb_puts(const char *s);

size_t dumb_strlen(const char *s);

size_t dumb_strnlen(const char *s, size_t maxlen);

const char *dumb_strchr(const char *s, int c);

char *dumb_strcpy(char *restrict dst, const char *restrict src);

char *dumb_stpcpy(char *restrict dst, const char *restrict src);

char *dumb_strncpy(char dst[], const char *restrict src, size_t sz);

char *dumb_strcat(char *restrict dst, const char *restrict src);

char *dumb_strncat(char *restrict dst, const char *restrict src, size_t sz);

char *dumb_fgets(char s[], int size, FILE *restrict stream);

char *dumb_strdup(const char *s);

size_t dumb_getline(char **restrict lineptr,
                     size_t *restrict n,
                     FILE *restrict stream);


#endif

