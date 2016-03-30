/*
    Description:

    This function uses the recursive definition of the binomial coefficient and dynamic programming in the top-down sense to calculate the binomial coefficient 
    much faster.

    Time Complexity:

    Using this code:

    The map is used to store the pre-calculated values. Before applying the recursive definition, it is checked whether the value exists in the map and is used if it 
    does. If not, it is recursively calculated again. 

    Exampe Input:
    
    50 23

    Example Output:

    108043253365600

*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

map<pr,ll> mp;

ll ncr(ll n,ll r){
 	if(r==0||r==n) return 1;
 	else if(r==1||r==n-1) return n;
 	else if(mp.find(make_pair(n,r))!=mp.end()) return mp[make_pair(n,r)];
 	else{
 		ll val=ncr(n-1,r)+ncr(n-1,r-1);
 		mp[make_pair(n,r)]=val;
 		return val;
 	} 
}

int main(){

	ll n,r;
	cin>>n>>r;
	printf("%lld\n",ncr(n,r));
}
