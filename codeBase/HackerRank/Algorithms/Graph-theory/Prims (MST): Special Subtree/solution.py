'''
    Copyright (C) 2020, Sathira Silva.
'''

from collections import defaultdict
from heapq import heappop, heappush

def prim(n, edges, start):
    graph = defaultdict(list)
    for u, v, w in edges:
        graph[u].append((w, v))
        graph[v].append((w, u))

    weight = [float("inf")] * (n + 1)
    visited = [False] * (n + 1)
    weight[0] = 0
    weight[start] = 0
    minHeap = [(weight[start], start)]
    while minHeap:
        _, u = heappop(minHeap)
        if visited[u]:
            continue
        visited[u] = True
        for w, v in graph[u]:
            if not visited[v] and w < weight[v]:
                weight[v] = w
                heappush(minHeap, (weight[v], v))
    return sum(weight)
