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

int main(){
 
    ios_base::sync_with_stdio(false);   
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int x,y;
        int grid1[4][4];
        int grid2[4][4];
        cin>>x;
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++) cin>>grid1[j][k];
        }
        cin>>y;
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++) cin>>grid2[j][k];
        }
        int ans;
        int num=0;
        for(int j=0;j<4;j++){
            int tmp=grid1[x-1][j];
            for(int k=0;k<4;k++){
                if(tmp==grid2[y-1][k]){
                    ans=tmp;
                    num++;
                } 
            }
        }
        if(num==1) printf("Case #%d: %d\n",i+1,ans);
        else if(num>1) printf("Case #%d: Bad magician!\n",i+1);
        else printf("Case #%d: Volunteer cheated!\n",i+1);
    }
    return 0;
}