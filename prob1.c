/*
    contains solution for problem #1, in which the function my_str_n_cat() is called to concatenate two predefined strings.
*/
#include "root.h"

char *my_str_n_cat(char *dest, char *source, int n);

void problem1(void)
{
    char str1[15] = "abcdef";
    char str2[15] = "uvxyz";

    int n;
    scanf(" %d", &n);
    printf("new string: %s", my_str_n_cat(str1, str2, n));
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