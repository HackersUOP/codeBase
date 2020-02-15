'''
    This code was written by UOP_hashInclude during ACES Precoders v8 2020
    nuwanjaliyagoda@eng.pdn.ac.lk   imeshuek@eng.pdn.ac.lk  dinelkadilshani95@gmail.com

'''
n=int(input())
p=[]
for i in range (n):
    word=input().strip()
    p+=[word]


for i in p:
    w=""
    for j in i:
        if w=="":
            w=j
        elif w[0]>=j:
            w=j+w
        else:
            w=w+j
    print(w)
        
    