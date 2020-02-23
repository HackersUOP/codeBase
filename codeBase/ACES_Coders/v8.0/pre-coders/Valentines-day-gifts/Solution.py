'''
    gihanjayatilaka[at]eng[dot]pdn[dot]ac[dot]lk
'''

N=int(input())
names=[]
radii=[]
for _ in range(N):
    name,radius=input().strip().split()
    names.append(name)
    radii.append(float(radius))
rn=zip(radii,names)
rn=sorted(rn)
ans=1
noOfCrushes=len(set(names))

names=set()
for i in range(N):
    names.add(rn[i][1])
    if len(names)==noOfCrushes:#One person can wrap only the gifts of everyone else = ONE less than the no of crushes
        ans+=1
        names=set()
        names.add(rn[i][1])
print(ans)
