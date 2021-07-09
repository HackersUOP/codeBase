'''
  gihanjayatilaka[at]eng[dot]pdn[dot]ac[dot]lk 2020-03-22
'''
ar=None-
dpAns=None
K=None
N=None
P=None

T = int(input())


def dp(n,pp,deb):
    # print("funcIn",deb,n,pp)
    if n>=N or pp<=0:
        # print(deb+"dpAns[{}][{}]={}".format(n, pp, 0))
        return 0
    if dpAns[n][pp]>-1:
        return dpAns[n][pp]



    tempAns=dp(n+1,pp,deb+"   ")

    for k in range(min(pp,K)):
        tempAns=max(tempAns,ar[n][k]+dp(n+1,pp-k-1,deb+"   "))

    dpAns[n][pp]=tempAns
    # print(deb+"dpAns[{}][{}]={}".format(n,pp,tempAns))

    return dpAns[n][pp]
-
for t in range(1, T + 1):
    NKP=list(map(int, input().strip().split()))
    N=NKP[0]
    K=NKP[1]
    P=NKP[2]
    ar=[]
    dpAns=[[-1 for _ in range(P+1)] for n in range(N)]
    for i in range(N):
        ar.append(list(map(int, input().strip().split())))

    # print(ar)

    for i in range(N):
        for j in range(1,K):
            ar[i][j]=ar[i][j-1]+ar[i][j]
    # print(ar)
    # for i in range(N,-1,-1):






    print("Case #{}: {}".format(t,dp(0,P,"   ")))
