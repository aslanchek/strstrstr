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
 fgets   ++++
 strdup  +
 * getline
 */

void DUMP_BUFFER(char *buffer, size_t sz);

void DUMP_BUFFER(char *buffer, size_t sz) {
    fprintf(stderr, "buff: >");

    for (size_t i = 0; i < sz; i++) {
        char tmp = buffer[i];
        switch(tmp) {
            case '\n': 
                fprintf(stderr, "%c", '|'); // '|' stands for \n
                break;
            case '\0':
                fprintf(stderr, "%c", '_'); // '_' stands for \0
                break;
            default: 
                fprintf(stderr, "%c", tmp);
                break;
        }
    }

    fprintf(stderr, "<\n");
}

#define TEST(name, str) if (name(str) == dumb_##name(str) printf("OK")

int main() {
    {
        char str[] = "abcdefg";

        puts("\nTEST: puts(str)");
        dumb_puts(str);
        puts(str);
    
        // TEST: strlen()
        assert( strlen(str) == dumb_strlen(str));
    }

    {
        puts("\nTEST: strcpy(dst, src)");
        char src[] = "Hello World";
        char dst[256] = {};
        printf("src : %s\n", src);
        printf("dest: %s\n", dst);
        dumb_strcpy(dst, src);
        printf("src : %s\n", src);
        printf("dest: %s\n", dst);
    }

    {
        puts("\nTEST: strchr(str, 'W')");
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
        puts("\nTEST: strncpy(dst, src, 4)");
        char src[] = "Hello World";
        char dst[256] = {};
        printf("src : %s\n", src);
        printf("dest: %s\n", dst);

        dumb_strncpy(dst, src, 4);

        printf("src : %s\n", src);
        printf("dest: %s\n", dst);
    }

    {
        puts("\nTEST: strncpy(buff, sample, 4)");
        char buff[6] = { };
        memset(buff, 'a', 5);
        // buff -> aaaaaa00asd
        // buff -> Hellaa00asd
        char sample[] = "Hello world";

        printf("sample: %s\n", sample);
        printf("buff  : %s\n", buff);

        dumb_strncpy(buff, sample, 4);

        printf("sample: %s\n", sample);
        printf("buff  : %s\n", buff);

        memset(buff, 0, 6);
    }

    {
        puts("\nTEST: strcat(dest, src)");
        char src[] = " World";
        char dst[256] = "Hello";
        printf("src : %s\n", src);
        printf("dest: %s\n", dst);

        dumb_strcat(dst, src);

        printf("src : %s\n", src);
        printf("dest: %s\n", dst);
    }

    {
        puts("\nTEST: strncat(dest, src, 4)");
        char src[] = " World";
        char dst[256] = "Hello";
        printf("src : %s\n", src);
        printf("dest: %s\n", dst);

        dumb_strncat(dst, src, 4);

        printf("src : %s\n", src);
        printf("dest: %s\n", dst);
    }    

    {
        puts("\nTEST: strncat(dest+1, src, 5)");

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
        puts("\nTEST: fgets(buff, 16, file)");
        {
            FILE *f = fopen("test.txt", "r");
            char buff[16] = {};
            puts("fgets() from stdio.h");
            fgets(buff, 16, f);
            DUMP_BUFFER(buff, 16);
        }

        {
            FILE *f = fopen("test.txt", "r");
            char buff[16] = {};
            puts("fgets() from dumb_string.h");
            dumb_fgets(buff, 16, f);
            DUMP_BUFFER(buff, 16);
        }
    }

    {
        puts("\n TEST: strdup(str)");
        char str[] = "Hello World!";

        {
            puts("strdup() from stdio.h");
            char *p = strdup(str);
            fprintf(stderr, "allocated ptr: %p\n", p);
            dumb_puts(p);
            free(p);
        }

        {
            puts("dumb_strdup() from dumb_string.h");
            char *p = dumb_strdup(str);
            fprintf(stderr, "allocated ptr: %p\n", p);
            dumb_puts(p);
            free(p);
        }
    }

    return 0;
}

