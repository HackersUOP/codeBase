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

string solve(int n,int m,vector<vector<int> > &grid,int rowm[],int colm[]){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp=grid[i][j];
            if(tmp!=rowm[i]&&tmp!=colm[j]) return "NO";
        }
    }
    return "YES";
}

int main(){
 
    ios_base::sync_with_stdio(false);   
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        vector<vector<int> > grid;
        int rowm[n];
        int colm[m];
        for(int j=0;j<n;j++){
            int mx=INT_MIN;
            vector<int> vec;
            for(int k=0;k<m;k++){
                int tmp;
                cin>>tmp;
                mx=(mx>tmp)?mx:tmp;
                vec.push_back(tmp);
            }
            rowm[j]=mx;
            grid.push_back(vec);
        }
        for(int j=0;j<m;j++){
            int mx=INT_MIN;
            for(int k=0;k<n;k++){
                int tmp=grid[k][j];
                mx=(mx>tmp)?mx:tmp;
            }
            colm[j]=mx;
        }
        printf("Case #%d: %s\n",i+1,solve(n,m,grid,rowm,colm).c_str());    
    }
    return 0;
}