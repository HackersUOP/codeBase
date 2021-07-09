/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-4-0/challenges/bi-colored-tree
    
    Approach: Finding the number of red vertices in the path from root (0) to any vertex is easy and can be responded to queries in O(1). All we have to do is start from the
              root of the tree and breadth-first or depth-first traverse through the tree to accumulate the number of red vertices and store it in the same array. Using that
              pre-calculated array, we can answer any query. Suppose the queried vertices x and y are such that their lowest common ancestor is the root of the tree. 
              Then, the number of red vertices in the path from x to y = tree[x] + tree[y] - tree[0].
              We have to deduct the number of red vertices in the path from root to root i.e. tree[0] because it has been counted twice from both tree[x] and tree[y].
              But if the lowest common ancestor of x and y are not the root, we also have to deduct both tree[lca] and tree[parent of lca] also. Because the numner of red
              vertices in the path from lca to lca = tree[lca] - tree[parent of lca]
              
              Lowest Common Ancestor of two vertices can be found in O(logn) for each query using the algorithm below. The 2D array parent[i][j] stores the jth ancestor of
              ith node. depth[i] stores the depth of the ith node.
*/

#include <bits/stdc++.h>

#define MAXLEVEL 17

using namespace std;

int lca(int u, int v, int parent[][MAXLEVEL], int depth[]) 
{ 
    if (depth[v] < depth[u]) 
        swap(u, v); 
    int diff = depth[v] - depth[u]; 
    for (int i = 0; i< MAXLEVEL; i++) 
        if ((diff >> i) & 1) 
            v = parent[v][i];
    if (u == v)
        return u;
    for (int i = MAXLEVEL - 1; i >=0 ; i--) 
        if (parent[u][i] != parent[v][i]) 
        { 
            u = parent[u][i]; 
            v = parent[v][i]; 
        }
    return parent[u][0]; 
}

int main() {
    int n, T;
    cin >> n >> T;
    int tree[n], parent[n][MAXLEVEL], depth[n];
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < MAXLEVEL; j++)
            parent[i][j] = -1;
    for (int i = 0; i < n; i++)
        cin >> tree[i];
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        parent[i][0] = p - 1;
        graph[p - 1].push_back(i);
    }
    queue<int> q;
    bool visited[n];
    memset(visited, false, sizeof(visited));
    int u = 0;
    visited[u] = true;
    depth[u] = 0;
    q.push(0);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v : graph[u])
            if (!visited[v]) {
                visited[v] = true;
                tree[v] += tree[u];
                depth[v] = depth[u] + 1;
                q.push(v);
            }
    }
    for (int i = 1; i < MAXLEVEL; i++)
        for (int u = 0; u < n; u++) 
            if (parent[u][i - 1] != -1) 
                parent[u][i] = parent[parent[u][i - 1]][i - 1];
    for (int t = 0; t < T; t++) {
        int a, b, _lca;
        cin >> a >> b;
        _lca = lca(a - 1, b - 1, parent, depth);
        cout << (tree[a - 1] + tree[b - 1] - (_lca == 0 ? tree[_lca] : tree[_lca] + tree[parent[_lca][0]])) << endl;
    }
    return 0;
}
