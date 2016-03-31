#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
#include <sstream>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

bool exist(vector<string> arr,string s,int len){
    
    int n=len,l=0,r=n-1,x;

	while(l<=r){
		x=(l+r)/2;
		if(arr[x]==s){
			return true;	
		}
		else if(arr[x]>s){
			r=x-1;
		}
		else l=x+1;
	}

	return false;

}

int main(){

	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	for(int i=0;i<t;i++){

		vector<string> arr; 
		int n,m,ans=0,len=0;
		cin>>n>>m;
		for(int j=0;j<n;j++){
			string s;
			cin>>s;
			arr.push_back(s);
            len++;
		} 
		for(int j=0;j<m;j++){
			string parsed,input,check_str="";
			cin>>input;
			stringstream ss(input);

			while(getline(ss,parsed,'/')){
			    if(parsed!=""){
			     //cout<<parsed<<" "<<endl;
			     check_str+="/"+parsed;
			     //cout<<check_str<<" "<<endl;
                 sort(arr.begin(),arr.end());
			     if(!exist(arr,check_str,len)){
			     	ans++;
			     	arr.push_back(check_str);
                    len++;
			     }    
			  } 
			}
		}
		printf("Case #%d: %d\n",i+1,ans );
		
	}
}
