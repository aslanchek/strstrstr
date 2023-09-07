#include <dumb_string.h>
// abc\0 , 2
// ^
// s
size_t dumb_strnlen(const char *s, size_t maxlen) {
    size_t count = 0;

    while ( *s++ ) {
        count++;
    }

    return count < maxlen ? count : maxlen;
}

