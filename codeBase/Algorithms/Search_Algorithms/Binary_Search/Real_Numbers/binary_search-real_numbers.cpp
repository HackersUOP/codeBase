#include <bits/stdc++.h>

using namespace std;

int main(){
    const double mx=1e9,eps=1e-5;
    double left=0,right=mx,target=1e5,x;
    while((right-left)>eps){
        x=(left+right)/2;
        if(x-target>=eps) right=x;
        else left=x;
    }
    printf("Value of left is %lf which is equal to our initial target with an error of less than 10^-5.\n",left);

}