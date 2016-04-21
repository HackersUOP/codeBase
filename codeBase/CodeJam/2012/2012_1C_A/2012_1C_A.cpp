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
#include<iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool BFS(int s);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
bool Graph::BFS(int s)
{
    int S = s;
    bool *visited = new bool[V];
    int num_visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false, num_visited[i] = 0;
    list<int> queue;
    visited[s] = true;
    num_visited[s] = 1;
    queue.push_back(s);
    list<int>::iterator i;
    while (!queue.empty()) {
        s = queue.front();
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            num_visited[*i]++;
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
            if (num_visited[*i] == 2 && s != S) return true;
        }
    }
    return false;
}
bool solve(vector<pr> &vec, Graph &g) {
    sort(vec.rbegin(), vec.rend());
    for (int i = 0; i < vec.size(); i++) {
        int s = vec[i].second;
        if (g.BFS(s)) return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        Graph g(n);
        vector<pr> vec;
        for (int j = 0; j < n; j++) {
            int m;
            cin >> m;
            vec.push_back(make_pair(m, j));
            for (int k = 0; k < m; k++) {
                int a;
                cin >> a;
                g.addEdge(j, a - 1);
            }
        }
        if (solve(vec, g)) printf("Case #%d: Yes\n", i + 1);
        else printf("Case #%d: No\n", i + 1);
    }
    return 0;
}
