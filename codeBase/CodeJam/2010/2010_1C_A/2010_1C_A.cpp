#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
#include <sstream>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

ll vec_pos(vector<ll> arr,ll d,ll len){
    
    ll n=len,l=0,r=n-1,x;

	while(l<=r){
		x=(l+r)/2;
		if(arr[x]==d){
			return x;	
		}
		else if(arr[x]>d){
			r=x-1;
		}
		else l=x+1;
	}

	return -1;

}


int main(){

	ios_base::sync_with_stdio(false);
	ll t;
	cin>>t;

	for(ll i=0;i<t;i++){

		vector<ll> lvec,rvec; 
		map<ll,ll> mp;
		ll n;
		ll ans=0;
		cin>>n;
		for(ll j=0;j<n;j++){
			ll a,b;
			cin>>a>>b;
			lvec.push_back(a);
            rvec.push_back(b);
            mp[a]=b;
		} 
		sort(lvec.begin(),lvec.end());
		sort(rvec.begin(),rvec.end());
		map<ll,ll>::iterator iter;
		for(iter=mp.begin();iter!=mp.end();iter++){
		
			ll x=vec_pos(lvec,iter->first,n);
			ll y=vec_pos(rvec,iter->second,n);	
			for(int k=x+1;k<n;k++){
				ll z=vec_pos(rvec,mp[lvec[k]],n);
				if(z<y) ans++;
			}
		}
		printf("Case #%lld: %lld\n",i+1,ans );
		
	}
	return 0;
}
