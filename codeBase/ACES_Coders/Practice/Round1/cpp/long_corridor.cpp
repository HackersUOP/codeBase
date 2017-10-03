#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int comp(pr & p1,pr &p2){
    ll x1=p1.first;
    ll y1=p1.second;
    ll x2=p2.first;
    ll y2=p2.second;
    if(x1==x2 && y1==y2) return 0;
    else if(y2*x1-x2*y1<0LL) return -1;
    else return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    pr times[n];
    ll ans=0;
    for(int i=0;i<n;i++){
        ll x,v;
        cin>>x>>v;
        ll g=gcd(x,v);
        pr t=make_pair(x/g,v/g);
        if(i==0){
            times[i]=t;
            ans++;
            continue;
        }
        if(comp(t,times[i-1])<=0) times[i]=times[i-1];
        else{
            times[i]=t;
            ans++;
        } 
    }
    cout<<ans<<endl;
    
    return 0;
}