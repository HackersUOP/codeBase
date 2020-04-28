'''
    Copyright (C) 2020, Sathira Silva.
'''

class Node:
    def __init__(self, id):
        self.id = id
        self.adjacent = set()
    
    def __eq__(self, node):
        return self.id == node.id

    def __hash__(self):
        return hash(self.id)

class Graph:
    def __init__(self, size, edges):
        self.nodes = {}

        for i in range(1, size + 1):
            self.nodes[i] = Node(i)

        for edge in edges:
            u, v = edge
            self.nodes.get(u).adjacent.add(self.nodes.get(v))
            self.nodes.get(v).adjacent.add(self.nodes.get(u))

    def find_clusters(self, node, visited, count):
        visited[node] = True
        for child in self.nodes.get(node).adjacent:
            if not visited[child.id]:
                count = 1 + self.find_clusters(child.id, visited, count)
        return count

    def rebuild_hackerland_optimally(self, c_lib, c_road):
        result = 0
        visited = [False] * (len(self.nodes) + 1)
        for node in self.nodes:
            if not visited[node]:
                cluster_size = self.find_clusters(node, visited, 1)
                print(cluster_size)
                result += c_lib
                if c_lib > c_road:
                    result += (cluster_size - 1) * c_road
                else:
                    result += (cluster_size - 1) * c_lib
        return result

def roadsAndLibraries(n, c_lib, c_road, cities):
    hackerland = Graph(n, cities)
    return hackerland.rebuild_hackerland_optimally(c_lib, c_road)
