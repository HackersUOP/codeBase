lns=[]
test=0
counter=0
while(test==0):
    s1=raw_input()
    if s1.endswith('\r')==True:
        s1=s1.replace('\r','')
    else:
        test=1
    lns.append(s1)
    counter=counter+1
    
target=[]
counter_1=0

spaces=[]
for k in range(counter):
    space=[]
    for p in range(len(lns[k])):
        if lns[k][p]==' ':
            space.append(p)
    spaces.append(space)

for j in range(counter):
    if len(lns[j])==43 and spaces[j]==[3, 9, 15, 19, 25, 30, 34, 39]:
        counter_1=counter_1+1
        target=lns[j]
    

if counter_1==0:
    print 'No solution'
else:
    def unspace(a):
        g=str(a)
        f=g.split(' ')
        f=''.join(f)
        return f
    
    
    def respace(b,c):
        for l in range(len(spaces[c])):
            b.insert(spaces[c][l],' ')
        return ''.join(b)

    alph='abcdefghijklmnopqrstuvwxyz'
    const='thequickbrownfoxjumpsoverthelazydog'
    cipher_alph=[]
    unspaced_target=unspace(target)
    for m in range(len(alph)):
	    n=const.index(alph[m])
	    cipher_alph.append(unspaced_target[n])

    def decipher(d,e):
        inp=unspace(d)
        sentence=[]
        for o in range(len(inp)):
	    q=cipher_alph.index(inp[o])
	    sentence.append(alph[q])

        return respace(sentence,e)

    for r in range(counter):
        print decipher(lns[r],r)

