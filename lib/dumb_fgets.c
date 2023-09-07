#include <dumb_string.h>

/*
 * Читает по крайней мере size-1 символов из stream пока не встретит EOF или \n
 *
 * size-1 для того, чтобы в буффер размера size влезла строка + \0
 *
 *                     fgets(buf[.sz = 5], 5, stdin);                   
 *
 *
 *          ___________________________________________________________________
 *  stdin-->| | | | |H|e|l|l|o| |w|o|r|l|d|0| | | | | | | | | | | | | | | | | |
 *          -------------------------------------------------------------------
 *                   0 1 2 3 4 5 6 7 8 9                                        
 *                                                                              
 *                                                                              
 *          ___________________________________________________________________
 *          | | | | | |H|e|l|l|0| | | | | | | | | | | | | | | | | | | | | | | |
 *          -------------------------------------------------------------------
 *                     ^ buf                                                             
 */  
char *dumb_fgets(char s[], int size, FILE *restrict stream) {
    int i = 0;
    for (; i < size - 1; i++) {
        int tmp = getc(stream);
            if ( tmp != EOF  ) {
                s[i] = (char)tmp;

                if ( tmp == '\n' ) {
                    break;
                }
            } else {
                break;
            }
        }
    s[i + 1] = '\0'; // TODO: i or i+1 ??? consider EOF variant
    return s;
}

