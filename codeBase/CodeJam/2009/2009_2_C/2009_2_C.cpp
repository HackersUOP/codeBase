/*
Copyright Hackers' Club, University Of Peradeniya
Author : E/13/181 (Samurdhi Karunarathne)
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at *
http://www.apache.org/licenses/LICENSE-2.0 *
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include<bits/stdc++.h>
using namespace std;
#define NIL 0
#define INF INT_MAX
typedef long int li;
bool vecCompare(vector<li> &vec1, vector<li> &vec2) {
    int len = vec1.size();
    for (int i = 0; i < len; i++) {
        if (vec1[i] >= vec2[i]) return false;
    }
    return true;
}
class BipGraph {
    int m, n;
    list<int> *adj;
    vector<int> pairU, pairV, dist;
public:
    BipGraph(int m, int n);
    void addEdge(int u, int v);
    bool bfs();
    bool dfs(int u);
    int hopcroftKarp();
};
int BipGraph::hopcroftKarp() {
    for (int u = 0; u < m; u++)
        pairU[u] = NIL;
    for (int v = 0; v < n; v++)
        pairV[v] = NIL;
    int result = 0;
    while (bfs())
    {
        for (int u = 1; u <= m; u++)
            if (pairU[u] == NIL && dfs(u))
                result++;
    }
    vector<bool> considered;
    considered.resize(m + 1, false);
    int num_considered = 0;
    int ans = 0;
    while (num_considered < m) {
        int ind = -1;
        for (int i = 1; i <= m; i++) {
            if (!considered[i]) {
                ind = i;
                break;
            }
        }
        int next = ind;
        considered[next] = true;
        num_considered++;
        while (pairU[next] != 0) {
            next = pairU[next];
            considered[next] = true;
            num_considered++;
        }
        ans++;
    }
    return ans;
}
bool BipGraph::bfs() {
    queue<int> Q;
    for (int u = 1; u <= m; u++)
    {
        if (pairU[u] == NIL)
        {
            dist[u] = 0;
            Q.push(u);
        }
        else dist[u] = INF;
    }
    dist[NIL] = INF;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (dist[u] < dist[NIL])
        {
            list<int>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = *i;
                if (dist[pairV[v]] == INF)
                {
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF);
}
bool BipGraph::dfs(int u) {
    if (u != NIL)
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = *i;
            if (dist[pairV[v]] == dist[u] + 1)
            {
                if (dfs(pairV[v]) == true)
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}
BipGraph::BipGraph(int m, int n) {
    this->m = m;
    this->n = n;
    adj = new list<int>[m + 1];
    pairU.resize(m + 1);
    pairV.resize(n + 1);
    dist.resize(m + 1);
}
void BipGraph::addEdge(int u, int v) {
    adj[u].push_back(v);
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, K;
        cin >> n >> K;
        vector<vector<li> > stocks;
        stocks.resize(n);
        BipGraph g(n, n);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < K; k++) {
                li tmp;
                cin >> tmp;
                stocks[j].push_back(tmp);
            }
        }
        sort(stocks.begin(), stocks.end());
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (vecCompare(stocks[j], stocks[k])) {
                    g.addEdge(j + 1, k + 1);
                    printf("%d %d\n", j + 1, k + 1);
                }
            }
        }
        printf("Case #%d: %d\n", i + 1, g.hopcroftKarp());
    }
    return 0;
}
