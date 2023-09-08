#include <dumb_string.h>

char *dumb_strdup(const char *s) {
    char *newptr = calloc(strlen(s), sizeof(s[0]));
    if (!newptr) {
        dumb_strcpy(newptr, s);
    }
    return newptr;
}

