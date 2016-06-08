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

import math
s1=raw_input()
s2=raw_input()
s1=s1.split()
s2=s2.split()
pi=3.141592653589793
la1=float(s1[1])*pi/180
lo1=float(s1[2])*pi/180
la2=float(s2[1])*pi/180
lo2=float(s2[2])*pi/180
g1=6378*math.cos(la1)
g2=6378*math.cos(la2)
p1=[g1*math.cos(lo1),g1*math.sin(lo1),6378*math.sin(la1)]
p2=[g2*math.cos(lo2),g2*math.sin(lo2),6378*math.sin(la2)]
ang=math.acos((p1[0]*p2[0]+p1[1]*p2[1]+p1[2]*p2[2])/math.sqrt(p1[0]**2+p1[1]**2+p1[2]**2)/math.sqrt(p2[0]**2+p2[1]**2+p2[2]**2))
c=int(2*pi*6378);
d=round(6378*ang)
print str(int(d))+" km"