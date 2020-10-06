/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-4-0/challenges/candy-distribution-3-1
    
    Approach: This can be solved efficiently using dynamic programming. We have to find the largest sum divisible by 3 that can be obtained by the given array. There are three
              ways to make the sum divisible by 3. Let x be the element in the array we're currently looking at. So, we have to look at (x % 3 + lastRem) % 3 where lastRem is
              the remainder when the previous sum (sum of first i - 1 elements) is divided by 3.
              (1).  If lastRem = 0, x % 3 = 0
              (2).  If lastRem = 1, x % 3 = 2
              (3).  If lastRem = 2, x % 3 = 1 can make the sum divisible by 3.
              
              (01). Subproblems: dp[i][j] = the largest sum that can be made using the first i elements of the array with sum % 3 = k
                                 Base Cases: dp[0][0] = 0, dp[0][1] = -inf, dp[0][2] = -inf
              (02). Guessing: is ith element included in the sum or not?
              (03). Recurrence: dp[i][j] = max(dp[i - 1][j], candies[i - 1] + dp[i - 1][(j + 3 - candies[i - 1] % 3) % 3])
              (04). Topological order:  for i in (1, n)
                                          for j in (0, 3]
              (05). Original Problem: dp[n][0]
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int candies[n];
    for (int i = 0; i < n; i++)
        cin >> candies[i];
    int dp[n + 1][3];
    dp[0][0] = 0, dp[0][1] = INT_MIN, dp[0][2] = INT_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++)
            dp[i][j] = max(dp[i - 1][j], candies[i - 1] + dp[i - 1][(j + 3 - candies[i - 1] % 3) % 3]);
    }
    cout << dp[n][0];
    return 0;
}
