#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
using namespace std;

typedef long long ll;

int main() {
    
    ios_base::sync_with_stdio(false);
  ll T;
  cin>>T;
  for(ll i=0;i<T;i++){
    ll L,t,N,C;
    cin>>L>>t>>N>>C;
    vector<ll> cs;
    //if(i==19||i==25) cout<<L<<" "<<t<<" "<<N<<" "<<C<<endl;
    for(ll j=0;j<C;j++){
      ll a;
      cin>>a;
      cs.push_back(a);
    }
    vector<ll> dis;
    ll zsum=0;
    for(ll j=0;j<N;j++){
      ll k=j%C;
      dis.push_back(cs[k]);
      zsum+=cs[k];
    }
    if(L==0){
      printf("Case #%d: %lld\n",i+1,zsum*2 );
      continue;
    }
    ll sum=0,ind=0;
    while(sum<(t/2)){
      sum+=dis[ind];
      ind++;
    }
    ll rem=(sum-t/2);
        //cout<<rem<<endl;
    vector<ll> fin;
    fin.push_back(rem);
    for(ll j=ind;j<N;j++){
      fin.push_back(dis[j]);
    }
    sort(fin.begin(),fin.end());
    ll finsum=t,len=(N-ind+1);
    for(ll j=0;j<len;j++){
            //cout<<fin[j]<<" ";
      if(j<len-L) finsum+=fin[j]*2;
      else finsum+=fin[j];
    }
        //cout<<endl;
    printf("Case #%d: %lld\n",i+1,finsum);

  }

    return 0;
}