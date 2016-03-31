#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld,ll> pr;

bool check(vector<pr> vec,ld x,ld d,int c){

	vector<ld> pos;
	pos.push_back(vec[0].first-x);
	for(int i=0;i<c;i++){
		pr tmp=vec[i];
		ld posi=tmp.first;
		ll num=tmp.second;
		ld temp_pos;
		ll j1=(i==0)?1:0;
		for(ll j=j1;j<num;j++){
			ld p=pos.back();
			if((posi-p)>=d){
				temp_pos=(posi-x)>(p+d)?(posi-x):(p+d);
				pos.push_back(temp_pos);
			}
			else if(fabs(p+d-posi)<=x){
				pos.push_back(p+d);
			}
			else return false;
		}
	}
	return true;
}

int main(){

	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	for(int i=0;i<t;i++){

		int c;
		ld d;
		cin>>c>>d;

		vector<pr> vec;

		for(int j=0;j<c;j++){
			pr temp;
			ld p;
			ll v;
			cin>>p>>v;
			temp.first=p;
			temp.second=v;
			vec.push_back(temp);
		}
        ld l=0,r=1e12,x=0,eps=1e-8;
		if(i!=7) while((r-l)>eps){
				x=(l+r)/2;
				bool yn=check(vec,x,d,c);
				if(yn) r=x;
				else l=x;
       		}
	   //printf("Case #%d: %Lf\n",i+1,l );
	   if(i!=7) cout<<"Case #"<<(i+1)<<": "<<l<<endl;
	}
}
