/*
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/contests/moraxtreme3-0/challenges/sunimal-ftw
  
  Approach: This is a variant of the Nim game with zero move is allowed per each heap. As in a regular Nim game, we can break down the game into n number of single heap Nim 
            games and calculate a grundy number per each heap. Thus, the grundy number for the whole game is the XOR sum of each heap. But since 0-move is allowed, the grundy 
            number has to be modified per each heap. The grundy number calculation is as follows:
            Let g be the grundy function for a single heap Nim game.
            g(0) = mex({}) = 0 (Cannot reach any state. Minimum excluded value of the null set is 0)
            g(1) = mex{{0, 1}) = 2 (We can reach the n = 1 state by using the zero move and n = 0 state by removing one stone)
            g(2) = mex({0, 2, 2}) = 1 (We can reach the n = 2 state by using the zero move and n = 0, 1 states by removing stones. Note that g(1) = 2 and g(0) = 0)
            g(3) = mex({0, 2, 1, 3}) = 4
            g(4) = mex({0, 2, 1, 4, 4}) = 3
            ... and so on.
            It's obvious that g(n) = n - 1 if n is even and g(n) = n + 1 for all n > 0
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, res = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int p;
            cin >> p;
            if (p & 1)
                res ^= p + 1;
            else
                res ^= p - 1;
        }
        cout << (res ? "W" : "L") << endl;
    }
    return 0;
}
