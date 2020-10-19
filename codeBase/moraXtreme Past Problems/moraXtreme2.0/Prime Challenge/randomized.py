'''
    Copyright (C) Sathira Silva, 2020.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-2/challenges/prime-challenge
    
    Approach: The following is a randomized algorithm for the above problem. Goldbach's first and second conjectures are used to solve the problem. His first conjecture says
              that "Every even integer greater than 2 can be expressed as the sum of two primes". His second conjecture states "Every odd integer greater than 5 can be expressed
              as the sum of three primes". The first prime can always be chosen as 3 because when the first prime is 3 and since n is odd, n - 3 will be even. From goldbach's
              second conjecture, n - 3 can be expressed as the sum of two primes because of the given upper bound of n. Below algorithm sets 3 to be the first prime and
              generates a random integer less than n. When both generated integer (say p2) and n - 3 - p2 are primes, it prints the result. Miller - Rabin primality test is
              used for the primality checks.
'''

import random

def power(x, y, p):
    res = 1
    x = x % p
    while (y > 0):
        if (y & 1): 
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p 
    return res

def millerTest(d, n):
    a = 2 + random.randint(1, n - 4);
    x = power(a, d, n); 
    if (x == 1 or x == n - 1): 
        return True
    while (d != n - 1):
        x = (x * x) % n
        d *= 2
        if (x == 1):
            return False
        if (x == n - 1): 
            return True
    return False

def isPrime(n, k):
    if (n <= 1 or n == 4): 
        return False
    if (n <= 3): 
        return True
    d = n - 1
    while (d % 2 == 0): 
        d //= 2
    for i in range(k): 
        if (millerTest(d, n) == False): 
            return False
    return True

n = int(input())
while True:
    p1 = 3
    p2 = random.randint(4, n)
    p3 = n - p1 - p2
    if isPrime(p2, 20) and isPrime(p3, 20):
        print(p1, p2, p3)
        break
