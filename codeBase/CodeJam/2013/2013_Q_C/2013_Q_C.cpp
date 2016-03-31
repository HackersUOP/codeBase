#include <stdio.h>
#include <iostream>
#include <sstream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <memory>
#include <string>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int,int> pr;

string pad(string s,ll b){
    string ret=s;
    for(int f=0;f<(b-s.size())/2;f++) ret="0"+ret+"0";
    return ret; 
}

int main(){
 
    ios_base::sync_with_stdio(false);   
    vector<vector<ll> > palindromes;
    vector<ll> one{1,2,3,4,5,6,7,8,9};
    vector<ll> two{11,22,33,44,55,66,77,88,99};
    palindromes.push_back(one);
    palindromes.push_back(two);
    for(ll i=3;i<=7;i++){
        vector<ll> tmp;
        string zs="";
        for(int u=0;u<=(i-3);u++) zs+="0";
        for(int k=1;k<10;k++){
            string e=to_string(k)+zs+to_string(k);
            string::size_type sz = 0;
            ll num=stoll(e,&sz,0);
            tmp.push_back(num);
            for(int g=(i+1)%2;g<=(i-3);g+=2){
                vector<ll> mid=palindromes[g];
                for(ll j=0;j<mid.size();j++){
                    string s; 
                    s=to_string(k)+pad(to_string(mid[j]),(i-2))+to_string(k);
                    string::size_type sz = 0;
                    ll num=stoll(s,&sz,0);
                    tmp.push_back(num);
                }        
            }    
        }
        sort(tmp.begin(),tmp.end());
        palindromes.push_back(tmp);
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll A,B,ans=0;
        cin>>A>>B;
        ll a=(ll)ceil(sqrt((long double)A));
        ll b=(ll)floor(sqrt((long double)B));
        if(b==10000000L) b=9999999L;
        ll a_length=to_string(a).size();
        ll b_length=to_string(b).size();
        ll a_ind=-1,b_ind=-1;
        vector<ll> a_vec=palindromes[a_length-1];
        vector<ll> b_vec=palindromes[b_length-1];
        for(ll j=0;j<a_vec.size();j++) if(a_vec[j]>=a) {a_ind=j;break;}
        for(ll j=0;j<b_vec.size();j++){
                if(b_vec[j]>=b){
                    if(b_vec[j]>b) b_ind=j-1;
                    else b_ind=j;
                    break;
                }  
        } 
        if(a_length==b_length){
            for(ll j=a_ind;j<=b_ind;j++){
                ll j2=a_vec[j]*a_vec[j];
                string S1=to_string(j2);
                string S2=S1;
                reverse(S1.begin(),S1.end());
                if(S1==S2) {ans++;}
            }    
        }
        else{
            for(ll j=a_ind;j<a_vec.size();j++){
                ll j2=a_vec[j]*a_vec[j];
                string S1=to_string(j2);
                string S2=S1;
                reverse(S1.begin(),S1.end());
                if(S1==S2) {ans++;}
            }   
        }    
        if(b_length>a_length){
                for(ll j=0;j<=b_ind;j++){
                ll j2=b_vec[j]*b_vec[j];
                string S1=to_string(j2);
                string S2=S1;
                reverse(S1.begin(),S1.end());
                if(S1==S2) {ans++;}
                } 
        }
        if(b_length>a_length+1){
            for(ll j=a_length;j<b_length-1;j++){
                vector<ll> temp=palindromes[j];
                for(ll k=0;k<temp.size();k++){
                    ll j2=temp[k]*temp[k];
                    string S1=to_string(j2);
                    string S2=S1;
                    reverse(S1.begin(),S1.end());
                    if(S1==S2) {ans++;}
                }
            }
        } 
        printf("Case #%d: %lld\n",i+1,ans);    
    }
    return 0;
}