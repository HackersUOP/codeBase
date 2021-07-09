/*
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/contests/moraxtreme-4-0/challenges/range-query-1-1
  
  Approach: Binary search for the lower and upper boundaries.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, q;
    cin >> n, cin.ignore(), cin >> m, cin.ignore(), cin >> q;
    int arr[m];
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    sort(arr, arr + m);
    for (int Q = 0; Q < q; Q++) {
        int a, b;
        cin >> a, cin.ignore(), cin >> b;
        cout << (upper_bound(arr, arr + m, b) - lower_bound(arr, arr + m, a)) << endl;
    }
    return 0;
}
