#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int,int> pr;

int fight(int *arr,int x, int y,int n) {
    int s=0;
    for(int i=0;i<n;i++) {
        if(x&(1<<i)){ 
            if(arr[i]&y) s|=(1<<i);
        }
        if(y&(1<<i)) {
            if(arr[i]&x) s|=(1<<i);
        }
    }
    return s;
}

vector<pr> solve(int *arr,int n) {
    int count[1<<16], rec[1<<16];
    count[0]=0;
    for(int i=1;i<(1<<n);i++) {
        assert((i^(i&-i)) == (i&(i-1)));
        count[i]=1+count[i&(i-1)];
    }
    for(int i=0;i<n;i++) rec[1<<i]=i;

    int f[1<<16];
    memset(f, 0,sizeof(f));
    for(int s=1;s<(1<<n);s++) {
        int c=count[s]; if((c&(c-1))>0) continue;
        if(c==1) { f[s]=s; continue; }
        for(int s0=(s-1); s0>0; s0=(s0-1)&s) {
            int c0=count[s0]; if(c0*2!=c) continue;
            f[s]|=fight(arr,f[s0], f[s^s0],n);
        }
    }

    vector<pr> ans((size_t)n);
    for(pr& p: ans) p.first=9999999, p.second=1;
    for(int s=1;s<(1<<n);s++) {
        int c=count[s]; if((c&(c-1))>0) continue;
        for(int i=0;i<n;i++) if(s&(1<<i)){
            if(f[s]&(1<<i))
                ans[(size_t)i].first=min(ans[(size_t)i].first, n/c/2+1);
            if(f[s]^(1<<i))
                ans[(size_t)i].second=max(ans[(size_t)i].second, n/c+1);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int arr[22];
    int n;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        memset(arr, false, sizeof(arr));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                if(x==1) arr[i]|=(1<<j);
            }
        }
        vector<pr> ans=solve(arr,n);
        printf("Case #%d:\n", i+1);
        for(pr p: ans) printf("%d %d\n",p.first,p.second);
    }
    return 0;
}
