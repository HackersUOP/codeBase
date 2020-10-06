/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-4-0/challenges/gems-of-twopow
    
    Approach: Consider each m_i as binary bit positions. The sum of pair of same bit makes the next bit. Initially, each bit belongs to it's own bit group. Just after a
              pair of same bit group is made, move it to the next bit group recursively.
*/

#include <bits/stdc++.h>

using namespace std;

int c[10001];

void makeset(int p) {
    if (c[p] > 1) {
        c[p + 1]++;
        c[p] = 0;
        makeset(p + 1);
    }
}

int main() {
    int n;
    cin >> n;
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        c[p]++;
        makeset(p);
    }
    int res = 0;
    for (int i = 0; i < 10001; i++)
        res += c[i] > 0;
    cout << res;
    return 0;
}
