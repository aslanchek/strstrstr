#include <dumb_string.h>

// TODO: when returning non-const char* any cast discards const qualifier
//       so can I return const?
const char *dumb_strchr(const char *s, int c) {
    do {
        if ( *s == c ) {
            return s; 
        }
    } while ( *s++ );
    return NULL;
}

