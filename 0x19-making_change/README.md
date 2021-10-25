# 0x19. Making Change

Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount total.

- Prototype: def makeChange(coins, total)
- Return: fewest number of coins needed to meet total
    - If total is 0 or less, return 0
    - If total cannot be met by any number of coins you have, return -1
- coins is a list of the values of the coins in your possession
- The value of a coin will always be an integer greater than 0
- You can assume you have an infinite number of each denomination of coin in the list
- Your solution’s runtime will be evaluated in this task

```
carrie@ubuntu:~/0x19-making_change$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

makeChange = __import__('0-making_change').makeChange

print(makeChange([1, 2, 25], 37))

print(makeChange([1256, 54, 48, 16, 102], 1453))

carrie@ubuntu:~/0x19-making_change$
carrie@ubuntu:~/0x19-making_change$ ./0-main.py
7
-1
carrie@ubuntu:~/0x19-making_change$
```

## Discussion

[Great videa that really stressed the optimization of solutions concept](https://www.youtube.com/watch?v=jgiZlGzXMBw)

The goal is to find the fewest coins that make up the given total.
So It's about collecting all the ways to find the fewest coins that make up the parts

if I follow this example and create
use the parameters coins = [1, 5, 10] and try to reach N=8
Geeks for Geeks has me create an array of ways, length N+1
Array of ways
[0, 0, 0, 0, 0, 0, 0, 0, 0]
Index of array of ways
[0, 1, 2, 3, 4, 5, 6, 7, 8]

how many ways to make 0? 0 ergo ways[0] = 0
how many ways to make 1? using the first coin, 1, there is 1
how many ways to make 2 .. N
the solution is [range(1,8)]

but what are the fewest ways to do the same?
still [range(1,8)]

what if I used coins[1] now?
still operating off of the same array of ways
fewest coins to make [0-8]
Array of ways
[0, 1, 2, 3, 4, 1, 2, 3, 4]
Index of array of ways
[0, 1, 2, 3, 4, 5, 6, 7, 8]

what if I used 8 now?
[0, 1, 2, 3, 4, 1, 2, 3, 1]

Then, I *read* the answer off the last number in the array, this is the *bottom up* solution to this problem

I **replaced** the value when I was able to create a fewer total of coinage, whats more, I also know the smallest way to make 5 is with 1 coin. Tabulating from the bottom up helps find *optimizations* that guarantee the result.

Let's talk `code`
```
def makeChange(coins, total):
    """
    Returns the fewest number of coins needed to meet a given amount total
    """
```
First, I need to create the 'array of minimum ways'
```
    # create the 'array of ways'
    matrix = [total + 1] * (total + 1)
    matrix[0] = 0
```
An array is created that has a number larger than the total in total + 1 places. This is to ensure that we have a zero :).
We'll compute the minimum ways to make 1-total, denoted by their index in the array.
```
    # for each step of the matrix, l -> r
    for n in range(1, total + 1):
        # look at each coin in matrix
        for coin in coins:
            # if n (index of matrix) minus coin is greater than 0
            if n - coin >= 0:
                # Then we must be able to remove a coin
                # Thus making the count of coins necessary less
                # we'll check the min to set the new lower value
                matrix[n] = min(matrix[n], 1 + matrix[n - coin])
```
Each iteration of the top loop, will run a bottom up tabulation of the minimum coins necessary to compute the nth index of our matrix. By removing a coin, the remainder of the total that's left *is already present* in our matrix, so we just need to point to it.

At the end of our loops, the last position of the matrix, corresponding to N, will contain the fewest number of coins. Unless we weren't able to find a configuration that made up that number, in which case, we left an impossible number in it's place
```
return matrix[total] if matrix[total] < total + 1 else -1
```
We return the fewest coins, or -1 for false