/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem:  https://csacademy.com/ieeextreme-practice/task/979a09a0cd8c4e98dd0a690f39a55bd2/
    
    Approach: Union each edge. If the end points of an edge belongs to the same set, a loop is found.
*/

#include <bits/stdc++.h>

using namespace std;

int findSet(int u, int parent[]) {
    if (parent[u] == -1)
        return u;
    return findSet(parent[u], parent);
}

void makeUnion(int u, int v, int parent[]) {
    parent[findSet(u, parent)] = findSet(v, parent);
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int n, m;
        cin >> n >> m;
        int parent[n];
        memset(parent, -1, sizeof(parent));
        bool found = false;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            if (!found) {
                int pu = findSet(u, parent), pv = findSet(v, parent);
                if (pu == pv)
                    found = true;
                makeUnion(u, v, parent);
            }
        }
        cout << found << endl;
    }
}
