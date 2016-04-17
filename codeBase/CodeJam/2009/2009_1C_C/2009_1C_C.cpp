/*
Copyright Hackers' Club, University Of Peradeniya
Author : E/13/181
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at *
http://www.apache.org/licenses/LICENSE-2.0 *
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

typedef long int li; 
typedef pair<li,vector<li> > pr;

li find(li p,vector<li> rel,li q,map<pr,li> &mp);

li solve(li p,vector<li> rel,li q,map<pr,li> &mp){

    if(p==1) return 0;
    else if(q==1) return p-1;
    else{
        li mn=LONG_MAX;
        for(int i=0;i<q;i++){
            if(i==0){
                vector<li> temp;
                for(int j=1;j<q;j++){
                  temp.push_back(rel[j]-rel[0]);
                  //cout<<rel[j]-rel[0]<<endl;  
                }
                //cout<<p-rel[0]<<q-1<<endl;
                li y=find(p-rel[0],temp,q-1,mp);   
                //cout<<y<<endl;
                mn=min(mn,y);
            }
            else if(i==q-1){
                vector<li> temp(rel.begin(),rel.end()-1);
                for(unsigned int j=0;j<temp.size();j++){
                  //cout<<temp[j]<<endl;  
                }
                //cout<<rel[q-1]-1<<q-1<<endl;
                li y=find(rel[q-1]-1,temp,q-1,mp);  
                //cout<<y<<endl;
                mn=min(mn,y);
            }
            else{
                vector<li> temp1;
                for(int j=i+1;j<q;j++) temp1.push_back(rel[j]-rel[i]);
                li y=find(p-rel[i],temp1,q-i-1,mp);     
                //cout<<y<<endl;

                vector<li> temp2(rel.begin(),rel.begin()+i);
                li z=find(rel[i]-1,temp2,i,mp);    
                //cout<<z<<endl;
                mn=min(mn,y+z);
            }
        }
        //cout<<mn+(p-1);
        return mn+(p-1);
    }
}

li find(li p,vector<li> rel,li q,map<pr,li> &mp){

    pr temp=make_pair(p,rel);

    if(mp.find(temp)!=mp.end()){
        //cout<<"HA"<<endl;
        return mp[temp];
    } 
    else{
        li w=solve(p,rel,q,mp);
        mp[temp]=w;
        //cout<<"w "<<w<<endl;
        return w;
    }    
}

int main()
{
 
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    map<pr,li> mp;
    for(int i=0;i<t;i++){
        
        li p,q;
        cin>>p>>q;
        vector<li> rel;
        for(int j=0;j<q;j++){
            li tmp;
            cin>>tmp;
            rel.push_back(tmp);
        } 
        
        printf("Case #%d: %ld\n",i+1,solve(p,rel,q,mp) );

    }
    return 0;
}
