#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

bool solve(vector<vector<char> > &array,int r,int c){

	for(int j=0;j<r;j++){
		for(int k=0;k<c;k++){
			if(array[j][k]=='#'){
				array[j][k]='/';
				if(k+1==c||j+1==r) return false;
				else if(array[j+1][k]!='#') return false;
				else if(array[j+1][k+1]!='#') return false;
				else if(array[j][k+1]!='#') return false;
				else{
					array[j+1][k]='\\';
					array[j+1][k+1]='/';
					array[j][k+1]='\\';
				}
			}
		}
	}
	return true;
}

int main(){

	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	for(int i=0;i<t;i++){

	int r,c;
	cin>>r>>c;
	vector<vector<char> > array;
	for(int j=0;j<r;j++){
		vector<char> temp;
		for(int k=0;k<c;k++){
			char c;
			cin>>c;
			temp.push_back(c);
		}
		array.push_back(temp);
	}

	if(!solve(array,r,c)) printf("Case #%d:\nImpossible\n",i+1 );
	else{
        printf("Case #%d:\n",i+1 );
		for(int j=0;j<r;j++){
		for(int k=0;k<c;k++){
			printf("%c",array[j][k]);
		}
		printf("\n");
	}
	} 
	}
}
