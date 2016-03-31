#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

ll solve(vector<ll> &machines,ll L,ll n,ll m,ll d){
    ll l = 0, r = 1e18, x;
    while(l<r){
        x=(l+r)/2;
        ll sum=0;
        for(ll i=0;i<n;i++)
            sum+=x/machines[i];
        if(sum>=L)
            r=x;
        else
            l=x+1;
    }
    //cout<<l<<endl;
    vector<ll> times;
    for(ll i=0;i<n;i++){
        ll num=l/machines[i];
        for(ll j=0;j<num;j++) times.push_back(machines[i]*(j+1));
    }
    sort(times.begin(),times.end());
    //for(ll i=0;i<times.size();i++) cout<<times[i]<<" ";
    //cout<<endl;
    ll ind=L-m*(ll)ceil((ld)L/(ld)m-1.0)-1;
    //cout<<ind<<endl;
    ll start=times[ind];
    for(ll i=ind+m;i<L;i+=m){
        start=max(start+d,times[i]);
    }
    return start+d;
}

int main() {
    freopen("D:/Programming/C++/HackerCup/2016_1_B/laundro_matt.txt", "r", stdin); 
    freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll L,n,m,d;
        scanf("%lld %lld %lld %lld",&L,&n,&m,&d);
        vector<ll> machines;
        for(ll j=0;j<n;j++){
            ll tmp;
            scanf("%lld",&tmp);
            machines.push_back(tmp);
        } 
        printf("Case #%d: %lld\n",i+1,solve(machines,L,n,m,d));
    }
    return 0;
}
