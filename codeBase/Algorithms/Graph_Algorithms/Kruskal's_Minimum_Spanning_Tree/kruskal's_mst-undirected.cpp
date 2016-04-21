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
The Kruskal's Algorithm finds the Minimum Spanning Tree of an undirected graph.
Time Complexity: O(E*logE) or O(E*logV) where E=Number of edges V=Number of vertices
Using this code:
The Graph class implements an undirected graph and a Graph object can be created by passing the number of vertices(V) and the number of
edges(E) to the constructor. Then the edges must be externally added, by appending an Edge object to the "edges" vector of the created
Graph object, which takes the source, destination and the weight of the edge. The nodes are numbered starting from 0. The function
KruskslMST return the value of the MST and prints the edges in the MST on the console.
Example Input:
9 14
0  1  4
0  7  8
1  2  8
1  7  11
2  3  7
2  8  2
2  5  4
3  4  9
3  5  14
4  5  10
5  6  2
6  7  1
6  8  6
7  8  7
Example Output:
37
6 7
5 6
2 8
0 1
2 5
2 3
1 2
3 4
Example Problems:
https://www.hackerrank.com/challenges/matrix
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;
class Edge {
public:
    ll src, dest, weight;
};
class Graph {
public:
    ll V, E;
    vector<Edge> edges;
    Graph(ll, ll);
};
Graph::Graph(ll V, ll E) {
    this->V = V;
    this->E = E;
    edges.resize(E);
}
class Subset {
public:
    ll parent;
    ll rank;
};
ll find(Subset subsets[], ll i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(Subset subsets[], ll x, ll y)
{
    ll xroot = find(subsets, x);
    ll yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
bool myComp(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}
ll KruskalMST(Graph graph) {
    ll V = graph.V;
    Edge result[V];
    ll e = 0;
    ll i = 0;
    sort(graph.edges.begin(), graph.edges.end(), myComp);
    Subset subsets[V];
    for (ll v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1) {
        Edge next_edge = graph.edges[i++];
        ll x = find(subsets, next_edge.src);
        ll y = find(subsets, next_edge.dest);
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    ll sm = 0;
    for (i = 0; i < e; ++i) {
        sm += result[i].weight;
        printf("%d %d\n", result[i].src, result[i].dest);
    }
    return sm;
}
int main() {
    ios_base::sync_with_stdio(false);
    ll V, E;
    cin >> V >> E;
    Graph graph(V, E);
    for (ll j = 0; j < E; j++) {
        ll s, d, w;
        cin >> s >> d >> w;
        Edge edge;
        edge.src = s;
        edge.dest = d;
        edge.weight = w;
        graph.edges.push_back(edge);
    }
    cout << KruskalMST(graph) << endl << endl;
    return 0;
}
