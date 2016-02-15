/*
    Description:

    Topological Sorting(TopSort) gives an ordering of a directed graph in such a way that for any edge on the graph, the destination node 
    appears after the correspoding source-node in the ordering. As such, a topological sort is not unique and there are several ways in 
    which the nodes can be arranged to satisfy this condition. In this implementation, the lexicographically smallest such ordering is found.
    (i.e. the samllest possible node-id comes first). This is a tougher task than finding any ordering and a minimum priotiy queue is used 
    for this purpose in this particular implementation.

    Time Complexity:

    Using this code:

    The Graph class implements an undirected graph and a Graph object can be created by passing the number of vertices(V) to the constructor.
    Then the edges must be externally added with the function addEdge(src,dest), which takes the source and destination as arguments. Calling
    the function topologicalSort(V) will print the lexicoraphically smallest topological sort on the console.

    Exampe Input:
    
    6 6

    5 2
    5 0
    4 0
    4 1
    2 3
    3 1

    Example Output:

    4 5 0 2 3 1 

    Example Problems:

    https://www.hackerrank.com/challenges/favourite-sequence
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Graph{
  ll V; 
  vector<vector<ll> > adj;
  set<ll> nodes;  
  vector<ll> inedge;  
  void topologicalSortUtil(ll v, vector<bool> visited);
  priority_queue<ll,vector<ll>,greater<ll> > mpq;  
public:
  Graph(ll V); 

  void addEdge(ll v, ll w);

  void topologicalSort(ll);
};

Graph::Graph(ll V){
  this->V = V;
  adj.resize(V);
  inedge.resize(V,0);  
}

void Graph::addEdge(ll v, ll w){
  adj[v].push_back(w);
  nodes.insert(v);
  nodes.insert(w);  
  inedge[w]++;  
}

void Graph::topologicalSortUtil(ll v, vector<bool> visited){
  visited[v] = true;
  cout<<v<<" ";  
  for (int i = 0; i <adj[v].size(); ++i){
      if (!visited[adj[v][i]]){
        inedge[adj[v][i]]--;
        if(inedge[adj[v][i]]==0) mpq.push(adj[v][i]);  
      }
  }
  while(!mpq.empty()){
      ll tm=mpq.top();
      mpq.pop();
      topologicalSortUtil(tm,visited);
  }  
}


void Graph::topologicalSort(ll n){
  adj.resize(n);
  inedge.resize(n);  
  V=n;
  for(int i=0;i<inedge.size();i++) if(inedge[i]==0 && nodes.find(i)!=nodes.end()) mpq.push(i);    
  vector<bool> visited(V);
  for (ll i = 0; i < V; i++)
    visited[i] = false;
    
  ll y=mpq.top();
  mpq.pop();
  topologicalSortUtil(y, visited);
}

int main(){
  ll V,E;
  cin>>V>>E;
  Graph graph(V);  
  for(ll i=0;i<E;i++){
      ll s,d;
      cin>>s>>d;
      graph.addEdge(s,d);
  }  
  graph.topologicalSort(V);

  return 0;
}