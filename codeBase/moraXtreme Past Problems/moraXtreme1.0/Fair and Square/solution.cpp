/*
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/contests/moraxtreme1/challenges/fair-and-square
  
  Approach: Any number can be represented as the sum of perfect squares. Since a number N can always be expressed as the sum of squares of 1, the maximum count of perfect squares
            that sums to N is N for any number N. But that can be minimized for numbers larger than 3. Let dp(x) = minimum number of perfect squares that sums to x.
            Thus, dp(x) = x if x <= 3; min(x, 1 + dp(x - i * i) for i in range(1, ceiling(sqrt(x))) Otherwise) where i * i is a perfect square less than x.
            Therefore, a dynamic programming approach can be used to efficiently calculate the count.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    int dp[20001];
    dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3; // Base Cases
    for (int n = 4; n <= 20000; n++) {
        dp[n] = n;  // n can be always represented as sum of n square of 1s and it's the maximum perfect square count
        for (int i = 1; i * i <= n; i++)
            dp[n] = min(dp[n], 1 + dp[n - i * i]);
    }
    for (int tt = 0; tt < t; tt++) {
        int a;
        cin >> a;
        cout << dp[a] << endl;
    }
    return 0;
}
