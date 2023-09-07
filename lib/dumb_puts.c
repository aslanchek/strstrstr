#include <dumb_string.h>

int dumb_puts(const char *s) {
    int count = 0;
    while ( *s ) {
        if( putchar(*s++) == EOF) {
            return EOF;
        }
        count++;
    }
    count++;
    if( putchar('\n') == EOF ) {
        return EOF;
    }
    return count;
}

