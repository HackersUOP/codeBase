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