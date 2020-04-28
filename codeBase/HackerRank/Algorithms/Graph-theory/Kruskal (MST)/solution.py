'''
    Copyright (C) 2020, Sathira Silva.
'''

def find_set(u, parent):
    while u != parent[parent[u]]:
        parent[u] = parent[parent[u]]
        u = parent[u]
    return u

def union(u, v, parent):
    parent[find_set(v, parent)] = find_set(u, parent)

def kruskal(n, edges):
    parent = [i for i in range(n)]
    edges.sort(key = lambda x:x[2])
    s = 0
    for u, v, w in edges:
        if find_set(u, parent) != find_set(v, parent):
            union(u, v, parent)
            s += w
    
    return str(s)
