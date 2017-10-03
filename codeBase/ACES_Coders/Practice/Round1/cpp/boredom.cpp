#include <bits/stdc++.h>

using namespace std;

int dp[10001];

bool isPrime(int n){
    if(n==1) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}

int solve(int n){
    if(n==1) return INT_MAX;
    if(isPrime(n)) return 0;
    if(dp[n]!=-1) return dp[n];
    int ret=INT_MAX;
    for(int i=1;i<n;i++){
        if(isPrime(i)) ret=min(ret,solve(n-i));
    }
    dp[n]=1+ret;
    return 1+ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N; 
    for(int i=0;i<10001;i++) dp[i]=-1;
    cout<<solve(N)<<endl;
    
    return 0;
}