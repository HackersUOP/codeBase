#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

int solve(vector<int> &coins,map<int,int> &mp,int amount){
    if(mp.find(amount)!=mp.end()){
        return mp[amount];
    }     
    if(amount<coins[0]) return -1;
    int ret=INT_MAX;
    for(int i=0;i<coins.size();i++){
        int y1=1+solve(coins,mp,amount-coins[i]);
        if(y1>0) ret=min(ret,y1);
    }
    if(ret==INT_MAX) ret=-1;
    mp[amount]=ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> coins;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        coins.push_back(tmp);
        mp[tmp]=1;
    }
    int amount;
    cin>>amount;
    sort(coins.begin(),coins.end());
    int ans=INT_MAX;
    for(int i=1;i<amount;i++){
        solve(coins,mp,i);
    }
    int y=solve(coins,mp,amount);
    if(y>0) ans=min(ans,y);
    for(int i=amount+1;i<=amount+coins.back();i++){
        int y=solve(coins,mp,i);
        int z=solve(coins,mp,i-amount);
        if(y>0&&z>0) ans=min(ans,y+z);
    }
    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
