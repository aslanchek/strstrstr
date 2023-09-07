#include <dumb_string.h>

char *dumb_strcpy(char *restrict dst, const char *restrict src) {
    char *save = dst;

    while ( (*dst = *src) ) {
        ++dst;
        ++src;
    }

    return save;
}

