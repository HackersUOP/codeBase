'''
    This code was written by UOP_hashInclude during ACES Precoders v8 2020
    nuwanjaliyagoda@eng.pdn.ac.lk   imeshuek@eng.pdn.ac.lk  dinelkadilshani95@gmail.com

'''
qwe,n=[int(i) for i in input().strip().split(" ")]

p=[int(i) for i in input().strip().split(" ")]
q=[0]
tot=0
for i in p:
    tot+=i
    q+=[tot]

for i in range (n):
    a,b=[int(i) for i in input().strip().split(" ")]
    if b>=qwe:
        b=len(q)-1
    print(q[b+1]-q[a])
    
