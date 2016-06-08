'''
Copyright Hackers' Club, University Of Peradeniya
Author : E/13/181 (Samurdhi Karunarathne)
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at *
http://www.apache.org/licenses/LICENSE-2.0 *
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
'''

s1=raw_input()
s2=raw_input()
s1=s1.split(',')
s2=s2.split(',')

def generate(v):
    points=[]
    a=v[0]
    b=v[1]
    prepoints=[[a+2,b+1],[a+2,b-1],[a-2,b+1],[a-2,b-1],[a+1,b+2],[a-1,b+2],[a+1,b-2],[a-1,b-2]]
    for i in range(8):
        if prepoints[i][0]>=0 and prepoints[i][0]<=7 and prepoints[i][1]>=0 and prepoints[i][1]<=7:
            points.append(prepoints[i])
    return points             

def iffound(p,q):
	found=0
	pointsarr=generate(p)
	for j in range(len(pointsarr)):
		if pointsarr[j]==q:
			found=1
		        break
	return found

def number(x,y):
    currentpoints=[x]
    FOUND=0
    counter=0
    while (FOUND==0):
        for w in range(len(currentpoints)):
            if iffound(currentpoints[w],y)==1:
                FOUND=1
                break
    
        
        current=[]
        for w in range(len(currentpoints)):
            for e in range(len(generate(currentpoints[w]))):
                arr1=generate(currentpoints[w])
                current.append(arr1[e])


        del currentpoints[:]
        currentpoints=current
        counter=counter+1

    return counter

print number([int(s1[0].split('(')[1]),int(s1[1].split(')')[0])],[int(s2[0].split('(')[1]),int(s2[1].split(')')[0])])
