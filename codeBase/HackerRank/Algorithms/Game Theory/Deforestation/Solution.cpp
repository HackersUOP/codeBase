/*
    Copyright (C) 2020, Sathira Silva.
*/

#include <bits/stdc++.h>

using namespace std;

int grundy[501];

int dfs(int u, int p, vector<vector<int>>& G){
    for(auto ch : G[u]){
        if(ch != p) grundy[u] ^= dfs(ch,u,G);
    }
    return u == 1 ? grundy[u] : ++grundy[u];
}


string deforestation(int n, vector<vector<int>> tree) {
    memset(gr, 0, sizeof(gr));
    vector<vector<int>> graph(n+1);
    for(auto p : tree){
        graph[p[0]].push_back(p[1]);
        graph[p[1]].push_back(p[0]);
    }
    return dfs(1, -1, graph) ? "Alice" : "Bob";
}
