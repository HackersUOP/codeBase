/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-4-0/challenges/speed-dating/
    
    Approach: Instead of finding the maximum sum attainable with the limit of k consecutive elements maximum, find the
              minimum sum of the elements which needs to be skipped (or removed) in order to get the maximum sum of
              elements with k consecutive integers maximum. The other way around (finding the maximum sum directly) is
              also possible in the same time complexity but it gives TLE for the last test case. The dynamic programming
              steps are as follows:
              (01). Subproblems: dp[i] the minimum sum of elements to skip using first i elements
                                 Base cases: from i = 0 upto k, dp[i] = 0
              (02). Guessing: should we remove the jth element or not? (for j from i - k to i)
              (03). Recursion: dp[i] = min(dp[j - 1] + arr[j] for all j from i - k to i)
              (04). Topological order: for i from k + 1 to n
                                            for j from i - k to i
              (05). Original problem: sum of the array - dp[n]
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    ll desirabilities[n], sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> desirabilities[i];
        sum += desirabilities[i];
    }
    ll dp[n + 1];
    // Base Cases:
    for (int i = 0; i <= k; i++)
        dp[i] = 0;
    for (int i = k + 1; i <= n; i++) {
        dp[i] = dp[i - k - 1] + desirabilities[i - k - 1];
        for (int j = i - k + 1; j <= i; j++)
            dp[i] = min(dp[i], dp[j - 1] + desirabilities[j - 1]);
    }
    cout << (sum - dp[n]);
}
