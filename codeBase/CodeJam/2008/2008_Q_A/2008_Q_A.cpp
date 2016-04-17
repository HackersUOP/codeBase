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
#include <sstream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main(){
 
    ios_base::sync_with_stdio(false);
    string s;
    int t;
    getline(cin,s);
    stringstream(s)>>t;
    for(int i=0;i<t;i++){
        int S;
        getline(cin,s);
        stringstream(s)>>S;
        //cout<<S<<endl;
        vector<string> vec;
        for(int j=0;j<S;j++){
            getline(cin,s);
            //cout<<s<<endl;
        }
        int q,num=0,ans=0;
        bool selected=false;
        getline(cin,s);
        stringstream(s)>>q;
        for(int j=0;j<q;j++){
            getline(cin,s);
            //cout<<s<<endl;
            if(!binary_search(vec.begin(),vec.end(),s)){
                //cout<<"Haha"<<endl;
                num++;
                vec.push_back(s);
                sort(vec.begin(),vec.end());
            }
            if(num==S){
                vec.erase(vec.begin(),vec.end());
                vec.push_back(s);
                ans++;
                num=0;
                selected=true;
            }
            if(selected&&num==S-1){
                vec.erase(vec.begin(),vec.end());
                vec.push_back(s);
                ans++;
                num=0;
            }
        }
        printf("Case #%d: %d\n",i+1,ans);
       
    }
    return 0;
}
