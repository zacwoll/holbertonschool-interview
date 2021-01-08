#!/usr/bin/python3

from typing import List
import math

def primeFactors(n: int) -> List[int]:
    primes = []
    m = 2
    limit = max(math.sqrt(n), 3)

    while (m <= limit):
        # if the inner loop succeeds
        # we must restart the process
        # of appending primes to list
        if (n % m == 0):
            primes.append(m)
            n /= m
            m = 1
            limit = max(math.sqrt(n), 3)
        m += 1
    if (n > 0 and n != 1):
        primes.append(int(n))
    return primes

def minOperations(n: int) -> int:
    if (n < 1):
        return 0
    primes = primeFactors(n)
    return sum(primes)