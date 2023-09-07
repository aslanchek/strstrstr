#include <dumb_string.h>

/* Зануляет буффер фиксированного размера и копирует строку в последовательность символов
 *      ____________________________________
 *      | | | | | | | |A|B|C|D|0|0| | | | | |
 *      -------------------------------------
 *                     ^                                                    
 *                     src                   size = 10;
 *      _____________________________________
 *      | | | | | | | |A|B|C|D|0|0|0|0|0|0| |
 *      -------------------------------------
 *                     ^-----------------^                                  
 *                     buff                                               
 *                                                                          
 */
char *dumb_strncpy(char dst[], const char *restrict src, size_t sz) {
    memset(dst, 0, sz);
    memcpy(dst, src, sz);
    // OR
    /*
    for (size_t i = 0; i < sz; i++) {
        dst[i] = src[i];
    }
    */
    return dst;
}

