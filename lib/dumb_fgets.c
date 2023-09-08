#include <dumb_string.h>

/*
 * Читает до size-1 символов из stream и помещает из в
 * s. Чтение прекращается когда встретит EOF или \n. \n записывается в
 * буффер. Нуль-терминатор записывается в буффер после последнего символа
 *
 * size-1 для того, чтобы в буффер размера size влезла строка + \0
 *
 *
 *
 *          ___________________________________________________________________
 *  stdin-->| | | | |H|e|l|l|o| |w|o|r|l|d|0| | | | | | | | | | | | | | | | | |
 *          -------------------------------------------------------------------
 *                   0 1 2 3 4 5 6 7 8 9                                        
 *                                                                              
 *                                                                              
 *                     fgets(buf[.sz = 20], 20, stdin);                   
 *          ___________________________________________________________________
 *          | | | | | |H|e|l|l|o| |w|o|r|l|d|0| | | | | | | | | | | | | | | | |
 *          -------------------------------------------------------------------
 *                     ^ buf                                                             
 *
 *                     fgets(buf[.sz = 5], 5, stdin);                   
 *          ___________________________________________________________________
 *          | | | | | |H|e|l|l|0| | | | | | | | | | | | | | | | | | | | | | | |
 *          -------------------------------------------------------------------
 *                     ^ buf                                                             
 *
 */  
char *dumb_fgets(char s[], int size, FILE *restrict stream) {

    if (feof(stream) && ferror(stream)) {
        fprintf(stderr, "fgets panic!");
        return NULL;
    }

    int i = 0;
    for (; i < size - 1; i++) {
        int tmp = getc(stream);

        if (feof(stream) || ferror(stream)) {
            if (i == 0) {
                return NULL;
            }

            s[i] = '\0';
            return s;
        } else if (tmp == '\n') {
            s[i] = '\n';
            s[i+1] = '\0';
            return s;
        } else if (tmp == '\0') {
            s[i] = '\0';
            return s;
        } else {
            s[i] = (char) tmp;
        }
    }

    s[i] = '\0';
    return s;
}

