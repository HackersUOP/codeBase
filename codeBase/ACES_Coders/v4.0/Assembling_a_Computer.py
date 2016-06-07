s=raw_input()
a=s.count('A')
d=s.count('D')
x=s.count('X')
y=s.count('Y')
p=s.count('P')
r=s.count('R')

value=min(a,d,x,y,p,r)

print value