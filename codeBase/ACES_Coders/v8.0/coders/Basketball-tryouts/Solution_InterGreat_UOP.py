from collections import defaultdict

def pair():
    maxi = 0
    for ele in As:
        a = A[ele]
        for eleC in Cs:
            c = C[eleC]
            val = (ele - eleC) * (a - c + 1)
            if val > maxi:
                maxi = val
    return maxi

N, D = list(map(int, input().split()))
A = defaultdict()
C = defaultdict()
sA = 0
sC = 0
sB = 0
numA = -1
numC = -1
for t in range(N):
    t1, t2, t3, t4 = input().split()
    t1 = int(t1)
    t2 = int(t2)
    t4 = int(t4)
    if t3 == "A":
        numA += 1
        if (t4 not in A) or A[t4] < t2:
            A[t4] = t2
        sA += (t4 * t2)
    elif t3 == "B":
        sB += (t2 - t1 + 1) * t4
    else:
        numC += 1
        if (t4 not in C) or C[t4] > t1:
            C[t4] = t1
        sC += (t2 - t1 + 1) * t4
unpaired = sA + sB + sC
As = A
Cs = C
# As = sorted(A.keys(), reverse = True)
# Cs = sorted(C.keys())
paired = pair()
print(str(unpaired) + " " + str(unpaired + paired))
