from sys import stdin, stdout

INF = 1e9
N, I = map(int, stdin.readline().split())
cost = [[int(c) if c != 'X' else INF for c in stdin.readline().split()] for _ in range(N)]
profit = [[0] * I] + [list(map(int, stdin.readline().split())) for _ in range(N - 1)]
T = int(stdin.readline())
for t in range(T):
    items = list(map(int, stdin.readline().split()))
    S = len(items)
    dp = [[-INF] * S for _ in range(N)]
    #Sell the last item
    for i in range(N):
        dp[i][S - 1] = profit[i][items[S - 1]]
    
    for k in range(S - 2, -1, -1):
        for i in range(N):
            for j in range(N):
                dp[i][k] = max(dp[i][k], dp[j][k + 1] + profit[i][items[k]] - cost[i][j])
    
    res = -INF
    for i in range(1, N):
        res = max(res, dp[i][0] - cost[0][i])
    
    stdout.write('{}\n'.format(res))
