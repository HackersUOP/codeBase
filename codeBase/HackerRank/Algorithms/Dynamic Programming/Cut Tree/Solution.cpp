/*
    Problem Statement:  Given a tree T with n nodes, how many subtrees (T') of T have at most K edges connected to (T - T')?
    
    Approach:   The idea is to depth first traverse the tree and count the subtrees having number of edges connected to the complement 
                of the current subtree upto k edges.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> tree[51];
long long dp[51][51];
int k;

void dfs(int u, int parent = -1) {
    for (int v: tree[u]) {
        if (v == parent)
            continue;
        dfs(v, u);
        for (int j = k; j > 0; j--) {
            for (int x = j; x > 0; x--)
                dp[u][j] += dp[u][j - x] * dp[v][x];
            dp[u][j] += dp[u][j - 1];
        }
    }
    return;
}

long long cutTree(int n, vector<vector<int>> edges) {
    for (auto e: edges) {
        tree[e[0]].push_back(e[1]);
        tree[e[1]].push_back(e[0]);
    }
    long long subtrees = 0;
    memset(dp, 0, sizeof(dp));
    for(int u = 1; u <= n; u++)
        dp[u][0] = 1;   // Base case
    dfs(1);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < k; j++)
                subtrees += dp[i][j];
    return subtrees + dp[1][k] + 1;
}
