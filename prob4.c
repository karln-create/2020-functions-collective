/*
    contains solution to problem 4, checking whether a string is a palindrome.
*/
#include "root.h"

int is_palindrome(char *my_str, int left, int str_len);

void problem4(void)
{
    char *strn = {"race car"};
    unsigned int str_len = (unsigned int)sizeof(strn) / sizeof(char);
    is_palindrome(strn, 0, str_len);
}

/* check if the string is a palindrome */
int is_palindrome(char *my_str, int left, int str_len)
{
    /* if the left marker passes the right marker successfully, it's confirned a palindrome */
    if (left >= str_len)
    {
        printf("The string is a palindrome.\n");
        return 1;
    }
    /* while the string has not been fully checked, start from both ends and move toward the middle */
    else if (my_str[left] == my_str[str_len - 1])
    {
        return is_palindrome(my_str, left + 1, str_len - 1);
    }
    else
    {
        printf("The string is not a palindrome.\n");
        return 0;
    }
}