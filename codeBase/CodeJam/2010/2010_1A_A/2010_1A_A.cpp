#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int solve(vector<vector<char> > chars,int n,int K){

	bool blue=false,red=false;
	int len=0;

	for(int j=n-1;j>=0;j--){	
		vector<char> tmp;
		int cns=0,l=0;
		for(int k=n-1;k>=0;k--){
			char c;
			c=chars[j][k];
			if(c!='.'){
                //cout<<c<<" ";
				if(cns!=0&&c==tmp.back()){
					cns++;
					if(cns==K){
						if(c=='R') red=true;
						else blue=true;
                        if(blue&&red){
                          //cout<<"FDG"<<" ";
                          //for(unsigned int b=0;b<tmp.size();b++) cout<<tmp[b]<<" ";
                          //cout<<endl;
                          return 3;  
                        } 
					}
				} 
				else cns=1;	
                tmp.push_back(c);
                chars[j][k]='.';
                l++;
			} 
		}
        //cout<<endl;
		//cout<<l<<endl;
		if(l!=0){
			for(int g=n-1;g>(n-1-l);g--) chars[j][g]=tmp[n-1-g];
			//chars[j].insert(chars[j].begin(),'.');
			len++;
		}

	}
    /*for(int j=0;j<n;j++){
        //cout<<chars[j].size()<<endl;
        for(int k=0;k<n;k++) cout<<chars[j][k]<<" ";
        cout<<endl;
    }
    */
	if(len==0) return 0;
	else{
	    //cout<<"fjskgfshd"<<endl;
		for(int j=n-1;j>=0;j--){
			int cns=0;
			for(int k=n-1;k>=0;k--){
				char c=chars[k][j];
				if(c!='.'){
				if(cns!=0&&c==chars[k+1][j]){
					cns++;
					if(cns==K){
						if(c=='R') red=true;
						else blue=true;
						if(blue&&red) return 3;
					}
				} 
				else cns=1;	
				}
			}
		}

		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
                //cout<<chars[j][k]<<" ";
				int cns=0;
				int row=j,col=k;
				while(row<n-1&&col<n-1){
					char c=chars[row][col];
					if(c!='.'){
						if(c==chars[row+1][col+1]){
							cns++;
							if(cns==K-1){
								if(c=='R') red=true;
								else blue=true;
								if(blue&&red) return 3;
							}
							row++;
							col++;
						} 
						else break;	
					}
					else break;
				}
			}
            //cout<<endl;
		}

		for(int j=n-1;j>=0;j--){
			for(int k=0;k<n;k++){
				int cns=0;
				int row=j,col=k;
				while(row>=1&&col<n-1){
					char c=chars[row][col];
					if(c!='.'){
						if(c==chars[row-1][col+1]){
							cns++;
							//cout<<cns<<endl;
							if(cns==K-1){
								if(c=='R') red=true;
								else blue=true;
								if(blue&&red) return 3;
							}
							row--;
							col++;
						} 
						else break;	
					}
					else break;
				}
			}
		}

			
	}
    if(blue&&!red) return 2;
	else if(!blue&&red) return 1;
	else return 0;
}

int main(){

	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	for(int i=0;i<t;i++){

	int n,K,rows=0;
	cin>>n>>K;
	vector<vector<char> > chars;
	bool yn[n];
	for(int j=0;j<n;j++){
		vector<char> tmp;
		for(int k=0;k<n;k++){
			char c;
			cin>>c;
			tmp.push_back(c);			
		}
		chars.push_back(tmp);
	}
	
	int res=solve(chars,n,K);
    //cout<<res;    
	string s="";
	if(res==0) s="Neither";
	else if(res==1) s="Red";
	else if(res==2) s="Blue";
	else if(res==3) s="Both";
	printf("Case #%d: %s\n",i+1,s.c_str());
}
}
