# Dynamic Programming
## For me
I need dynamic programming to solve 0-making_change.py so I need a page for notes while I study it.

Dynamic Programming is mainly an optimization over plain recursion. Wherever we see a recursive solution that has repeated calls for same inputs, we can optimize it using Dynamic Programming.

The idea is to simply store the results of subproblems, so that we do not have to re-compute them when needed later. This simple optimization reduces time complexities from exponential to polynomial.

For example, if we write simple recursive solution for Fibonacci Numbers, we get exponential time complexity and if we optimize it by storing solutions of subproblems, time complexity reduces to linear.
```
// Recursion: Exponential
int fib(int n)
{
    if (n <= 1)
        return n;
        return fib(n-1) + fib(n-2);
}
// Dynamic Programming: Linear
f[0] = 0;
f[1] = 1;

for (i = 2; i <= n; i++)
{
    f[i] = f[i-1] + f[i-2];
}
return f[n];
```

## When is a problem a Dynamic Programming problem?
Dynamic Programming is an algorithmic paradigm that solves a given complex problem by breaking it into subproblems and stores the results of subproblems to avoid computing the same results again. Following are the two main properties of a problem that suggests that the given problem can be solved using Dynamic programming.
1. Overlapping Subproblems
2. Optimal Substructure

### Overlapping Subproblems
Dynamic Programming combines solutions to sub-problems. Dynamic Programming is mainly used when solutions of the same subproblems are needed again and again. In dynamic programming, computer solutions to subproblems are stored in a table so that these don't have to be recomputed. So Dynamic Programming is not useful when there are no common (overlapping) subproblems because there is no point storing the soutions if they are not needed again. For example, binary search doesn't have common subproblems, but the fibonacci numbers does!

#### Memoization (Top Down)
The memoized program for a problem is similar to the recursive version with a small modification that looks into a lookup table before computing solutions. We initialize a lookup array with all initial values as NIL. Whenever we need the solution to a subproblem, we first look into the lookup table. If the precomputed value is there then we return that value, otherwise we calculate the value and put the result in the lookup table so that it can be reused later.

check out this solution for fibonacci with a lookup table!!
```
# a program for Memoized version of nth Fibonacci number

# function to calculate nth Fibonacci number
def fib(n, lookup):

    # base case
    if n <= 1 :
        lookup[n] = n

    # if the value is not calculated previously then calculate it
    if lookup[n] is None:
        lookup[n] = fib(n-1 , lookup)  + fib(n-2 , lookup)

    # return the value corresponding to that value of n
    return lookup[n]
# end of function

# Driver program to test the above function
def main():
    n = 34
    # Declaration of lookup table
    # Handles till n = 100
    lookup = [None] * 101
    print "Fibonacci Number is ", fib(n, lookup)

if __name__=="__main__":
    main()
```
#### Tabulation (Bottom Up):
The tabulated program for a given problem builds a table in bottom-up fashion and returns the last entry from the tabe. For example, for the same Fibonacci number, we first calculate fib(0) then fib(1) then fib(2) then fib(3) and so on. So literally we are building the solutions of subproblems bottom-up.
```
# Python program Tabulated (bottom up) version
def fib(n):

    # array declaration
    f = [0] * (n + 1)

    # base case assignment
    f[1] = 1

    # calculating the fibonacci and storing the values
    for i in range(2 , n + 1):
        f[i] = f[i - 1] + f[i - 2]
    return f[n]

# Driver program to test the above function
def main():
    n = 9
    print "Fibonacci number is " , fib(n)

if __name__=="__main__":
    main()
```
#### Tabultion vs Memoization
Both tabulated and memoized solutions store the solutions of subproblems. In Memoized version, table is filled on demand while in the Tabulated version, starting from the first entry, all entries are filled one by one. Unlike the Tabulated version, all entries of the lookup table are not necessarily filled in Memoized version.
Tabulation => solve from the bottom up
Memoization => solve on demand from the top down

### Optimal Substructure:
A give problem has Optimal Substructure Proptery if **optimal solution of the given problem can be obtained by using optimal solutions of its subproblems.**

For example, the Shortest Path problem has following optimal substructure property: If a node 'x' lies in the shortest path from a source node 'u' to destination node 'v' then the shortest path from 'u' to 'v' is combination of shortest path from 'u' to 'x' and shortest path from 'x' to 'v'. But on the other hand, the Longest Path problem doesn't have the Optimal Substructure property. Here by Longest Path we mean longest simple path (path without cycle) between two nodes. Consider the following unweighted graph
q -><- r
^v    ^v
s -><- t

There are two longest paths from q to t: q -> r -> t & q -> s -> t
Unlike shortest paths, these longest paths do not have the optimal substructure property. For example, the longest path q -> r -> t is not a combination of longest path from q to r and longest path from r to t, because the longest path from q to r is q->s->t->r and the longest path from r to t is r->q->s->t.