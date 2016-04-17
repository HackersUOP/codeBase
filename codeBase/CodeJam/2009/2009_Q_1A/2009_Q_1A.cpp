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
