#include <dumb_string.h>

char *dumb_strcpy(char *restrict dst, const char *restrict src) {
    char *dst_ptr = dst;

    while ( *dst =  *src  ) {
        ++dst;
        ++src;
    }

    return dst_ptr;
}

