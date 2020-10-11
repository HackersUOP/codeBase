/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-5-0/challenges/1939
    
    Apporach: If voco is a leaf vertex (number of adjacent vertices = 1) it can be captured by the first player immediately thus, Stalind wins. Otherwise, they both have to
              capture the other vertices before they capture the city voco. Therefore, start a BFS / DFS from the city voco and count the number of grandchildern of voco.
              Since the requirement to capture a city is at most having one grandchild, if (#grandchildren - 1) is even, always the first player wins and if it is odd, the
              second player wins.
              
    Time Complexity: O(n) since the graph is a tree
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int n, voco;
        cin >> n >> voco;
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if (graph[voco].size() == 1)  // Check if Hitalnd can win immediately
            cout << "Hitland" << endl;
        else {  // Otherwise, traverse the tree Breadth-First
            bool visited[n + 1];
            memset(visited, false, sizeof(visited));
            int grandchildren = 0;
            queue<int> q;
            int u = voco;
            q.push(voco);
            while (!q.empty()) {
                u = q.front();
                q.pop();
                visited[u] = true;
                for (int v : graph[u])
                    if (!visited[v]) {
                        q.push(v);
                        grandchildren++;
                    }
            }
            cout << ((grandchildren - 1) & 1 ? "Stalind" : "Hitland") << endl;
        }
    }
}
