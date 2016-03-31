#include <stdio.h>
#include <float.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<vector<vector<ll> >,vector<vector<ll> > > Key;

ll findh(vector<vector<ll> > vecb,vector<vector<ll> > vect,map<Key,ll > &mp);

ll solve(vector<vector<ll> > vecb,vector<vector<ll> > vect,map<Key,ll > &mp){

    /*cout<<endl;
    for(unsigned int i=0;i<vecb.size();i++){
        cout<<vecb[i][0]<<" "<<vecb[i][1]<<" "; 
    }
    cout<<endl;
    for(unsigned int i=0;i<vect.size();i++){
        cout<<vect[i][0]<<" "<<vect[i][1]<<" "; 
    }
    cout<<endl<<endl;
    
    cout<<"map"<<" ";
    for(auto iter:mp){
            cout<<iter.second<<" ";
        }
    cout<<endl;
    */
	if(vecb.size()==0||vect.size()==0) return 0;
	if(vecb[0][1]==vect[0][1]){
		ll a=vecb[0][0],b=vect[0][0];
		if(a>b){
			vecb[0][0]=a-b;
			vect.erase(vect.begin());
			return (b+findh(vecb,vect,mp));
		}
		else if(a<b){
			vect[0][0]=b-a;
			vecb.erase(vecb.begin());
			return (a+findh(vecb,vect,mp));	
		}
		else{
			vecb.erase(vecb.begin());
			vect.erase(vect.begin());
			return (a+findh(vecb,vect,mp));
		}
	}
	else{
		vector<ll> temp=vecb[0];
		vecb.erase(vecb.begin());
		ll ret1=findh(vecb,vect,mp);
		vecb.insert(vecb.begin(),temp);
		vect.erase(vect.begin());
		ll ret2=findh(vecb,vect,mp);
		ll ret=(ret1>ret2)?ret1:ret2;
		return ret;
	}
}

ll findh(vector<vector<ll> > vecb,vector<vector<ll> > vect,map<Key,ll > &mp){
	Key pr;
	pr.first=vecb;
	pr.second=vect;

    
    if(mp.find(pr)==mp.end()){
        ll val=solve(vecb,vect,mp);
          mp.insert(make_pair(pr,val));
        /*cout<<"map"<<" ";
    for(auto iter:mp){
            cout<<iter.second<<" ";
        }
    cout<<endl;*/
          return val;
    }
    else{       
          //cout<<"fafadsfsdsfsd"<<endl;  
          return mp.at(pr);  
    }
    
}

int main(){

	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i){
		int n,m;
		cin>>n>>m;
		vector<vector<ll> > vecb;
		vector<vector<ll> > vect;
        map<Key,ll > mp;
		for(int j=0;j<n;j++){
			vector<ll> temp;
			ll num,type;
			cin>>num>>type;
			vecb.push_back(temp);
			vecb[j].push_back(num);
			vecb[j].push_back(type);
		}
		for(int j=0;j<m;j++){
			vector<ll> temp;
			ll num,type;
			cin>>num>>type;
			vect.push_back(temp);
			vect[j].push_back(num);
			vect[j].push_back(type);
		}

		printf("Case #%d: %lld\n",i+1,solve(vecb,vect,mp));
        
}
}