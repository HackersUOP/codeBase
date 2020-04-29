'''
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement:  https://www.hackerrank.com/challenges/knightl-on-chessboard/copy-from/155879319
    
    Approach:   Run bfs for each a = 1 to n - 1 and b = a to n - 1 because of the symmetry in the KnightL(a, b) = KnightL(b, a).
'''

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int bfs(int a, int b, int n) {
    queue<pair<int, int>> q;
    int distance[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0 ; j < n; j++)
            distance[i][j] = INF;
    vector<pair<int, int>> directions = {{a, b}, {b, a}, {a, -b}, {b, -a}, {-a, b}, {-b, a}, {-a, -b}, {-b, -a}};
    q.push({0, 0});
    distance[0][0] = 0;
    int x1, y1;
    while (!q.empty()) {
        x1 = q.front().first;
        y1 = q.front().second;
        q.pop();
        for (auto dxdy: directions) {
            int dx = dxdy.first, dy = dxdy.second;
            if (dx + x1 >= 0 && dx + x1 < n && dy + y1 >= 0 && dy + y1 < n && distance[dx + x1][dy + y1] > distance[x1][y1] + 1) {
                distance[dx + x1][dy + y1] = distance[x1][y1] + 1;
                q.push({dx + x1, dy + y1});
            }
        }
    }
    return (distance[n - 1][n - 1] == INF) ? -1 : distance[n - 1][n - 1];
}

vector<vector<int>> knightlOnAChessboard(int n) {
    vector<vector<int>> moves(n - 1, vector<int>(n - 1, 1));
    for (int a = 1; a < n; a++) {
        for (int b = a; b < n; b++) {
            moves[a - 1][b - 1] = moves[b - 1][a - 1] = bfs(a, b, n);
        }
    }
    return moves;
}
