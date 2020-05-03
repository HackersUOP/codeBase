/*
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement:  https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem
    
    Approach:   Run BFS on each cell to find the number of cells in filled regions (Floodfill Algorithm).
    
    Time Complexity:  O(nm)
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, cells;
bool visited[11][11];
int grid[11][11];
const int directions[8][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}, {-1, -1}};

void bfs(int x, int y) {
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int x0 = q.front().first;
        int y0 = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x1 = x0 + directions[i][0];
            int y1 = y0 + directions[i][1];
            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && !visited[x1][y1] && grid[x1][y1]) {
                cells++;
                visited[x1][y1] = true;
                q.push({x1, y1});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int maxCells = -1;
    cin >> n >> m;  
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j]) {
                cells = 0;
                bfs(i, j);
                maxCells = max(maxCells, cells);
            }
        }
    }
    cout << maxCells + 1 << endl;
    return 0;
}
