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


int main(){
 
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        
        ll n,k;
        cin>>n>>k;
        string s;
        ll n2=(ll)pow(2.0f,(double)n);
        if((k+1)%n2==0) s="ON";
        else s="OFF"; 
        printf("Case #%d: %s\n",i+1,s.c_str()); 

    }
    return 0;
}