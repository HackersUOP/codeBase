from cmath import exp, pi

def fft(x):
    N = len(x)
    if N <= 1: return x
    even = fft(x[0::2])
    odd =  fft(x[1::2])
    T= [exp(-2j*pi*k/N)*odd[k] for k in range(N//2)]
    return [even[k] + T[k] for k in range(N//2)] + [even[k] - T[k] for k in range(N//2)]
    
def ifft(X):
    for i in range(len(X)):
        X[i] = X[i].conjugate()
    x = fft(X)
    for i in range(len(x)):
        x[i] = x[i].conjugate()/len(X)
    return x


N,T,logP = map(int,input().split())
P = 10**logP

arr=[]
for _ in range(T):
    arr.append(list(map(int,input().split())))
W = int(input())
req = list(map(int,input().split()))

cnt = [[0 for _ in range(max(arr[t])+1)] for t in range(T)]
N2 = 0
for x in range(T):
    N2 += len(cnt[x])
    for y in range(N):
        cnt[x][arr[x][y]] += 1

#padding 0s
Np = 1
while Np<N2:
    Np = Np<<1
for x in range(T):
    cnt[x] = cnt[x] + [0 for _ in range(Np-len(cnt[x]))]


CNT = [None for _ in range(T)]
for x in range(T):
    CNT[x] = fft(cnt[x])

ANS = [1 for _ in range(Np)]
for x in range(T):
    for y in range(Np):
            ANS[y] *= CNT[x][y]


ans = ifft(ANS)

tmp = []
for k in range(W):
    try:
        tmp.append(round(abs(ans[req[k]])))
    except:
        tmp.append(0)

tmp_i = [i for i in range(W)]
tmp,tmp_i=zip(*sorted(zip(tmp,tmp_i)))
final_ans = []
zeros = 0
for k in range(0,W):
    if tmp[k] > P:
        final_ans.append(tmp_i[k])
    if tmp[k] < 0.5:
        zeros += 1
final_ans.sort()

print(" ".join(map(str, final_ans)).strip())
