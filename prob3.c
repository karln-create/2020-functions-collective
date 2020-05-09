/*
    contains the solution for the bubble sorting technique.
*/
#include "root.h"

void bubble_sort(char *ptrstrings[], int num_strings);

void problem3(void)
{
    char *arr_strings[] = {"prstu", "fghij", "uvxyz", "abcde", "klmno"};

    int num_strings = (int)sizeof(arr_strings) / (int)sizeof(*arr_strings);
    bubble_sort(arr_strings, num_strings);
}

void bubble_sort(char *ptrstrings[], int num_strings)
{
    int c = 1, u = num_strings - 1;
    char *tempstr = '\0';
    /* outer control loop, failsafe to make sure that the inner loop resets properly and does not miss any string */
    for (; u > 0; u--)
    {
        /* inner control loop, reset with each fresh decremented u to check for any unordered string */
        for (c = 1; c <= u; ++c)
        {
            /* compare the strings then swap their address if condition is met */
            if (strcmp(ptrstrings[c - 1], ptrstrings[c]) > 0)
            {
                tempstr = ptrstrings[c - 1];
                ptrstrings[c - 1] = ptrstrings[c];
                ptrstrings[c] = tempstr;
            }
        }
    }
}