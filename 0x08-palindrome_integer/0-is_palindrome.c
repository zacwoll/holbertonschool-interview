#include <stdio.h>

/**
  * find_listint_loop - Floyd's Tortoise and Hare, finds loop in list
  * @head: head of the list
  * Return: listint_t address of loop
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