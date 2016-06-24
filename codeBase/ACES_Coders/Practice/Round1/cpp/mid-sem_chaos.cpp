#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;
    bool vec[N][M];
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) vec[i][j]=false;
        for(int i=0;i<N;i++){
        int K;
        cin>>K;
        for(int j=0;j<K;j++){
            int tmp;
            cin>>tmp;
            vec[i][tmp-1]=true;
        }
    }
    int mn=INT_MAX;
    for(int i=0;i<(1<<N);i++){
        bool f[M];
        for(int j=0;j<M;j++) f[j]=false;
        int c=0;
        for(int j=0;j<N;j++){
            if((1<<j)&i){
                c++;
                for(int k=0;k<M;k++) if(vec[j][k]) f[k]=true;
            }
        }
        for(int j=0;j<M;j++) if(!f[j]) goto here;
            mn=min(mn,c);
        here:;
    }
    cout<<((mn==INT_MAX)?-1:mn)<<endl;
    return 0;
}