'''
	gihanjayatilaka[at]eng[dot]pdn[dot]ac[dot]lk 16/02/2020
'''
P=int(input())

diff=[0]*(100000+1)

for _ in range(P):
	m,s,e=map(int,input().strip().split())

	diff[s]+=m
	diff[e+1]-=m

pay=[0]*len(diff)

pay[0]=diff[0]
for i in range(1,len(pay)):
	pay[i]=pay[i-1]+diff[i]

print(max(pay))
