'''
    Copyright (C) 2020, Sathira Silva.
'''

from sys import stdin, stdout
from collections import defaultdict


def dfs(n, source, tree, ans, p=0):
    total = 1
    for v, w in tree[source]:
        if v != p:
            children = dfs(n, v, tree, ans, source)
            ans[w] += (n - children) * children
            total += children
    return total

# Find the parent vertex of u


def find_set(u, inSet):
    # Current parent of u = inSet[u]
    while u != inSet[inSet[u]]:
        # Set parent of u to parent of parent of u
        inSet[u] = inSet[inSet[u]]
        # Set u to parent of u
        u = inSet[u]
    return u


def union(u, v, s):
    # Set parent of parent of v to parent of u
    s[find_set(v, s)] = find_set(u, s)


def roadsInHackerland(n, roads):
    # Kruskal's Algorithm to find the MST
    tree = defaultdict(list)
    parent = [i for i in range(n)]  # Indices of vertices
    roads.sort(key=lambda x: x[2])
    for u, v, w in roads:
        if find_set(u, parent) != find_set(v, parent):
            union(u, v, parent)
            tree[u].append((v, w))
            tree[v].append((u, w))
    ans = [0] * 2 * len(roads)   # Total number of degrees of vertices
    dfs(n, 0, tree, ans)
    s = 0
    for i in range(len(ans)):
        s += ans[i] * (1 << i)
    return bin(s)[2:]


if __name__ == '__main__':
    n, m = map(int, stdin.readline().split())
    roads = []
    for _ in range(m):
        u, v, w = map(int, stdin.readline().rstrip().split())
        roads.append([u - 1, v - 1, w])
    result = roadsInHackerland(n, roads)
    stdout.write(result + '\n')
