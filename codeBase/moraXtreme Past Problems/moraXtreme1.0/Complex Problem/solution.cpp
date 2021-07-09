/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme1/challenges/single-input
    
    Approach: This is an easy math problem. Find the roots of the given equation. It's obvious that they're complex hence conjugates which implies that when the given expression
              is evaluated, the result is real for all n. The proof is added to the README.
              The final answer for p is: 4cos(npi/3)
              NOTE: if n is divisible by 3 and n / 3 is odd cos(npi/3) = -1, if n / 3 is even cos(npi/3) = 1; If n is not divisible by 3 but odd, cos(npi/3) = 1/2 and -1/2
              if n is even otherwise.
              
    >>> The 6th test case is wrong. For n = 900000000000000000, the result should be p = 4 because cos(900000000000000000pi/3) = 1. But -4 has been put as the expected output.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    cout << (n % 3 == 0 ? ((n / 3) & 1 ? -4 : 4) : (n & 1 ? 2 : -2));
    return 0;
}
