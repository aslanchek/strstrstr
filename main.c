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
 strncpy +
 strcat  ++
 strncat +?
 fgets   +
 * strdup
 * getline
 */

int main() {
    {
        char str[] = "abcdefg";

        puts("\nTEST: puts()");
        dumb_puts(str);
        puts(str);
    
        // TEST: strlen()
        assert( strlen(str) == dumb_strlen(str));
    }

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
        puts("\nTEST: strchr()");
        const char str[] = "Hello World";
        char tofind = 'W';

        char *found = strchr(str, tofind);
        //char *found = str + 6;

        printf("find %c in %s\n", tofind, str);
        printf("str  : %p\n", str);
        printf("found: %p\n", found);
        *found = 'Z';
        printf("str  : %s\n", str);
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
        puts("\nTEST: strncpy()");
        char buff[6] = { };
        memset(buff, 'a', 5);
        // buff -> aaaaaa00asd
        // buff -> Hellaa00asd
        char sample[] = "Hello world";

        printf("src : %s\n", sample);
        printf("dest: %s\n", buff);

        dumb_strncpy(buff, sample, 4);

        printf("src : %s\n", sample);
        printf("dest: %s\n", buff);

        memset(buff, 0, 6);
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

    {
        puts("\nTEST: strncat()");

        char buff[24] = {};
        memset(buff, 'a', 10);
        buff[1] = '\0';
        char sample[] = "Hi";

        printf("src : %s\n", sample);
        printf("dest: %s\n", buff);

        dumb_strncat(buff+1, sample, 5);

        printf("src : %s\n", sample);
        printf("dest: %s\n", buff);   
    }    

    {
        char buff[10] = {};
        fprintf(stderr, "----------------\n");
        dumb_fgets(buff, 3, stdin);
        fflush(stdout);
        //fgets(buff+1, 3, stdin);
        fprintf(stderr, "\n%s", buff);
        fprintf(stderr, "----------------\n");
    }
    {
        char buff[10] = {};
        fprintf(stderr, "----------------\n");
        //dumb_fgets(buff, 3, stdin);
        fgets(buff, 3, stdin);
        fprintf(stderr, "\n%s", buff);
        fprintf(stderr, "----------------\n");
    }


    return 0;
}

