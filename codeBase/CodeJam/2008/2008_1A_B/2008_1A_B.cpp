#include <stdio.h>
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

typedef long int li; 
typedef pair<int,int> pr;

struct sort_pred {
    bool operator()(const pr &left, const pr &right) {
        return left.second > right.second;
    }
};

bool solve(vector<vector<pr> > &prefs,vector<int> &ans,vector<int> &def_malts){

    unsigned int i=0;
    while(i<prefs.size()){
        vector<pr> tmp=prefs[i];
        if(tmp.size()==1&&tmp[0].second==1){
            ans[tmp[0].first-1]=1;
            prefs.erase(prefs.begin()+i);
            if(!binary_search(def_malts.begin(),def_malts.end(),tmp[0].first)){
              def_malts.push_back(tmp[0].first);
              sort(def_malts.begin(),def_malts.end());  
            } 
            i--;
        }
        i++;
    }

    unsigned int len=prefs.size();
    //cout<<"len "<<len<<endl;
    unsigned int w=0;
    while(w<prefs.size()){
        vector<pr> tmp=prefs[w];
        unsigned int len=tmp.size();
        if(tmp[0].second==1){
                if(binary_search(def_malts.begin(),def_malts.end(),tmp[0].first)){
                  prefs.erase(prefs.begin()+w);
                  continue;  
                } 
        }
        for(unsigned int j=0;j<tmp.size();j++){
            //cout<<tmp[j].first<<endl;
            sort(def_malts.begin(),def_malts.end());
            if(tmp[j].second==0&&binary_search(def_malts.begin(),def_malts.end(),tmp[j].first)){
              prefs[w].erase(prefs[w].begin()+j);
              if(prefs[w].size()==0) return false;
            } 
        }
        w++;
    }

    for(unsigned int i=0;i<prefs.size();i++){
        if(prefs[i].size()==1&&prefs[i][0].second==1) return solve(prefs,ans,def_malts); 
    }

    return true;
}

int main()
{
 
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        
        int n,m;
        cin>>n>>m;
        vector<vector<pr> > prefs;
        vector<int> def_malts;
        vector<int> ans;
        for(int j=0;j<n;j++){
            ans.push_back(0);
        }
        for(int j=0;j<m;j++){
            int f;
            cin>>f;
            int malt=0;
            bool yn=true;
            vector<pr> temp;
            for(int k=0;k<f;k++){
                int x,y;
                cin>>x>>y;
                pr P=make_pair(x,y);
                temp.push_back(P);
            }
            sort(temp.begin(), temp.end(), sort_pred());
            prefs.push_back(temp);    
        }

        if(solve(prefs,ans,def_malts)){
            cout<<"Case #"<<i+1<<": ";
            for(int j=0;j<n;j++){
                cout<<ans[j]<<" ";
            }
            cout<<endl;
            
            /*for(unsigned int j=0;j<prefs.size();j++){
                for(unsigned int k=0;k<prefs[j].size();k++) cout<<prefs[j][k].first<<","<<prefs[j][k].second<<" ";
                cout<<endl;    
            }
            
            if(binary_search(def_malts.begin(),def_malts.end(),366)) cout<<"YES"<<endl;
            */
        }
        else cout<<"Case #"<<i+1<<": IMPOSSIBLE"<<endl;
    }
    return 0;
}