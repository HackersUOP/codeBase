#include <bits/stdc++.h>

using namespace std;

int main(){
	const int mx=1e9;
	int left=0,right=mx,target=1e5,x;
	while(left<right){
		x=(left+right)/2;
		if(x>target) right=x;
		else left=x+1;
	}
	printf("Value of l is %d\n",l);
}