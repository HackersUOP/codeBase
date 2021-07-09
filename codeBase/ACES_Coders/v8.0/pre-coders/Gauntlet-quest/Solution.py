'''
NOTE:
Due to the large queue size, the unoptimized solution is comparatively slower (Only in interpreted languages like python).
Thus multiple queues are used, one for each bit mask value.
suren.sri@eng.pdn.ac.lk
'''

from heapq import *
n, m, k = map(int, input().split())
typ = [sum(map(lambda x: 1 << (x - 1), map(int, input().split()[1:]))) for _ in range(n)]
graph = [[] for i in range(n)]
for i in range(m):
    a, b, c = map(int, input().split())
    a, b = a - 1, b - 1
    graph[a].append((b, c))
    graph[b].append((a, c))
k, n = (1 << k) - 1, n - 1
h = [[] for _ in range(k + 1)]
v = [set() for _ in range(k + 1)]
last = {0: 0}
heappush(h[typ[0]], (0, 0))
flag = INF = 10 ** 9
for i in range(k + 1):
    while h[i]:
        c, a = heappop(h[i])
        if a == n:
            for x, y in last.items():
                if i | x == k:
                    flag = min(flag, max(y, c))
            last[i] = min(c, last.get(i, INF))
        if a in v[i]:
            continue
        v[i].add(a)
        for x, y in graph[a]:
            j = typ[x] | i
            if x not in v[j]:
                heappush(h[j], (y + c, x))
print(flag)
