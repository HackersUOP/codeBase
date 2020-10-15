/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-5-0/challenges/return-to-1
    
    Approach: Collatz Conjecture (https://en.wikipedia.org/wiki/Collatz_conjecture) says 'no matter what value of n, the sequence will always reach 1'. Therefore, recursively
              apply the operations and count the number of steps a needed until the number reaches 1 using memoization.
*/

#include <bits/stdc++.h>

using namespace std;

map<int, int> memo;

int steps(int n) {
    // Base Case:
    if (n == 1)
        return 0;
    if (memo.count(n))
        return memo[n];
    if ((n & 1) == 0)
        return memo[n] = steps(n >> 1) + 1;
    return memo[n] = steps(3 * n + 1) + 1;
}

int main() {
    int n;
    cin >> n;
    for (int _ = 0; _ < n; _++) {
        int kapila, kalpa;
        cin >> kapila >> kalpa;
        int s = steps(kalpa), t = steps(kapila);
        cout << (s < t ? "Kalpa" : s == t ? "-" : "Kapila") << endl;
    }
    return 0;
}
