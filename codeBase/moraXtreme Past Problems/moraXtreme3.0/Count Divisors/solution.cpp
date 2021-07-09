/*
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/contests/moraxtreme3-0/challenges/count-divisors-1-1
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n;
        m = n;
        int count = 0;
        while (m > 0) {
            if (m % 10 != 0 && n % (m % 10) == 0)
                count++;
            m /= 10;
        }
        cout << count << endl;
    }
    return 0;
}
