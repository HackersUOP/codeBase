#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(vector<vector<char> > &grid,int r,int c){
    int ans=0;
    for(int j=0;j<r;j++){
        for(int k=0;k<c;k++){
            char ch=grid[j][k];
            if(ch=='.') continue;
            bool up=false,down=false,right=false,left=false;
            for(int g=j-1;g>=0;g--) if(grid[g][k]!='.') {up=true;break;};
            for(int g=j+1;g<r;g++) if(grid[g][k]!='.') {down=true;break;}
            for(int g=k+1;g<c;g++) if(grid[j][g]!='.') {right=true;break;}
            for(int g=k-1;g>=0;g--) if(grid[j][g]!='.') {left=true;break;}    
            if(ch=='^'){
                 if(!up){
                    if(down||right||left) ans++;
                    else return -1;
                 }   
            }
            if(ch=='>'){
                 if(!right){
                    if(down||up||left) ans++;
                    else return -1;
                 }   
            }
            if(ch=='<'){
                 if(!left){
                    if(down||right||up) ans++;
                    else return -1;
                 }   
            }
            if(ch=='v'){
                 if(!down){
                    if(up||right||left) ans++;
                    else return -1;
                 }   
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int r,c;
        cin>>r>>c;
        vector<vector<char> > grid;
        for(int j=0;j<r;j++){
            vector<char> vec;
            for(int k=0;k<c;k++){
                char ch;
                cin>>ch;
                vec.push_back(ch);
            }
            grid.push_back(vec);
        }
        int ret=solve(grid,r,c);
        if(ret!=-1) printf("Case #%d: %d\n",i+1,ret);
        else printf("Case #%d: IMPOSSIBLE\n",i+1);
    }
    return 0;
}
