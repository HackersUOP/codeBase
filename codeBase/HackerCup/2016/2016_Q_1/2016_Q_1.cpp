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

int main(){

	ios_base::sync_with_stdio(false);
	ll t;
	cin>>t;
	for(ll i=0;i<t;i++){
		vector<pr> points; 
		map<ll,map<pr,ll> > mp;
		ll n;
		ll ans=0;
		cin>>n;
		for(ll j=0;j<n;j++){
			ll a,b;
			cin>>a>>b;
			points.push_back(make_pair(a,b));
		} 
		sort(points.begin(),points.end());
		for(ll j=0;j<n-1;j++){
			for(ll k=j+1;k<n;k++){
				ll dist=(points[k].first-points[j].first)*(points[k].first-points[j].first)+(points[k].second-points[j].second)*(points[k].second-points[j].second);	
				if(mp.find(dist)!=mp.end()){
                    if(mp[dist].find(points[j])!=mp[dist].end()) mp[dist][points[j]]++;
                    else mp[dist][points[j]]=1LL;
                    if(mp[dist].find(points[k])!=mp[dist].end()) mp[dist][points[k]]++;
                    else mp[dist][points[k]]=1LL;
                }
				else{
                    map<pr,ll> tmp;
                    tmp[points[j]]=1LL;
                    tmp[points[k]]=1LL;
                    mp[dist]=tmp;
                }	
			}
		}
		map<ll,map<pr,ll> >::iterator iter;
		for(auto &iter:mp){
			map<pr,ll>::iterator iter1;
			for(auto &iter1:iter.second){
				ll y=iter1.second;
				if(y>=2) ans+=y*(y-1LL)/2LL;	
			}
		}
		printf("Case #%lld: %lld\n",i+1,ans);
	}
	return 0;
}
