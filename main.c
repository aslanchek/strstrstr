#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <dumb_string.h>

/*
 *      ___________________________________________________________________
 *      | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
 *      -------------------------------------------------------------------
 */

/*!
 puts    +
 strchr  +
 strlen  +
 strcpy  +
 strncpy
 strcat
 strncat
 fgets
 * strdup
 * getline
 */

int main() {
    char str[] = "abcdefg";

    puts("\nTEST: puts()");
    dumb_puts(str);
    puts(str);
    
    // TEST: strlen()
    assert( strlen(str) == dumb_strlen(str));

    {
        puts("\nTEST: strcpy()");
        char src[] = "Hello World";
        char dst[256] = {};
        printf("src : %s\n", src);
        printf("dest: %s\n", dst);
        dumb_strcpy(dst, src);
        printf("src : %s\n", src);
        printf("dest: %s\n", dst);
    }

    {
        puts("\nTEST: strncpy()");
        char src[] = "Hello World";
        char dst[256] = {};
        printf("src : %s\n", src);
        printf("dest: %s\n", dst);

        dumb_strncpy(dst, src, 4);

        printf("src : %s\n", src);
        printf("dest: %s\n", dst);
    }

    {
        puts("\nTEST: strcat()");
        char src[] = " World";
        char dst[256] = "Hello";
        printf("src : %s\n", src);
        printf("dest: %s\n", dst);

        dumb_strcat(dst, src);

        printf("src : %s\n", src);
        printf("dest: %s\n", dst);
    }

    {
        puts("\nTEST: strncat()");
        char src[] = " World";
        char dst[256] = "Hello";
        printf("src : %s\n", src);
        printf("dest: %s\n", dst);

        dumb_strncat(dst, src, 4);

        printf("src : %s\n", src);
        printf("dest: %s\n", dst);
    }    


    return 0;
}

