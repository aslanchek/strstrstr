#include <dumb_string.h>

char *dumb_strchr(const char *s, int c) {
    do {
        if ( *s == c ) {
            return (char *) s; // TODO: any cast discards const qualifier
        }
    } while ( *s++ );
    return NULL;
}

