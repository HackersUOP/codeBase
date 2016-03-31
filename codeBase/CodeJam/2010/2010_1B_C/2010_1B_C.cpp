#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

ll find_ncr(map<pr,ll> &map_ncr,ll n,ll k);
ll find_sett(map<pr,ll> &map_sett,map<pr,ll> &map_ncr,ll m,ll r);

ll ncr(map<pr,ll> &map_ncr,ll n,ll k){

	if(k==0||k==n) return 1;
	else if(k==1||k==n-1) return n;
	else{
		return (find_ncr(map_ncr,n-1,k))%100003+(find_ncr(map_ncr,n-1,k-1))%100003;
	} 
}

ll find_ncr(map<pr,ll> &map_ncr,ll n,ll k){

	pr p;
	p.first=n;
	p.second=k;
	if(map_ncr.find(p)!=map_ncr.end()){
		return map_ncr[p];
	}
	else{
		ll ret=ncr(map_ncr,n,k);
		map_ncr[p]=ret;
		return ret;
	}

}

ll sett(map<pr,ll> &map_sett,map<pr,ll> &map_ncr,ll m,ll r){

	if(r==1||r==2||r==m-1) return 1;
	ll top=m-(r+1);
	ll cind=0,sind=r-1;
	ll ret=0;
	while((cind<=top)&&(sind>=1)){
		ret+=find_sett(map_sett,map_ncr,r,sind)*ncr(map_ncr,top,cind);
		cind++;
		sind--;
	}

	return ret%100003;
}

ll find_sett(map<pr,ll> &map_sett,map<pr,ll> &map_ncr,ll m,ll r){

	pr p;
	p.first=m;
	p.second=r;
	if(map_sett.find(p)!=map_sett.end()){
		return map_sett[p];
	}
	else{
		ll ret=sett(map_sett,map_ncr,m,r);
		map_sett[p]=ret;
		return ret;
	}

}

int main(){

	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	map<pr,ll> map_sett;
	map<pr,ll> map_ncr;


	for(int i=0;i<t;i++){

		ll n;
		cin>>n;
		ll ans=0;
		for(ll j=1;j<n;j++){
			ans+=sett(map_sett,map_ncr,n,j);
		}
		ans=ans%100003;
		printf("Case #%d: %lld\n",i+1,ans );
		
	}
}
