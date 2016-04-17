/*
Copyright Hackers' Club, University Of Peradeniya
Author : E/13/181
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at *
http://www.apache.org/licenses/LICENSE-2.0 *
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
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
