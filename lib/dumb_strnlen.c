#include <dumb_string.h>
// abc\0 , 2
// ^
// s
size_t dumb_strnlen(const char *s, size_t maxlen) {
    for (size_t i = 0; i < maxlen - 1; i++) {
        if ( !(*s++) ) {
            return i;
        }
    }
    return maxlen;
}

