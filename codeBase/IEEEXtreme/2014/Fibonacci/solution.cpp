/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://csacademy.com/ieeextreme-practice/task/09f92a575cc006d4a6a7f525f370ec30/
    
    Approach: The fibonacci sequence under modulo becomes a periodic sequence. That period is also known as the 'Pisano Period'. Therefore, it is enough to find the fibonacci
              sequence upto the pisano period.
*/

#include <bits/stdc++.h>

using namespace std;

// For m = 10, it turns out that the pisano period is 60
int pisanoPeriod(int m) {
    int prev = 0;
    int curr = 1;
    int res = 0;
    for(int i = 0; i < m * m; i++) {
        int temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
        if (prev == 0 && curr == 1)
            res= i + 1; 
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    int dp[61];
    dp[0] = dp[1] = 1;
    for (int i = 2; i < 61; i++)
        dp[i] = (dp[i - 1] % 10 + dp[i - 2] % 10) % 10;
    for (int _ = 0; _ < t; _++) {
        int m;
        cin >> m;
        cout << dp[m % 60] << endl;
    }
}
