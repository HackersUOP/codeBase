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
*DESCRIPTION:
Given a directed graph G, a Minimum Path Cover of G is a set of directed paths in G such that each vertex belongs to at least one path. If we construct a BiGraph with
the vertices of G in each of the two partitions, and match those vertices for each directed edge of the graph, we get a bigraph where each matching represents an edge
in the original directed graph.
If we find the maximum matching in this BipGraph using the Hopcroft-Karp algorithm, then we can construct the paths in the Minimum Path Cover starting from the first
vertex and following the matching until we get to a vertex which has no outgoing matching in the Maximum Matching obtained from the above algorithm. Then we go to the
next vertex which has not been considered so far and start over with the same procedure until we have considered all the vertices. The paths we obtained in this
procedure is the paths contained in the Minimum Path Cover of the graph.
*TIME COMPLEXITY:
*USING THIS CODE:
This basically uses the Hopcroft-Karp Maximum Matching Algorithm found in the Matching Algorithms section to implement the action. This is a good example of how a
standard algorithm can be modified to do a more specific task.
The Graph class implements an undirected graph and a Graph object can be created by passing the number of vertices(V) to the constructor.
Then the edges must be externally added with the function addEdge(src,dest), which takes the source and destination as arguments.
Given the details of the graph, the hopcroftKarp() function prints the paths in  the Minimum Path Cover of the graph and returns the number of paths in the Minimum Path
Cover.
The input format is as follows.
First the number of vertices(n) and the number of edges(K) of the graph must be given. Then the K edges of the graph must be specified, with source first and
destination second.
*EXAMPLE INPUT:
(See input.txt file in the enclosing directory)
*EXAMPLE OUTPUT:
1 -> 2 -> 3 -> 4 -> 5 -> 8 -> 10 -> 12 -> 15
6 -> 7 -> 9 -> 14
11 -> 13 -> 16
Number of paths: 3
*EXAMPLE PROBLEMS:
https://www.hackerrank.com/challenges/problem-solving
https://code.google.com/codejam/contest/204113/dashboard#s=p2
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
        printf("%d", next);
        considered[next] = true;
        num_considered++;
        while (pairU[next] != 0) {
            printf(" -> ");
            next = pairU[next];
            printf("%d", next);
            considered[next] = true;
            num_considered++;
        }
        printf("\n");
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
    int n, K;
    cin >> n >> K;
    BipGraph g(n, n);
    for (int j = 0; j < K; j++) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    printf("Number of paths: %d\n", g.hopcroftKarp());
    return 0;
}
