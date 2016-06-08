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
The Prim's Algorithm finds the Minimum Spanning Tree of an undirected graph.

Time Complexity: O(E*logE) or O(E*logV) where E=Number of edges V=Number of vertices

Using this code:
This is a non-class based approach(Compare with the Kruskal's MST implementation). The graph must be created by updating the two-dimensional array 'graph'. If an edge
exists between two nodes the corresponding element of the matrix should be updated with the weight of that edge. Otherwise the respective element should read 0. Calling
primMST(graph,n) prints the edges of the MST and finally prints the total wright of the MST. Note that the NST itself is not unique but the total weight is.

Example Input:
5 6
1 2 3
1 3 4
4 2 6
5 2 2
2 3 5
3 5 7
Example Output:
0 - 1  3
0 - 2  4
1 - 3  6
1 - 4  2
15
Example Problems:
https://www.hackerrank.com/challenges/matrix
*/

#include <bits/stdc++.h>

using namespace std;

typedef long int li;

li minKey(vector<li> key, vector<bool> mstSet, li V) {

  li min = LONG_MAX;
  li min_index;

  for (li v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
      min = key[v], min_index = v;

  return min_index;
}

void printMST(vector<li> parent, li V, vector<vector<li> > &graph) {
  for (li i = 1; i < V; i++)
    printf("%ld - %ld  %ld \n", parent[i], i, graph[i][parent[i]]);
  long long sm = 0;
  for (li i = 1; i < V; i++)
    sm += graph[i][parent[i]];
  cout << sm << endl;
}

void primMST(vector<vector<li> > &graph, li V) {
  vector<li> parent;
  vector<li> key;
  vector<bool> mstSet;

  for (li i = 0; i < V; i++)
    key.push_back(LONG_MAX), mstSet.push_back(false), parent.push_back(0);

  key[0] = 0;
  parent[0] = -1;

  for (li count = 0; count < V - 1; count++) {
    li u = minKey(key, mstSet, V);

    mstSet[u] = true;

    for (li v = 0; v < V; v++)

      if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
        parent[v]  = u, key[v] = graph[u][v];
  }

  printMST(parent, V, graph);
}


int main() {
  li n, m;
  cin >> n >> m;
  vector<vector<li> > graph;
  for (li j = 0; j < n; j++) {
    vector<li> tmp;
    for (li k = 0; k < n; k++) tmp.push_back(0);
    graph.push_back(tmp);
  }
  for (li j = 0; j < m; j++) {
    li x, y;
    li r;
    cin >> x >> y >> r;
    graph[x - 1][y - 1] = r;
    graph[y - 1][x - 1] = r;
  }
  primMST(graph, n);
  return 0;
}