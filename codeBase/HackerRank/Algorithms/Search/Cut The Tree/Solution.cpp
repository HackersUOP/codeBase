/*
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement:  Anna loves graph theory! She has a tree where each vertex is numbered from 1 to n, and each contains a data 
                        value. The sum of a tree is the sum of all its nodes' data values. If she cuts an edge in her tree, she forms 
                        two smaller trees. The difference between two trees is the absolute value between their sums.
                        Given a tree, determine which edge to cut so that the resulting trees have a minimal difference between them, 
                        then return that difference.
                        
    Approach:   Run DFS from root vertex to find all the subtree weights.
*/

#include <bits/stdc++.h>

using namespace std;

int n, minDifference, totalWeight;
const int MAX = (int) pow(10, 5) + 1;
vector<int> tree[MAX];
int weight[MAX];
bool visited[MAX];

int dfs(int u) {
    int w = weight[u];
    visited[u] = true;
    for (int v: tree[u])
        if (!visited[v])
            w += dfs(v);
    // Deduct w twice because totalWeight of the tree includes weight of the subtree w.
    minDifference = min(minDifference, abs(totalWeight - 2 * w));
    return w;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> weight[i];
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    minDifference = 1e9, totalWeight = accumulate(weight, weight + n + 1, 0);
    dfs(1);
    cout << minDifference << endl;
    return 0;
}
