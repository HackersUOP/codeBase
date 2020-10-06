/*
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/contests/moraxtreme3-0/challenges/save-the-cities
  
  Approach: The main idea is to find the number of connected components. Two cells are connected if they're adjacent and the cell value is 1. Maintain a visited array and 
            traverse through the city matrix. If the current cell is 1, depth first traverse the matrix and mark all the 1 cells that found as visited during the traversal.
            If the depth first traversal ends, then all those marked 1's are a single connected component. Therefore, increase the count at the end of the DFS.
*/

#include <bits/stdc++.h>

using namespace std;

int m, n;
int adj[1000][1000];
bool visited[1000][1000];
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void dfs(int i, int j) {
    visited[i][j] = true;
    for (int x = 0; x < 8; x++)
        if (i + dir[x][0] >= 0 && j + dir[x][1] >= 0 && i + dir[x][0] < m && j + dir[x][1] < n && adj[i + dir[x][0]][j + dir[x][1]] && !visited[i + dir[x][0]][j + dir[x][1]])
            dfs(i + dir[x][0], j + dir[x][1]);
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];
    memset(visited, 0, sizeof(visited));
    int count = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j] && !visited[i][j]) {
                dfs(i, j);
                count++;
            }
    cout << count << endl;
    return 0;
}
