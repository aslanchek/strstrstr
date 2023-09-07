#include <dumb_string.h>

/*!
 * Как работает mempcpy(const void *dest, const void *src, size_t size):
 *          копирует из объекта который лежит под src в объект под dest size раз,
 *          возвращает указатель на байт после последнего записанного (see chain calls)
 *
 *      _____________________________________
 *      | | | | | | | |A|B|C|D|0| | | | | | |
 *      -------------------------------------
 *                     ^                                                    
 *                     src                   size = 4;
 *      _____________________________________
 *      | | | | | | | |A|B|C|D|0| | | | | | |
 *      -------------------------------------
 *                     ^       ^                                            
 *                     dest    return value: dest + n                                   
 *                                                                          
 *                                                                          
 */
char *dumb_strncat(char *restrict dst, const char *restrict src, size_t sz) {
    // REDUCE OVERLAPS COUNT
    size_t len = dumb_strnlen(src, sz);
    char* first = dst + dumb_strlen(dst);

    char* last = mempcpy(first, src, len);
    *last = '\0';

    return dst;
}

