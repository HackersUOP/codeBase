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
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,s,p,ans=0;
        cin>>n>>s>>p;
        vector<int> vec;
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            vec.push_back(tmp);
        }
        sort(vec.begin(),vec.end());
        int S=0;
        int ind=0;
        while((S<s)&&(ind<n)){
            int y=vec[ind];
            int w=INT_MIN;
            if(y%3==0){
              if(y>=3) {
                w=y/3;
                if(w<p){
                  w=(y-3)/3+2;
                  if(w>=p) {S++;ans++;}  
                }
                else ans++;
                }
                else {
                    w=y/3;
                    if(w>=p) ans++;
                }
            } 
            else if(y%3==1){
                w=(y-1)/3+1;
                if(w>=p) ans++;
            } 
            else{
                w=(y-2)/3+1;
                if(w<p){
                    w=(y-2)/3+2;
                    if(w>=p) {S++;ans++;}      
                }
                else ans++;
            } 
            //cout<<y<<","<<w<<endl;
            ind++;
        }
        for(int j=ind;j<n;j++){
            int y=vec[j];
            int w=INT_MIN;
            if(y%3==0) w=y/3;
            else if(y%3==1) w=(y-1)/3+1;
            else w=(y-2)/3+1;
            //cout<<y<<","<<w<<endl;
            if(w>=p) ans++;
        }
        printf("Case #%d: %d\n",i+1,ans);    
    }
    return 0;
}