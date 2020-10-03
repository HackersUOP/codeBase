/*
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/contests/moraxtreme1/challenges/fair-and-square
  
  Approach: Any number can be represented as the sum of perfect squares. Since a number N can always be expressed as the sum of squares of 1, the maximum count of perfect squares
            that sums to N is N for any number N. But that can be minimized for numbers larger than 3. Let count(x) = minimum number of perfect squares that sums to x.
            Thus, count(x) = x if x <= 3; min(x, 1 + count(x - i * i) for i in range(1, ceiling(sqrt(x))) Otherwise) where i * i is a perfect square less than x.
            Therefore, a dynamic programming approach can be used to efficiently calculate the count.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    int count[20001];
    count[0] = 1, count[1] = 2, count[2] = 3, count[3] = 3; // Base Cases
    for (int n = 4; n <= 20000; n++) {
        count[n] = n;  // n can be always represented as sum of n square of 1s and it's the maximum perfect square count
        for (int i = 1; i * i <= n; i++)
            count[n] = min(count[n], 1 + count[n - i * i]);
    }
    for (int tt = 0; tt < t; tt++) {
        int a;
        cin >> a;
        cout << count[a] << endl;
    }
    return 0;
}
