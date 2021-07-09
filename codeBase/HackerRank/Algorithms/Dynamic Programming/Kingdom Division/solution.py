'''
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement:  King Arthur has a large kingdom that can be represented as a tree, where nodes correspond to cities and edges 
    correspond to the roads between cities. The kingdom has a total of n cities numbered from 1 to n. The King wants to divide his kingdom 
    between his two children, Reggie and Betty, by giving each of them 0 or more cities; however, they don't get along so he must divide 
    the kingdom in such a way that they will not invade each other's cities. The first sibling will invade the second sibling's city if 
    the second sibling has no other cities directly connected to it.
    Given a map of the kingdom's n cities, find and print the number of ways King Arthur can divide it between his two children such that 
    they will not invade each other. As this answer can be quite large, it must be modulo 7 + 10 ^ 9.
    
    Approach:   We have to find the number of ways of colouring subtrees such that its root node has the same colour as the subtree.
                This can be easily done with Dynamic Programming and DFS traversal to find the subtrees.
'''

from collections import defaultdict
sys.setrecursionlimit(10 ** 6)

mod = 7 + 10 ** 9

def dfs(city, kingdom, visited):
    global dp
    visited[city] = True
    for neighbourCity in kingdom[city]:
        if visited[neighbourCity]:
            continue
        dfs(neighbourCity, kingdom, visited)
        dp[city][0] = (dp[city][0] * dp[neighbourCity][1]) % mod
        dp[city][1] = (dp[city][1] * (2 * dp[neighbourCity][1] + dp[neighbourCity][0])) % mod
    dp[city][1] -= dp[city][0]

def kingdomDivision(n, roads):
    global dp
    visited = [False] * (n + 1)
    kingdom = defaultdict(list)
    for u, v in roads:
        kingdom[u].append(v)
        kingdom[v].append(u)
    dfs(1, kingdom, visited)
    return (2 * dp[1][1]) % mod

if __name__ == '__main__':
    n = int(stdin.readline())
    roads = []
    for _ in range(n-1):
        roads.append(list(map(int, stdin.readline().rstrip().split())))
    dp = [[1, 1] for _ in range(n + 1)]
    result = kingdomDivision(n, roads)
    stdout.write(str(result) + '\n')
