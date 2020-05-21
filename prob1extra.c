#include "root.h"

int strlen_recursive(char *string);

void problem1extra(void)
{
    char str1[15] = "abcdef";
    int length = 0;
    length = strlen_recursive(str1);
    printf("len = %d", length);
}

int strlen_recursive(char *string)
{
    int i = 0;
    if (*(string) != '\0')
    {
        i = strlen_recursive(string + 1);
        return i + 1;
    }
    else
        return 0;
}