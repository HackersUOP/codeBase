#include<bits/stdc++.h>
using namespace std;
#define NIL 0
#define INF INT_MAX
typedef long int li;
typedef pair<int,int> pr;

class BipGraph
{
    int m, n;
    vector<vector<int> > adj;
    vector<int> pairU, pairV, dist;
public:
    BipGraph(int, int);
    void addEdge(int, int);
    bool bfs();
    bool dfs(int);
    int hopcroftKarp();
};
int BipGraph::hopcroftKarp()
{
    for (int u = 0; u < m; u++)
        pairU[u] = NIL;
    for (int v = 0; v < n; v++)
        pairV[v] = NIL;
    int result = 0;
    while (bfs()) {
        for (int u = 1; u <= m; u++)
            if (pairU[u] == NIL && dfs(u)) {
                result++;
            }
    }
    return result;
}
bool BipGraph::bfs()
{
    queue<int> Q;
    for (int u = 1; u <= m; u++) {
        if (pairU[u] == NIL)
        {
            dist[u] = 0;
            Q.push(u);
        }
        else dist[u] = INF;
    }
    dist[NIL] = INF;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (dist[u] < dist[NIL]) {
            for (int i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i];
                if (dist[pairV[v]] == INF)
                {
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF);
}
bool BipGraph::dfs(int u)
{
    if (u != NIL)
    {
        for (int i = 0; i < adj[u].size(); ++i)
        {
            int v = adj[u][i];
            if (dist[pairV[v]] == dist[u] + 1)
            {
                if (dfs(pairV[v]) == true)
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}
BipGraph::BipGraph(int m, int n)
{
    this->m = m;
    this->n = n;
    adj.resize(m + 1);
    pairU.resize(m + 1);
    pairV.resize(n + 1);
    dist.resize(m + 1);
}
void BipGraph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}


int main() {
    int tt;
    cin>>tt;
    for(int t=0;t<tt;t++){
        int T,A,B;
        cin>>T>>A>>B;
        vector<pr> AT(A);
        vector<pr> BT(B);
        for(int i=0;i<A;i++){
            int a,b,c,d;
            scanf("%d:%d %d:%d\n",&a,&b,&c,&d);
            //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            AT[i]=make_pair(a*60+b,c*60+d);
        }
        for(int i=0;i<B;i++){
            int a,b,c,d;
            scanf("%d:%d %d:%d\n",&a,&b,&c,&d);
            //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            BT[i]=make_pair(a*60+b,c*60+d);
        }
        BipGraph g1(A,B);
        for(int i=0;i<A;i++){
            for(int j=0;j<B;j++){
                int e=BT[j].second;
                int s=AT[i].first;
                if(s-e>=T) g1.addEdge(i+1,j+1);
            }
        }
        printf("Case #%d: ",t+1);
        cout<<A-g1.hopcroftKarp()<<" ";
        BipGraph g2(B,A);
        for(int i=0;i<B;i++){
            for(int j=0;j<A;j++){
                int e=AT[j].second;
                int s=BT[i].first;
                if(s-e>=T) g2.addEdge(i+1,j+1);
            }
        }
        cout<<B-g2.hopcroftKarp()<<endl;
    }
    return 0;
}
