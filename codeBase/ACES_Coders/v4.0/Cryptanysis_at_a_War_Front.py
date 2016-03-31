s=list(raw_input())
tks=[1,0,2,3,4,5,6,7,8,9]
vals=[]
count=0
def rmd(seq):
    seen = set()
    seen_add = seen.add
    return [ x for x in seq if not (x in seen or seen_add(x))]

st=rmd(s)
for k in range(len(s)):
    vals.append(0)
    
for i in range(len(st)):
    for j in range(len(s)):
        if s[j]==st[i]:
            vals[j]=tks[count]
    count=count+1
    
if len(st)!=1:
    b=len(st)
else:
    b=2
    
strng=''.join(str(x) for x in vals)
print int(strng,b)