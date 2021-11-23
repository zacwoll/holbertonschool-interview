# 0x1E Wild Compare

## Write a function that compares two strings and returns 1 if the strings can be considered identical, otherwise return 0.

- Prototype: int wildcmp(char *s1, char *s2);
- s2 can contain the special character *.
- The special char * can replace any string (including an empty string)

```
alexa@ubuntu:~/0x1E-wild_cmp$ cat 0-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = wildcmp("main.c", "*.c");
    printf("%d\n", r);
    r = wildcmp("main.c", "m*a*i*n*.*c*");
    printf("%d\n", r);
    r = wildcmp("main.c", "main.c");
    printf("%d\n", r);
    r = wildcmp("main.c", "m*c");
    printf("%d\n", r);
    r = wildcmp("main.c", "ma********************************c");
    printf("%d\n", r);
    r = wildcmp("main.c", "*");
    printf("%d\n", r);
    r = wildcmp("main.c", "***");
    printf("%d\n", r);
    r = wildcmp("main.c", "m.*c");
    printf("%d\n", r);
    r = wildcmp("main.c", "**.*c");
    printf("%d\n", r);
    r = wildcmp("main-main.c", "ma*in.c");
    printf("%d\n", r);
    r = wildcmp("main", "main*d");
    printf("%d\n", r);
    r = wildcmp("abc", "*b");
    printf("%d\n", r);
    return (0);
}
alexa@ubuntu:~/0x1E-wild_cmp$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-wildcmp.c -o 0-wildcmp
alexa@ubuntu:~/0x1E-wild_cmp$ ./0-wildcmp
1
1
1
1
1
1
1
0
1
1
0
0
alexa@ubuntu:~/0x1E-wild_cmp$
```

Solution
```
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
```