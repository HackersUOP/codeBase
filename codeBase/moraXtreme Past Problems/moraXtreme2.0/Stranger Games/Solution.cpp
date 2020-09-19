#include <bits/stdc++.h>

#define INF (int) 1e9

using namespace std;

int dfs(int u, vector<int> graph[], bool visited[], int& count) {
    visited[u] = true;
    int currentCount = 0;
    for (int v : graph[u]) {
        if (!visited[v]) {
            int subCount = dfs(v, graph, visited, count);
            if (subCount % 2 == 0)
                count++;
            else
                currentCount += subCount;
        }
    }
    return currentCount + 1;
}

int main() {
    int N, M, n = 0;
    cin >> N >> M;
    vector<int> graph[N];
    map<string, int> m;
    for (int i = 0; i < M; i++) {
        string u, v;
        cin >> u >> v;
        if (m.find(u) == m.end())
            m[u] = n++;
        if (m.find(v) == m.end())
            m[v] = n++;
        graph[m.at(u)].push_back(m.at(v));
        graph[m.at(v)].push_back(m.at(u));
    }
    bool visited[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;
    int count = 0;
    dfs(0, graph, visited, count);
    cout << count + 1 << endl;
    return 0;
}
