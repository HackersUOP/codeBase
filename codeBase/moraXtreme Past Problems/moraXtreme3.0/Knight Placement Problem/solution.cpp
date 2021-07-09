/*
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/contests/moraxtreme3-0/challenges/knight-placement-problem
  
  Approach: There exists only one optimal configuration for any size of a chess board and it's as follows:
  
            K 0 K 0 ...
            0 K 0 K ...
            K 0 K 0 ...
            . . . . .
            . . . .   .
            
            Therefore, a general pattern can be recognized. Let K(n) be the maximum number of knights that can be placed without attcking each other.
            K(1) = 1
            K(2) = 2
            K(3) = 5
            K(4) = 8
            K(5) = 13
            K(6) = 18
            ... and so on
            
            Thus, if n is even K(n) = n * n / 2
                  if n is odd K(n) = (n * n + 1) / 2
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    long n;
    cin >> n;
    cout << ((n % 2 == 0) ? n * n / 2 : (n * n + 1) / 2);
    return 0;
}
