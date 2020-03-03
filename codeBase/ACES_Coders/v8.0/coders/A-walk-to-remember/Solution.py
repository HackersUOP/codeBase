'''
	This solution was submitted by Team: eyeCoders_UOP 
		during ACES Coders v8 2020 
	Team lead: Rusiru Thushara thusharakart@gmail.com

	The solution runs in O(n)
'''
def getline():return [float(x) for x in input().strip().split(' ')]
c,e,n,s0 = getline()
arr, lst = [], []
m = c/s0
for i in range(int(n)):
    x,s = getline()
    arr.append((x,s))
    if x<c and s>=0:
        m = max(m,(c-x)/s)
    elif s<0:
        lst.append((x,s))
count = 0
for x,s in lst:
    if x+s*m <= c:
        count+=1
print(round(m),count)
