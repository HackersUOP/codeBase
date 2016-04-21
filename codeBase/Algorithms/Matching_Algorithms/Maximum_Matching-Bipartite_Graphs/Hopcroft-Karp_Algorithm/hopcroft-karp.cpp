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
/*
Description:
The Hopcroft-Karp algorithm finds the maximum matching in a bi-partite graph. A bi-partite graph can be seen as a partition of a
graph where the edges only occur between the two halves of the partitioning.
Time Complexity:
Using this code:
A BipGraph object can be created by specifying the number of nodes in each half of the bi-partite graph. Then edges must be manually
added by using the function addEdge(src,dest), where src and dest denote the source and destination of the edge. Calling the function
hopcroftKarp() on the created BipGraph object will print the matchings which occur in the maximum matching and will return the size of
the matching(i.e the number of matchings in the maximum matching).
Example Input:
4 4 6
1 2
1 3
2 1
3 2
4 2
4 4
Example Output:
4
0 - 0
1 - 3
2 - 1
3 - 2
Example Problems:
https://www.hackerrank.com/challenges/bike-racers
https://www.hackerrank.com/challenges/problem-solving
https://code.google.com/codejam/contest/204113/dashboard#s=p2
*/
#include <bits/stdc++.h>
using namespace std;
#define NIL 0
#define INF INT_MAX
typedef long long ll;
typedef pair<long, long> pr;
class BipGraph
{
    ll m, n;
    vector<vector<ll> > adj;
    vector<ll> pairU, pairV, dist;
public:
    BipGraph(ll, ll);
    void addEdge(ll, ll);
    bool bfs();
    bool dfs(ll);
    ll hopcroftKarp();
};
ll BipGraph::hopcroftKarp()
{
    for (ll u = 0; u < m; u++)
        pairU[u] = NIL;
    for (ll v = 0; v < n; v++)
        pairV[v] = NIL;
    ll result = 0;
    while (bfs()) {
        for (ll u = 1; u <= m; u++)
            if (pairU[u] == NIL && dfs(u)) {
                result++;
            }
    }
    for (ll u = 0; u < m; u++) {
        printf("%lld - %lld\n", u, pairU[u]);
    }
    return result;
}
bool BipGraph::bfs()
{
    queue<ll> Q;
    for (ll u = 1; u <= m; u++) {
        if (pairU[u] == NIL)
        {
            dist[u] = 0;
            Q.push(u);
        }
        else dist[u] = INF;
    }
    dist[NIL] = INF;
    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        if (dist[u] < dist[NIL]) {
            for (int i = 0; i < adj[u].size(); ++i) {
                ll v = adj[u][i];
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
bool BipGraph::dfs(ll u)
{
    if (u != NIL)
    {
        for (int i = 0; i < adj[u].size(); ++i)
        {
            ll v = adj[u][i];
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
BipGraph::BipGraph(ll m, ll n)
{
    this->m = m;
    this->n = n;
    adj.resize(m + 1);
    pairU.resize(m + 1);
    pairV.resize(n + 1);
    dist.resize(m + 1);
}
void BipGraph::addEdge(ll u, ll v)
{
    adj[u].push_back(v);
}
int main() {
    ios_base::sync_with_stdio(false);
    ll m, n, e;
    cin >> m >> n >> e;
    BipGraph graph(m, n);
    for (int i = 0; i < e; i++) {
        ll s, d;
        cin >> s >> d;
        graph.addEdge(s, d);
    }
    cout << graph.hopcroftKarp() << endl << endl;
    return 0;
}
