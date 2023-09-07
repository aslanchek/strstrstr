#include <dumb_string.h>

size_t dumb_strlen(const char *s) {
    size_t count = 0;

    while ( *s++ ) {
        count++;
    }

    return count;
} 

