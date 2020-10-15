/*
    Copyright (C) 2020, Sathira Silva.
    
    Approach: This is purely an Edit Distance problem (or an Optimal Alignment problem) where only the replacements have a cost equal to the matched value. The goal is to 
              maximize the cost. Thus we can solve it using dynamic programming as follows:
              (01). Subproblems: Prefixes of two rows of cards (say first[:i], second[:j])
                    #subproblems: n^2 --> O(n^2)
              (02). Guessing:    One of three possibilities:
                                 * Replace
                                 * Insert
                                 * Delete
              (03). Recurrence: dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + penalty)
              (04). Topological order: Doesn't matter
              (05). Original Problem: dp[n][n]
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    map<char, int> points;
    for (int i = 0; i < 8; i++)
        points[i + '2'] = i + 2;
    points['T'] = 10;
    points['A'] = 20;
    points['J'] = points['Q'] = points['K'] = 15;
    int n;
    int dp[1001][1001];
    while (cin >> n) {
        if (n == 0) break;
        char first[n][1], second[n][1];
         for(int i = 0 ; i < n; i++)
            scanf("%s", first[i]);
        for(int i = 0; i < n; i++)
            scanf("%s", second[i]);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int penalty = 0;  // If the ith and jth card doesn't match, no point value
                if (first[i - 1][0] == second[j - 1][0] || first[i - 1][0] == 'R' || second[j - 1][0] == 'R') {
                    if (first[i - 1][0] == 'R' && second[j - 1][0] == 'R')
                        penalty = 50;
                    else if (first[i - 1][0] == 'R')
                        penalty = points[second[j - 1][0]];
                    else
                        penalty = points[first[i - 1][0]];
                }
                dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1] + penalty));
            }
        }
        cout << 2 * dp[n][n] << endl;
    }
}
