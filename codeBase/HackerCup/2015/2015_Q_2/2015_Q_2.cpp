#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

typedef tuple<int,int,int> tr;

tr operator-(const tr &one,const tr &two){
    tr ret;
    get<0>(ret)=get<0>(one)-get<0>(two);
    get<1>(ret)=get<1>(one)-get<1>(two);
    get<2>(ret)=get<2>(one)-get<2>(two);
    return ret;
}

bool solve(vector<tr> &vec,map<tr,bool> &mp,tr trans){
    if(get<0>(trans)<10) return false;
    if(get<1>(trans)<10) return false;
    if(get<2>(trans)<10) return false;
    if(binary_search(vec.begin(),vec.end(),trans)) return true;
    if(mp.find(trans)!=mp.end()) return mp[trans];
    for(int i=0;i<vec.size();i++){
        tr tri=trans-vec[i];
        if(solve(vec,mp,tri)) {
            mp[tri]=true;
            return true;
        }
        else{
            mp[tri]=false;
        }
    }
    mp[trans]=false;
    return false;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int i1,i2,i3;
        cin>>i1>>i2>>i3;
        tr target=make_tuple(i1,i2,i3);
        int n;
        cin>>n;
        vector<tr> vec;
        map<tr,bool> mp;
        for(int j=0;j<n;j++){
            int i1,i2,i3;
            cin>>i1>>i2>>i3;
            vec.push_back(make_tuple(i1,i2,i3));
        }
        sort(vec.begin(),vec.end());
        if(solve(vec,mp,target)) printf("Case #%d: yes\n",i+1);
        else printf("Case #%d: no\n",i+1);
    }
    return 0;
}
