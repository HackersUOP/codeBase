'''
    Copyright (C) 2020, Sathira Silva.
'''

from sys import stdin, stdout

class Node:
    def __init__(self, id):
        self.id = id
        self.adjacent = set()


class Graph:
    def __init__(self, size, edges):
        self.nodes = {}
        self.weights = {}

        for i in range(1, size + 1):
            self.nodes[i] = Node(i)

        for edge in edges:
            u, v, w = edge
            self.nodes.get(u).adjacent.add(self.nodes.get(v))
            self.nodes.get(v).adjacent.add(self.nodes.get(u))
            self.weights[(u, v)] = w
            self.weights[(v, u)] = self.weights[(u, v)]

    def shortest_path(self, start_id):
        queue = [start_id]
        distances = [-1] * len(self.nodes)
        distances[start_id - 1] = 0

        while queue:
            current_node = queue.pop(0)
            for child in self.nodes.get(current_node).adjacent:
                if distances[child.id - 1] == -1:
                    distances[child.id - 1] = distances[current_node - 1] + self.weights[(current_node, child.id)]
                    queue.append(child.id)
        
        del distances[start_id - 1]
        return distances


def bfs(n, m, edges, s):
    for i in range(m):
        edges[i].append(6)
    
    graph = Graph(n, edges)
    return graph.shortest_path(s)


if __name__ == '__main__':
    q = int(stdin.readline())
    for q_itr in range(q):
        n, m = map(int, stdin.readline().split())
        edges = []
        for _ in range(m):
            edges.append(list(map(int, stdin.readline().rstrip().split())))
        s = int(stdin.readline())
        result = bfs(n, m, edges, s)
        stdout.write(' '.join(map(str, result)) + '\n')
