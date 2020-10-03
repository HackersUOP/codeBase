'''
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/contests/moraxtreme1/challenges/maximum-2
  
  Approach: There exists an O(1) solution for this problem. Since f(kn) = n and f(kn + r) = f(kn) + r = f(n) + r (Note that r is the remainder of n / k), f(n) can be 
            expressed as f(n) = f(k * k * ...  k * x + n % k) = f(x) + n % k where x (< k) is the largest multiplier that n can be expressed with a product of as much as k's.
            Therefore, the least value of n in range (0, b] which maximizes f(n) is the [largest multiple of largest exponent of k less than b] - 1. We have deduct 1 in order
            to maximize the modulo term.
            In mathematical terms: floor(b / (k ^ floor(logk(b - 1)))) * (k ^ floor(logk(b - 1))) - 1.
'''

from math import log

k, b = map(int, input().split())
p = k ** int(log(b - 1, k))
print(b // p * p - 1)
