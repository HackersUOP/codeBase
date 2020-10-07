/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-4-0/challenges/matrix-game-1-1
    
    Approach: If the input matrix is produced using beta operations, the 1st half of the 1st column and the 2nd half of the 1st row must be equal (or the other way around). If
              so, we have to check the same condition of its half size matrix until size 1. When the condition is unsatisfied or the size is odd, then we break from the iteration
              and return the size of the previous matrix.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
    int size;
    for (size = n; size > 1; size/=2) {
        if (size & 1) break;
        int left = 0, right = 0;
        for (int i = 0; i < size / 2; i++)
            left += m[i][0], right += m[0][i + size / 2];
        if (left != right) break;
    }
    cout << size;
}
