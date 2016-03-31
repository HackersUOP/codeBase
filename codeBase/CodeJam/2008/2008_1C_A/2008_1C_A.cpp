#include <stdio.h>
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll; 

int main()
{
 
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        
        ll p,k,l,sm=0;
        cin>>p>>k>>l;
        vector<ll> vec;
        for(int j=0;j<l;j++) {
            ll tmp;
            cin>>tmp;
            vec.push_back(tmp);
        }
        sort(vec.rbegin(), vec.rend());
        for(int j=0;j<l;j++) {
            sm+=(ll)ceil((double)(j+1)/(double)k)*vec[j];
        }  
        printf("Case #%d: %lld\n",i+1,sm);
    }
    return 0;
}