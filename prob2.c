/*
    contains solution to problem 2, in which the function binary_search() is called to search for a predefined target.
*/
#include "root.h"

int binary_search(int arr[], int target, int arr_size);

void problem2(void)
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr_size = sizeof(arr) / sizeof(*arr);
    int target, found_index;
    printf("Enter any number to search: ");
    scanf(" %d", &target);
    /* if found_index = -1, the target does not exist within the array */
    found_index = binary_search(arr, target, arr_size);
}

int binary_search(int arr[], int target, int arr_size)
{
    int left = 0, right = arr_size - 1;
    int found = 0, targetindex = -1;
    int mid = left + (right - left) / 2;

    /* only need to violate either condition to break the loop, either found = -1 or left == right */
    while (found == 0 && left != right)
    {
        mid = left + (right - left) / 2;
        /* return targetindex if found */
        if (arr[mid] == target)
        {
            targetindex = mid;
            found = 1;
        }
        /* otherwise continue to search by scaling down the array by half with each iterative step */
        else if (target > arr[mid])
            left = mid + 1;
        else if (target < arr[mid])
            right = mid - 1;
    }
    return targetindex;
}