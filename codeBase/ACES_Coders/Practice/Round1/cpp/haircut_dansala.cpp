#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef unsigned long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    ll b,n;
    cin >>b>>n;
    ll m[b];
    for(ll i=0ULL;i<b;i++) {
      cin >> m[i];
    }
    ll l = 0ULL, r = 10000000000000000000ULL, t;
    while (l < r) {
      t = (l + r) / 2ULL;
      ll sum = 0ULL;
      for(ll i=0ULL;i<b;i++) 
        sum += t / m[i]+1;
      if (sum >= n)
        r = t;
      else
        l = t + 1ULL;
    }
    cout<<l<<endl;
    return 0;
}