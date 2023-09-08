#include <dumb_string.h>

/*
 *
 *
 */
char *dumb_strdup(const char *s) {
    char *newstr = calloc(strlen(s), sizeof(s[0])); // -> 
    dumb_strcpy(newstr, s);
    return newstr;
}
