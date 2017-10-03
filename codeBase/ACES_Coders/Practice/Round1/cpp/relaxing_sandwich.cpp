#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    int p,a,b;
    cin>>p>>a>>b;
    if(b>p) cout<<-1<<endl;
    else cout<<b+max(p-b,a)<<endl;
    return 0;
}