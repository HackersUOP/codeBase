/*
  Copyright (C) 2020, Sathira Silva.
*/

#include <bits/stdc++.h>

using namespace std;

int dir[8][2] = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};

int main() {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int m, n;
        cin >> m >> n;
        int grid[m][n];
        for (int i = 0; i < m; i++) {
            char c;
            for (int j = 0; j < n; j++) {
                cin >> c;
                grid[i][j] = c - '0';
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    for (int k = 0; k < 8; k++)
                        if (i + dir[k][0] >= 0 && i + dir[k][0] < m && j + dir[k][1] >= 0 && j + dir[k][1] < n && grid[i + dir[k][0]][j + dir[k][1]] == 0)
                            grid[i + dir[k][0]][j + dir[k][1]] = 2;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cout << grid[i][j];
            cout << endl;
        }
                            
    }
    return 0;
}
