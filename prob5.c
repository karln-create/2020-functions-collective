/*
    contains solution to problem 5, in which the function sum_primes() is called.
*/
#include "root.h"

unsigned int sum_primes(unsigned int num);
unsigned int check_prime(unsigned int num);

void problem5(void)
{
    unsigned int num, sum = 0;
    printf("Enter an positive integer: ");
    scanf(" %d", &num);
    sum = sum_primes(num);
    printf("Sum of all primes from 2 to n: %d", sum);
}

/* calculate the sum of all prime numbers from n to 2 */
unsigned int sum_primes(unsigned int num)
{
    if (num > 1)
    {
        num = check_prime(num) + sum_primes(num - 1);
        return num;
    }
    else
        return 0;
}

/* check if the passed number is a prime number */
unsigned int check_prime(unsigned int num)
{
    unsigned int i = 2, remainder = num % 2;
    while (i != num && remainder != 0)
    {
        remainder = num % (unsigned int)i;
        ++i;
    }
    if (i == num)
        return num;
    else
        return 0;
}

/*
    SOME THOUGHTS:
    This problem took me a long time and I couldn't even solve it. Took me half a day, which then burned me out and made me not wanting to write code for problem 4 as well.

    Now that I have looked at the solution, I realized I got tunnel visioned and was trying to do too many things at the same time.
    I was trying to do two tasks within one function: checking for primes and calculating the sum from checked primes.

    I simply don't have enough experience on writing algorithm and recursive function. That's why I didn't even see that I made the mistake from the very beginning.
    I should have slow down and actually drawn out the algorithm on paper/whiteboard (what I usually do best). Then I might have seen that I needed to break up the steps further down.

    I didn't do that so I didn't understand the problem completely. Instead, I jumped straight into writing the code.
    I was solving a problem I didn't understand. And that is why I couldn't solve it.

    It's a good lesson to learn. Always break everything down singular tasks.

    Going forward:
    - Itemize and list all actions, each starting with a verb.
    - Count the number of verbs, and that is the total number of actions/tasks needed to be executed.
*/