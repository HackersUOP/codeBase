# Name  - Thilakarathna W M D U
# Email - dtdinidu7@gmail.com
# Date  - 08/04/2020

tm = int(input()) # number of test cases
  
for t in range(1, tm+1): # looping through test cases
    n = int(input())     # size of the matrix
    mat = []
    trace = 0            # trace calculate variable
    rowCount = 0 
    colCount = 0
    for r in range(n):
        tmp = [int(i) for i in input().split()]
        trace += tmp[r]
        rowCheck = set(tmp.copy())
        if len(rowCheck) < n:
            rowCount += 1
        mat.append(tmp)

    
    for c in range(n):
        tmp = []
        for r in range(n):
            tmp.append(mat[r][c])
            #print(tmp)
        if (len(set(tmp)) < n):
            colCount += 1
    
    print("Case #{}: {} {} {}".format(t, trace, rowCount, colCount))
        