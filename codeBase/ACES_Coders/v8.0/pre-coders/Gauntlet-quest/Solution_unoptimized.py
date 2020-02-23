from heapq import heappop, heappush
from collections import defaultdict

n, m, k = map(int, raw_input().split())

masks = [0] * (n+1)
graph = defaultdict(list)
dp = [[float('inf')]*(2**k+2) for i in xrange(n+1)]

for i in xrange(1, n+1):
    ar = map(int, raw_input().split())
    for t in xrange(1, len(ar)):
        masks[i] |= 2**(ar[t]-1)

for i in range(m):
    u, v, w = map(int, raw_input().split())
    graph[u].append((v, w))
    graph[v].append((u, w))

queue = [(0, 1, masks[1])]

# Djikstra
while queue:
    cost, node, mask = heappop(queue)
    for X in graph[node]:
        v, c = X
        if cost + c < dp[v][mask|masks[v]]:
            heappush(queue, (cost+c, v, mask | masks[v]))
            dp[v][mask | masks[v]] = cost + c

ans = float('inf')

# Brute force bit manipulation
for i in xrange(2**k):
    for j in xrange(2**k):
        if i | j == 2**k - 1 and dp[n][j] != float('inf'):
            ans = min(ans, max(dp[n][i], dp[n][j]))

print ans
