/*
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/challenges/stone-division/problem
  
  Approach:
    (1). Identify the winning / losing states of the game:
        If there doesn't exist a number s in the in the set S such that s divides n, it is a loosing state. Otherwise, the game divides into s equivalent games (because a 
        single pile splits into s equal piles of size n / s). So, the grundy number of the total game is the nim-sum (XOR sum) of those equivalent games. Thus, if there exists such s
        and n / s is even (i.e. n is even), after the split the nim-sum will be 0 (Hence, it's a winning state). Otherwise, g(n / s) where g is the grundy function for the game.
        Therefore, if n is odd, after a split we can think of the game as a single pile of size n / s. If the n / s state is a losing state (i.e g(n / s) = 0), n is a winning
        state.
    (2). Compute grundy numbers:
        Clearly, the grundy number of a state n (a pile of size n) is g(n) = 0 if there is no number in set S that divides n. Otherwise, an expression can be formulated as
        winning(n) = (n % 2 == 0) or winning(n / s). Therefore, when there exists an s in S such that s | n we have to use dynamic programming with memoization to compute 
        the result since the expression for winning(n) is recursive.
        
        (In conclusion, we didn't have to compute the grundy numbers actually. We only checked whether the grundy number of the state after a split is 0 or not)
*/

#include <bits/stdc++.h>

using namespace std;

map<long long, bool> memo;
vector<long long> S;

bool solve(long long n) {
    if (memo.find(n) != memo.end())
        return memo[n];
    memo[n] = false;
    for (long long s : S) {
        if (n % s != 0) // s is not a divisor of n
            continue;
        if (n % 2 == 0 || !solve(n / s))
            memo[n] = true;
    }
    return memo[n];
}

int main() {
    long long n;
    int m;
    cin >> n >> m;
    S.resize(m);
    for (int i = 0; i < m; i++)
        cin >> S[i];
    cout << (solve(n) ? "First" : "Second") << endl;
}
