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

typedef long long ll; 

ll solve(ll arr[],ll r,ll k,ll n){

    if(n==1) return r*arr[0];
    ll ind=0LL;
    ll turn=0LL;
    ll len=0L;
    vector<vector<ll> > mem; 
    vector<ll> sums;
    //cout<<r<<endl;
    while(turn<r){
        ll p_sum=0;
        vector<ll> tmp;
        while(p_sum+arr[ind]<=k){
            p_sum+=arr[ind];
            tmp.push_back(ind);
            ind=(ind+1==n)?0:ind+1;
        }
        //cout<<"fsdfs "<<p_sum<<" "<<ind<<endl;
        for(ll y=0;y<len;y++){
            //cout<<"In"<<endl;
            if(mem[y]==tmp){
              //cout<<"Haha "<<y<<endl;
              if(y!=0L){
                ll e=(r-y)%(turn-y);
                e=(e==0)?0:(sums[(r-y)%(turn-y)-1+y]-sums[y-1]); 
                return sums[y-1]+(sums[turn-1]-sums[y-1])*((r-y)/(turn-y))+e;    
              }
              else{
                ll e=r%turn;
                e=(e==0)?0:(sums[(r)%(turn)-1]); 
                //cout<<sums[turn-1]<<" "<<(r/turn)<<" "<<e<<endl;  
                return (sums[turn-1])*(r/turn)+e;   
              }  
                
            } 
        }
        //cout<<"dfsfsdfs"<<endl;
        mem.push_back(tmp);
        len++;
        if(sums.size()==0) sums.push_back(p_sum);
        else sums.push_back(p_sum+sums.back());
        turn++;
        //cout<<"turn "<<turn<<endl;
    }
    //cout<<"Out"<<endl;
    return sums.back();
}

int main(){
 
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        
        ll r,k,n;
        cin>>r>>k>>n;
        ll arr[1000];
        ll sm=0L;
        for(ll j=0;j<n;j++){
            ll b;
            cin>>b;
            arr[j]=b;
            sm+=b;
        }

        if(sm<=k) printf("Case #%d: %lld\n",i+1,sm*r); 
        else printf("Case #%d: %lld\n",i+1,solve(arr,r,k,n));

    }
    return 0;
}
