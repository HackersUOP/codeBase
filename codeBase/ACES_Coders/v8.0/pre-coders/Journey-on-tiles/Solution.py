'''
    This code was written by UOP_Bitlasagna during ACES Precoders v8 2020
    dinuransika98@gmail.com	sathirasofte@gmail.com	sasanka14@gmail.com

'''
n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

for i in range(n - 2, -1, -1):
    grid[n - 1][i] += grid[n - 1][i + 1]
    grid[i][n - 1] += grid[i + 1][n - 1]
    
for i in range(n - 2, -1, -1):
    for j in range(n - 2, -1, -1):
        grid[i][j] += max(grid[i + 1][j], grid[i][j + 1])
        
print(grid[0][0])