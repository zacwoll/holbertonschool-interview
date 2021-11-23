#include <string.h>
#include <stdio.h>

/**
 * wildcmp - Compares two strings checking for equality, wildcard enabled
 * @s1: String to compare
 * @s2: String pattern to match
 * Return: 0 if false, 1 if true.
 */
int wildcmp(char *s1, char *s2) {

    // If we reach the end of both strings, we're done
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    // If s2 is a wildcard, move forward until after is not a wildcard
    if (*s2 == '*' && *(s2 + 1) == '*')
        s2++;

    // If the current characters of both strings match
    if (*s1 == *s2) {
        return wildcmp(s1+1, s2+1);
    }

    // If there is *, then there are two possibilities
    // a) We consider current character of s1 string
    // b) We ignore current character of s2 string.
    if (*s2 == '*') {
        return wildcmp(s1, s2+1) || wildcmp(s1+1, s2);
    }

    return (0);
}