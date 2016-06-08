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

Description:
Breadth-First search is one of the two primary ways in which the nodes of a graph are traversed(the other being Depth-First Search). Provided the graph is acyclic and connected, Depth-First search will reach each and every node of the graph.

Time Complexity:

Using this code:
A Graph object can be created by specifying the number of nodes in the graph. Then edges must be manually added by using the function addEdge(src,dest), where src and dest denote the source and destination of the edge. Calling the function BFS(s) on the created Graph object,with the input argument s, will print the nodes of the graph in the order that they are visited.

Example Input:
4 2
1 2
1 3
1
Example Output:
4
0 1 2 3
Example Problems:


*/

#include<bits/stdc++.h>

using namespace std;

class Graph {
    int V;
    vector<vector<int> > adj;
    bool visited[100];  //100 is the maximum number of expected nodes in the graph
public:
    Graph(int N) {
        V = N;
        vector<int> empty;
        for (int i = 0; i < N; i++) adj.push_back(empty);

        for (int i = 0; i < V; i++) visited[i] = false;
    }
    void addEdge(int v, int w);
    void DFS(int s);
};

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFS(int v) {

    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < V; i++)
        if (!visited[i])  DFS(i);
}

int main() {
    int n, e, s;
    cin >> n >> e;
    Graph g(n);
    for (int j = 0; j < e; j++) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a - 1, b - 1);
        g.addEdge(b - 1, a - 1);
    }
    cin >> s;
    g.DFS(s - 1);
    return 0;
}