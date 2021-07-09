n, d = [int(i) for i in input().split()]

A = {}
C = {}

shoots = 0

def rangeD(e1, s2, e2):
    tmp = min(e1, e2) - s2+1
    return(tmp if tmp >= 0 else -1)

for _ in range(n):
    s, e, t, num = [i for i in input().split()]
    s, e, num = int(s), int(e), int(num)
    shoots += (e-s+1)*num
    if (t == "A"):
        if num in A:
            A[num] = max(A[num], e)
        else:
            A[num] = e
    elif (t == "C"):
        if num in C:
            C[num] = min(C[num], s)
        else:
            C[num] = s
        
print(shoots, end = ' ')

maxVal = 0

for a in A:
    for c in C:
        if (a > c):
            tmp = rangeD(A[a], C[c], d)
            if not tmp == -1:
                maxVal = max(maxVal, tmp*(a-c))
                
print(shoots+maxVal)
