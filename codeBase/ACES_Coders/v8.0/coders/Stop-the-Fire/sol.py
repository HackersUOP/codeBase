# Python program to find articulation points in an undirected graph 

from collections import defaultdict 
import math
#This class represents an undirected graph  
#using adjacency list representation 
class Graph: 
   
    def __init__(self,vertices): 
        self.V= vertices #No. of vertices 
        self.graph = defaultdict(list) # default dictionary to store graph 
        self.Time = 0
   
    # function to add an edge to graph 
    def addEdge(self,u,v): 
        self.graph[u].append(v) 
        self.graph[v].append(u) 
   
    '''A recursive function that find articulation points  
    using DFS traversal 
    u --> The vertex to be visited next 
    visited[] --> keeps tract of visited vertices 
    disc[] --> Stores discovery times of visited vertices 
    parent[] --> Stores parent vertices in DFS tree 
    ap[] --> Store articulation points'''
    def APUtil(self,u, visited, ap, parent, low, disc, chd): 
  
        #Count of children in current node  
        children =0
        decendants = 0
        # Mark the current node as visited and print it 
        visited[u]= True
  
        # Initialize discovery time and low value 
        disc[u] = self.Time 
        low[u] = self.Time 
        self.Time += 1
  
        #Recur for all the vertices adjacent to this vertex 
        for v in self.graph[u]: 
            # If v is not visited yet, then make it a child of u 
            # in DFS tree and recur for it 
            if visited[v] == False : 
                parent[v] = u 
                children += 1
                decendants += 1
                decendants += self.APUtil(v, visited, ap, parent, low, disc,chd) 

                # Check if the subtree rooted with v has a connection to 
                # one of the ancestors of u 
                low[u] = min(low[u], low[v]) 
  
                chd[u] = decendants

                # u is an articulation point in following cases 
                # (1) u is root of DFS tree and has two or more chilren. 
                if parent[u] == -1 and children > 1: 
                    ap[u] = True
  
                #(2) If u is not root and low value of one of its child is more 
                # than discovery value of u. 
                if parent[u] != -1 and low[v] >= disc[u]:
                    ap[u] = True    
                      
                # Update low value of u for parent function calls     
            elif v != parent[u]:  
                low[u]  = min(low[u], disc[v]) 
        return decendants
  
    #The function to do DFS traversal. It uses recursive APUtil() 
    def AP(self,start): 
   
        # Mark all the vertices as not visited  
        # and Initialize parent and visited,  
        # and ap(articulation point) arrays 
        visited = [False] * (self.V) 
        disc = [float("Inf")] * (self.V) 
        low = [float("Inf")] * (self.V) 
        parent = [-1] * (self.V) 
        ap = [False] * (self.V) #To store articulation points 
        chd = [0] *self.V
        # Call the recursive helper function 
        # to find articulation points 
        # in DFS tree rooted with vertex 'i' 

        self.APUtil(start, visited, ap, parent, low, disc, chd) 
        
        return ap,chd

class Graph2(): 
  
    def __init__(self, vertices): 
        self.V = vertices 
        self.graph = [[0 for column in range(vertices)]  
                    for row in range(vertices)] 
  
    # A utility function to find the vertex with  
    # minimum distance value, from the set of vertices  
    # not yet included in shortest path tree 
    def minDistance(self, dist, sptSet): 
  
        # Initilaize minimum distance for next node 
        _min = 10**100
  
        # Search not nearest vertex not in the  
        # shortest path tree

        for v in range(self.V): 
            if dist[v] < _min and sptSet[v] == False: 
                _min = dist[v] 
                min_index = v 
        return min_index 
  
    # Funtion that implements Dijkstra's single source  
    # shortest path algorithm for a graph represented  
    # using adjacency matrix representation 
    def dijkstra(self, src): 
  
        dist = [10**100] * self.V 
        dist[src] = 0
        sptSet = [False] * self.V 
  
        for cout in range(self.V): 
  
            # Pick the minimum distance vertex from  
            # the set of vertices not yet processed.  
            # u is always equal to src in first iteration 
            u = self.minDistance(dist, sptSet) 
  
            # Put the minimum distance vertex in the  
            # shotest path tree 
            sptSet[u] = True
  
            # Update dist value of the adjacent vertices  
            # of the picked vertex only if the current  
            # distance is greater than new distance and 
            # the vertex in not in the shotest path tree 
            for v in range(self.V): 
                if self.graph[u][v] > 0 and sptSet[v] == False and dist[v] > dist[u] + self.graph[u][v]: 
                        dist[v] = dist[u] + self.graph[u][v] 
        return dist
N,S,M = map(int,input().split()) 

arr = [[0 for _ in range(N)] for _ in range(N)]

for _ in range(M):
    a,b,w = input().split()
    arr[int(a)][int(b)] = float(w)

g1 = Graph(N)
for i in range(N):
    for j in range(i+1,N):
        if arr[i][j] > 0:
            g1.addEdge(i,j) 

ap,chd = g1.AP(S)
aps = []
for index, value in enumerate (ap): 
    if value == True:
        aps.append(index)

arr_log = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    for j in range(N):
        if (arr[i][j] > 0):
            arr_log[i][j] = -math.log10(arr[i][j]) 
        else:
            arr_log[i][j] = 10*100

g = Graph2(N) 
g.graph = arr_log

dist = g.dijkstra(S)

_max = -10**100
ans = -1
for ap in aps:
    if 10**(-dist[ap])*chd[ap] > _max:
        if ap == S:
            continue
        _max = 10**(-dist[ap])*chd[ap]
        ans = ap

print(ans)



