from collections import defaultdict
from heapq import heappop, heappush
from sys import stdin, stdout


def search(n, k, centers, roads):
    city = defaultdict(list)
    for a, b, c in roads:
        city[a].append((b, c))
        city[b].append((a, c))
    k = (1 << k) - 1
    queue = [[] for _ in range(k + 1)]
    visited = [set() for _ in range(k + 1)]
    last_cat = {0: 0}
    heappush(queue[centers[0]], (0, 1))
    time = float("inf")
    for i in range(k + 1):
        while queue[i]:
            d, u = heappop(queue[i])
            if u == n:
                for fishes, dist in last_cat.items():
                    if i | fishes == k:
                        time = min(time, max(dist, d))
                last_cat[i] = min(d, last_cat.get(i, float("inf")))
            if u in visited[i]:
                continue
            visited[i].add(u)
            for v, w in city[u]:
                fishes = centers[v - 1] | i
                if v not in visited[fishes]:
                    heappush(queue[fishes], (w + d, v))
    return time


if __name__ == '__main__':
    n, m, k = map(int, stdin.readline().rstrip().split())
    centers = []
    for _ in range(n):
        centers_item = sum(map(lambda x: 1 << (x - 1), map(int, stdin.readline().split()[1:])))
        centers.append(centers_item)
    roads = []
    for _ in range(m):
        roads.append(list(map(int, stdin.readline().rstrip().split())))
    res = search(n, k, centers, roads)
    stdout.write(str(res) + '\n')
