'''
    This code was written by UOP_Binarybeasts during ACES Precoders v8 2020
    e17212@eng.pdn.ac.lk    kalpani.abewickrama@gmail.com   ishini.udara@gmail.com
'''
n = int(input().strip())
meetings = []

for i in range(n):
    a, s, e = list(map(str,input().strip().split()))
    col_idx = s.index(":")
    s = int(s[:col_idx])*60 + int(s[col_idx+1:])
    col_idx = e.index(":")
    e = int(e[:col_idx])*60 + int(e[col_idx+1:])
    if a=='Y':
        meetings.append([i,s,e])

sorted_meetings = sorted(meetings,key=lambda x: x[2])

s = set([sorted_meetings[0][0]])

k=0

for i in range(1,len(meetings)):
    if sorted_meetings[i][1] >= sorted_meetings[k][2]:
        s.add(sorted_meetings[i][0])
        k=i


print(len(s))
