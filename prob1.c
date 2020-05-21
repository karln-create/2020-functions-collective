/*
    contains solution for problem #1, in which the function my_str_n_cat() is called to concatenate two predefined strings.
*/
#include "root.h"

char *my_str_n_cat(char *dest, char *source, int n);
char *my_strcpy(char *destination, const char *source, int n);
int strlen_recursive(char *string);

void problem1(void)
{
    char str1[15] = "abcdef";
    char str2[15] = "uvxyz";

    int n;
    scanf(" %d", &n);
    printf("new string: %s", my_str_n_cat(str1, str2, n));

    int length = strlen_recursive(str1);
    printf("strlength = %d", length);
}

char *my_str_n_cat(char *dest, char *source, int n)
{
    int i = 0, j = 0;
    /* move the cursor to the tail end of the destination string */
    for (; *(dest + i) != '\0'; ++i)
        ;
    /* start appending the source string to the tail end of the destination string, break if encountering '\0' or if j reaches the nth character */
    for (; *(source + j) != '\0'; ++j)
    {
        if (*(source + j) == '\0' || j == n)
            break;

        *(dest + i + j) = *(source + j);
    }

    return dest;
}

char *my_strcpy(char *destination, const char *source, int n)
{
    int i, j;
    for (i = 0; *(source + i) != '\0'; ++i)
        ;

    if (n <= i)
    {
        for (j = 0; j <= n; ++j)
            *(destination + j) = *(source + j);
    }

    else
    {
        for (j = 0; j <= i; ++j)
            *(destination + j) = *(source + j);

        for (; j <= n; ++j)
            *(destination + j) = '\0';
    }

    return destination;
}

char *my_strncat(char *destination, char *source, int n)
{
    int i, j;
    for (i = 0; *(destination + i) != '\0'; ++i);

    if (n <= i)
    {
        for (j = 0; j <= n; ++j)
            *(destination + i + j) = *(source + j);
    }
    else
    {
        for (j = 0; *(source + j) != '\0'; ++j)
            *(destination + i + j) = *(source + j);
    }

    return destination;
}

int strlen_recursive(char *string)
{
    int i = 0;
    if (*(string) == '\0')
        return 0;
    
    strlen_recursive(string + 1);
    return ++i;
    
}