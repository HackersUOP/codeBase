/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-4-0/challenges/alien-agreement/
    
    Apporach:   This is an easy problem when the city is viewed as a graph. The problem is to find the minimum number of
                aliens to remove such that an alien in S is not connected with an alien in T. Therefore, we only need to
                consider the edges between S and T. When only those edges and vertices are considered as a sub-graph is
                a Bipartite graph since we do not care about the edges inside S or T. Then, to disconnect those edges
                such that the removals are minimum all we have to do is remove the minimum of the number of vertices
                in partitions that belongs to S and T.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, left = 0, right = 0;
    cin >> n >> m;
    bool vertices[2 * n];
    memset(vertices, false, sizeof(vertices));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        if (u / n != v / n) {
            if (!vertices[u]) {
                vertices[u] = true;
                left++;
            }
            if (!vertices[v]) {
                vertices[v] = true;
                right++;
            }
        }
    }
    cout << min(left, right);
    return 0;
}
