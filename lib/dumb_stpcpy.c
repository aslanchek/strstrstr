#include <dumb_string.h>

char *dumb_stpcpy(char *restrict dst, const char *restrict src) {
    while ( (*dst = *src)  ) {
        ++dst;
        ++src;
    }

    return dst;
}

