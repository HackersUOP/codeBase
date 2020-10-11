/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-5-0/challenges/noi-subset-sum
    
    Approach: This problem can be solved easily with dynamic programming (the recurrence is similar to the discrete knapsack without repetition problem).
    
              (01). Subproblems: let dp[i][x] be the number of subsets using the first i elements having sum equal to x.
                                 Base Cases: dp[i][0] = 1 for all i = 0 to n
                                             dp[0][x] = 0 for all x except 0
              (02). Guessing: Is ith number included in the subset or not?
              (03). Recurrence: dp[i][x] = dp[i - 1][x] + dp[i - 1][x - A[i - 1]] if i >= 1 else dp[i - 1][x]
              (04). Topological order: for i = 1,...n
                                          for x = 1,...s
              (05). Original problem: dp[n][s]
*/
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    int n, s;
    cin >> n >> s;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    ull dp[n + 1][s + 1];
    // Base Cases: number of sets having sum = 0 from the first i items is 1 (the null set)
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1ULL;
    // Base Cases: no items having a sum (except sum = 0) is 0
    for (int x = 1; x <= s; x++)
        dp[0][x] = 0;
    for (int i = 1; i <= n; i++)
        for (int x = 1; x <= s; x++)
            dp[i][x] = dp[i - 1][x] + (x >= A[i - 1]) * dp[i - 1][x - A[i - 1]];
    cout << dp[n][s];
}
