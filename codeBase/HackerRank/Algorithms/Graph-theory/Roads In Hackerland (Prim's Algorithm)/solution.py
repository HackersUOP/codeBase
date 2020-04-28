from collections import defaultdict
from heapq import heappop, heappush


def dfs(n, source, tree, ans, p=0):
    total = 1
    for v, w in tree[source]:
        if v != p:
            children = dfs(n, v, tree, ans, source)
            ans[w] += (n - children) * children
            total += children
    return total


def roadsInHackerland(n, roads):
    # Prim's Algorithm to find the MST
    hackerland = defaultdict(list)
    parent = dict()
    for u, v, w in roads:
        hackerland[u].append((w, v))
        hackerland[v].append((w, u))
    s = 0
    weight = [float("inf")] * (n + 1)
    visited = [False] * (n + 1)
    weight[0] = 0
    weight[1] = 0
    minHeap = [(weight[1], 1)]
    while minHeap:
        _, u = heappop(minHeap)
        if visited[u]:
            continue
        visited[u] = True
        for w, v in hackerland[u]:
            if not visited[v] and w < weight[v]:
                weight[v] = w
                parent[v] = (u, weight[v])
                heappush(minHeap, (weight[v], v))
    mst = defaultdict(list)
    for u, (v, w) in parent.items():
        mst[u].append((v, w))
        mst[v].append((u, w))
    # Total degree of vertices = 2 * Number of Edges
    ans = [0] * 2 * len(roads)
    dfs(n, 1, mst, ans)
    for i in range(len(ans)):
        s += ans[i] * (1 << i)
    return bin(s)[2:]
