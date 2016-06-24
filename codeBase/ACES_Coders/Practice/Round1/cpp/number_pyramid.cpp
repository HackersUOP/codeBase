#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<ll> vec;
    ll mx=0;
    for(ll i=0;i<n;i++){
        vector<ll> arr;
        for(ll j=0;j<i+1;j++){
            ll tmp;
            cin>>tmp;
            arr.push_back(tmp);
        }
        if(i==0){
            vec=arr;
            continue;
        }
        vector<ll> a(i+1);
        for(ll j=0;j<i+1;j++) a[j]=INT_MIN;
        for(ll j=0;j<i;j++){
            a[j]=max(a[j],arr[j]+vec[j]);
            a[j+1]=max(a[j+1],arr[j+1]+vec[j]);
            mx=max(mx,max(a[j],a[j+1]));
        }
        vec=a;
    }
    cout<<mx<<endl;
    return 0;
}