'''
    Copyright (C) 2020, Sathira Silva.
'''

  
from collections import defaultdict
from heapq import heappop, heappush

def beautifulPath(edges, A, B):
    graph = defaultdict(list)
    for u, v, w in edges:
        graph[u].append((w, v))
        graph[v].append((w, u))
    visited = [[False] * 1024 for _ in range(n + 1)]
    visited[A][0] = True
    minHeap = [(0, A)]
    while minHeap:
        d, u = heappop(minHeap)
        for w, v in graph[u]:
            if not visited[v][d | w]:
                visited[v][d | w] = True
                heappush(minHeap, (d | w, v))
    for i in range(1024):
        if visited[B][i]:
            return i
    return -1
