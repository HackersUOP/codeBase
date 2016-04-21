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
Dijkstra's Algorithm solves the all pairs shortest path problem. However it can only be used when the edge weights of the graph are
non-negative.
Time Complexity: O(E+V*logV)
Using this code:
This implementation works both for a directed graph and an undirected graph. It uses a matrix representaion of the graph. So when using
for an undirected graph, if an edge exists between two edges A and B of the graph, update the matrix "graph" with graph[A][B] as well as
graph[B][A]. The dijkstra() function prints the shortest distance between the specified source node and all other nodes. If a path does
not exist between any two nodes -1 will be printed. The nodes are numbered from 0.
Example Input:
9 14 0
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
Example Output:
0-1 : 4
0-2 : 12
0-3 : 19
0-4 : 21
0-5 : 11
0-6 : 9
0-7 : 8
0-8 : 14
Example Problems:
http://www.spoj.com/problems/EZDIJKST/
*/
#include <bits/stdc++.h>
using namespace std;
int minDistance(vector<int> dist, vector<bool> sptSet, int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void dijkstra(vector<vector<int> > graph, int src, int V) {
    vector<int> dist;
    vector<bool> sptSet;
    for (int i = 0; i < V; i++)
        dist.push_back(INT_MAX), sptSet.push_back(false);
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                    && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    for (int i = 0; i < V; i++) {
        if (dist[i] != 0) {
            if (dist[i] == INT_MAX) cout << -1 << " ";
            else cout << src << "-" << i << " : " << dist[i] << endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int V, E, src;
    cin >> V >> E >> src;
    vector<vector<int> > graph;
    for (int j = 0; j < V; j++) {
        vector<int> tmp;
        for (int k = 0; k < V; k++) tmp.push_back(INT_MAX);
        graph.push_back(tmp);
    }
    for (int j = 0; j < E; j++) {
        int s, d, w;
        cin >> s >> d >> w;
        graph[s][d] = w;
        graph[d][s] = w;
    }
    for (int j = 0; j < V; j++) {
        for (int k = 0; k < V; k++) if (graph[j][k] == INT_MAX) graph[j][k] = 0;
    }
    dijkstra(graph, src, V);
    return 0;
}
