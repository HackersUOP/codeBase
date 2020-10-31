/*
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/contests/moraxtreme1/challenges/window-summing
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w, window = 0;
    cin >> n >> w;
    vector<int> seq(n);
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    for (int i = 0; i < n; i++) {
        window += seq[i];
        if (i >= w)
            window -= seq[i - w];
        cout << window << " ";
    }
    return 0;
}
