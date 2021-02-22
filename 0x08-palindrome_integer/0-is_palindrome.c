#include <stdio.h>

/**
  * is_palindrome - determines if unsigned long is palindromic
  * @n: number in question
  * Return: 1 if true, 0 if false
  */
int is_palindrome(unsigned long n)
{
    unsigned long remainder, sum = 0, temp;

    temp = n;
    while (n > 0) {
        remainder = n % 10;
        sum = sum * 10 + remainder;
        n /= 10;
    }
    if (temp == sum)
        return (1);
    else
        return (0);
}