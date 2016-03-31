#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cfloat>

using namespace std;

typedef pair<int,double> pr;

bool pairCompare(const pr &one,const pr &two){
    if(one.second==two.second) return one.first<two.first;
    return one.second<two.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<pr> vec;
        vector<double> arr;
        for(int j=0;j<n;j++){
            double tmp;
            cin>>tmp;
            arr.push_back(tmp);
        }
        for(int j=0;j<n;j++){
            double tmp;
            cin>>tmp;
            if(tmp==0) vec.push_back(make_pair(j,DBL_MAX)); 
            else vec.push_back(make_pair(j,arr[j]/tmp));
        }
        sort(vec.begin(),vec.end(),pairCompare);
        cout<<"Case #"<<i+1<<": ";
        for(int j=0;j<n;j++){
            cout<<vec[j].first<<" ";
        }
        cout<<endl;
    }
    return 0;
}
