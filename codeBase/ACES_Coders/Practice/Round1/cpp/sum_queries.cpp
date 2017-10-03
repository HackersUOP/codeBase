#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef unsigned long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    int N,M;
    cin>>N>>M; 
    int a[N];
    ll s[N];
    ll sm=0;
    for(int i=0;i<N;i++){
        int t;
        cin>>t;
        sm+=t;
        s[i]=sm;
        a[i]=t;
    }
    for(int i=0;i<M;i++){
        int a1,b;
        cin>>a1>>b;
        cout<<s[b]-s[a1]+a[a1]<<endl;
    }
    return 0;
}