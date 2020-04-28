'''
    Copyright (C) 2020, Sathira Silva.
    
    The problem requires Floyd-Warshall all pairs shortest path algorithm which requires O(|V|^3) time, but it can also be solved
    by repeatedly applying Dijkstra and saving the answers for queries in a memo (Dynamic Programming).
    
    Time Complexity:    O(|V|^2.log(|V|) + |V||E|)
'''

from sys import stdin, stdout
from collections import defaultdict
from heapq import heappop, heappush

def dijkstra(n, source, target):
    global graph, dp
    if (source, target) in dp:
        return dp[(source, target)]
    visited = [False] * (n + 1)
    distance = [float("inf")] * (n + 1)
    distance[source] = 0
    minHeap = [(distance[source], source)]
    while minHeap:
        d, u = heappop(minHeap)
        if u == target:
            dp[(source, target)] = d
            return d
        if visited[u]:
            continue
        visited[u] = True
        for w, v in graph[u]:
            if not visited[v] and distance[v] > d + w:
                distance[v] = d + w
                heappush(minHeap, (distance[v], v))
    dp[(source, target)] = -1
    return -1

if __name__ == '__main__':
    n, m = map(int, stdin.readline().split())
    dp = dict()
    graph = defaultdict(list)
    for _ in range(m):
        u, v, w = map(int, stdin.readline().split())
        try:
            i = next(i for i, (_, to) in enumerate(graph[u]) if to == v)
            graph[u][i] = (w, v)
        except StopIteration:
            graph[u].append((w, v))
    q = int(stdin.readline())
    for q_itr in range(q):
        start, end = map(int, stdin.readline().split())
        stdout.write(str(dijkstra(n, start, end)) + '\n')
