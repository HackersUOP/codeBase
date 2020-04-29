'''
    Copyright (C) 2020, Sathira Silva.
'''

from collections import defaultdict
from sys import stdin, stdout
from heapq import heappop, heappush

def dijkstra(n, graph, u):
    distance = [float("inf")] * (n + 1)
    distance[u] = 0
    visited = [False] * (n + 1)
    visited[u] = True
    queue = [(distance[u], u)]
    while queue:
        d, u = heappop(queue)
        for v, w in graph[u]:
            if not visited[v] and distance[v] > d + w:
                visited[v] = True
                distance[v] = d + w
                heappush(queue, (distance[v], v))
    return distance[1:]

def treeFlow(n, tree):
    graph = defaultdict(list)
    for u, v, w in tree:
        graph[u].append((v, w))
        graph[v].append((u, w))
    return min(sum(dijkstra(n, graph, 1)), sum(dijkstra(n, graph, n)))

if __name__ == '__main__':
    n = int(stdin.readline())
    tree = [list(map(int, stdin.readline().rstrip().split())) for _ in range(n - 1)]
    result = treeFlow(n, tree)
    stdout.write(str(result) + '\n')
