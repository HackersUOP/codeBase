#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int dp[10001];

int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    int a[N];
    ll *s=(ll*) malloc(sizeof(ll)*N);
    ll sm=0;
    for(int i=0;i<N;i++){
        int t;
        scanf("%d",&t);
        sm+=t;
        s[i]=sm;
        a[i]=t;
    }
    for(int i=0;i<M;i++){
        int a1,b;
        scanf("%d %d",&a1,&b);
        cout<<s[b]-s[a1]+a[a1]<<endl;
    }
    free(s);
    return 0;
}