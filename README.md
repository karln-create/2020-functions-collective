# KARL NORDEN, CPTS121.SECTION17
# PA8 - EXTRA CREDIT

# DESCRIPTION: Write functions which solve given problems:
0. RESOURCES:

    https://eecs.wsu.edu/~aofallon/cpts121/progassignments/PA8.htm
    https://github.com/chadrrobbins/Sum-Primes-Recursive/blob/master/functions.c

1. 

    Write a function called my_str_n_cat() that:     - accepts pointer to a destination character array, and
                                                    - accepts pointer to a source character array (assumed to be a string), and
                                                    - returns the pointer to the destination array.
        This function needs to copy at most n characters (one by one) from the source character array to the end of the destination character array.
        If a null character is encountered before n characters have been encountered, copying must stop.
        No functions in <string.h> are allowed.
    (*) Use pointer arithmetic to solve this problem.

2. 

    Write a function called binary_search().

3. 

    Write a function called bubble_sort() that:      - accepts an array of pointers to strings, and the number of strings as arguments, and
                                                    - returns nothing.
        This function sorts the strings according to the following algorithm:
        1. set the marker U for the unsorted section at the end of the list (U is an integer index value)
        2. while the unsorted section has more than one element do steps 3 through 7
        3.      set the current element marker C at the second element of the list (C is an integer index value)
        4.      while C has not passed U, do steps 5 and 6
        5.          if the item at position C is less than the item to its left, then exchange these two items
        6.          move C to the right one position
        7.      move U left one position
        8. stop.
    (*) impletation may not use strcpy(). You many only exchange or swap pointers, but NOT actually make copies of the strings.

4. 

    Write a recursive function called is_palindrome() that:  - accepts a pointer to a string and its length, and
                                                            - determines recursively if the string is a palindrome.
        The function must returns 1 for a palindrome, 0 otherwise.    
    (*) A palindrome is a sequence of symbols that maybe interpreted the same forward and backward.
        For example: "race car" is a palindrome.
    (*) White space should be ignored in solution.

5. 

    Write a recursive function called sum_primes() that:     - accepts an unsigned integer, n, as an argument, and
                                                            - returns the sum of all primes from 2 to n.

6. 

    Write a function called maximum_occurances() that accepts:  - a pointer to a string (alphanumeric & whitespace characters only),
                                                               - a pointer to an array of struct occurances,
                                                               - a pointer to an integer, and
                                                               - a pointer to a character
    
    The struct is defined as:       typedef struct occurences {
                                        int num_occurences;
                                        double frequence;
                                    } Occurences;

    The function determines the frequency of each character found in the array.

    The frequency is defined as: let N(t) = total number of characters
                                     N(s) = number of one character symbol occured
                                then f(s) = N(s) / N(t), where f(s) = 0 for any non-occurant symbol.
    
    (*) The function should use the second array argument (of struct occurances) to keep track of each character.
        It also must returns through the pointers the maximum number of occurances of any one character, and the corresponding character for which the maximum represents.
        For example: input("test string"), in this string the letter 't' occurs 3 times, which is the maximum occurences for any one character within this string.
        
7. 

    Write a function called max_consecutive_integers() that accepts: - a two-dimensional array of signed integers,
                                                                    - the number of rows,
                                                                    - the number of cols,
                                                                    - one pointer as direct output parameter,
                                                                    - another pointer to pointer as indirect output parameter.

    The function finds the maximum of consecutive sequence of one integer.
    The first pointer stores the address of the start of maximum consecutive sequence of the same integer.
    The second pointer indirectly stores the number of the same consecutive integers in a row.

    (*) These seuquences may wrap from one row to the next.


# DEVELOPMENT HISTORY:
Update | 2020/05/08/Fri, 17:43 PDT

    PA8 completed.
    
Update | 2020/05/08/Fri, 14:35 PDT

    DONE: finished problem 6.
    TO-DO: problem 7.

Update | 2020/05/05/Tue, 19:33 PDT

    TO-DO: read and summarize problem 6.
    
Update | 2020/05/05/Tue, 18:29 PDT

    I couldn't figure out the recursive functions -- too difficult, so I looked up online and found a solution at: https://github.com/chadrrobbins/Sum-Primes-Recursive/blob/master/functions.c.

    The link also conveniently has solution for problem 5.

Update | 2020/05/05/Tue, 09:35 PDT

    So, for problem 3, it is important to understand that the pointer array holds the memory addresses of the strings. This degree of separation has the benefit of allowing us to manipulate the order of the strings simply by swapping their , without having to touch the values of strings at all.

Update | 2020/05/05/Tue, 09:10 PDT

    I think I figured out the process of the bubble sort function. I need to compare the strings at the addresses stored in the pointers then swap the addresses if needed.

Update | 2020/05/04/Mon, 16:46 PDT

    WIP: I'm vaguely starting to understand the problem but not quite there yet. It seems that I need to sort the pointers (to the strings) by their indirect values (or first character of each of the strings themselves). It seems I need to compare the values of the starting characters and then save the corresponding address to the sorted location.
    
Update | 2020/05/04/Mon, 16:28 PDT

    WIP: Not sure I understand problem 3 correctly. How am I supposed to sort the strings when the function accepts the array of pointers to the strings but not the strings? Do I sort the addresses?

Update | 2020/05/04/Mon, 14:01 PDT

    DONE: problem 2.
    TO-DO: problem 3: write an algorithm for the bubble sorting technique.

Update | 2020/05/04/Mon, 12:41 PDT

    DONE: problem 1.
    TO-DO: Problem 2: write a binary search function.

Update | 2020/05/01/Fri, 21:24 PDT

    First reading of the PA.
    TO-DO: finish breaking down the remaining problems (6 and 7).
    Project Direction: Make a separate *.c file for each problem. Each problem is self-contained in a void function, which will be called in main().