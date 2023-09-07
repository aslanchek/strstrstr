#include <dumb_string.h>

/*
 * strcat() semantics:
 *
 *      _____________________________________
 *      | | |A|B|C|0| | | | | | | |D|E|F|0| |
 *      -------------------------------------
 *           ^                     ^                                       
 *           dst                   src                
 *      _____________________________________
 *      | | |A|B|C|D|E|F|0| | | | |D|E|F|0| |
 *      -------------------------------------
 *           ^                                                            
 *           dst                                                                
 *                     
 */
char *dumb_strcat(char *restrict dst, const char *restrict src) {
    char* last = mempcpy(dst + dumb_strlen(dst), src, dumb_strlen(src));
    *last = '\0';
    return dst;
}

