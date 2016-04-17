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
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

typedef long double ld;
typedef long long ll; 

bool exist(vector<char> chars,char c,int n){

    int l=0,r=n-1,x;
    while(l<=r){
        x=(l+r)/2;
        if(chars[x]==c) return true;
        else if(chars[x]>c) r=x-1;
        else l=x+1;
    }
    return false;
}

int main()
{
 
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        
        string s;
        vector<char> chars;
        map<char,ld> mp;
        cin>>s;
        int len=s.size(),n=0;
        ld ans=0.0,base=0.0;
        for(int j=0;j<len;j++){
            char c=s[j];
            sort(chars.begin(),chars.end());
            if(!exist(chars,c,n)){
                base++;
                chars.push_back(c);
                n++;
            }
        }
        /*if(base==1.0){
            printf("Case #%d: %d\n",i+1,1);
            continue;
        }*/
        if(base==1.0) base=2.0;     
        mp[s[0]]=1.0;
        ld last=1.0;

        for(int j=0;j<len;j++){
            ld pw=(ld) (len-1-j);
            char c=s[j];
            if(mp.find(c)!=mp.end()){
              if(mp[c]!=0.0) ans+=mp[c]*pow(base,pw);  
            } 
            else if(last==1.0){
              mp[c]==0.0;
              last=0.0;  
            } 
            else if(last==0.0){
                last=2.0;
                mp[c]=2.0;
                ans+=2.0*pow(base,pw);
            }
            else{
                last++;
                mp[c]=last;
                ans+=last*pow(base,pw);
            }
        }
        ll answer=(ll) ans;
        printf("Case #%d: %lld\n",i+1,answer);

    }
    return 0;
}
