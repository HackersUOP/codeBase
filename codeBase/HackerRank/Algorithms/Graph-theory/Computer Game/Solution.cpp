/*
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement:  Sophia is playing a game on the computer. There are two random arrays A & B, each having the same number of 
                        elements. The game begins with Sophia removing a pair (Ai, Bj) from the array if they are not co-prime. She 
                        keeps a count on the number of times this operation is done.
                        Sophia wants to find out the maximal number of times(S) she can do this on the arrays. Could you help Sophia
                        find the value?
                        
    Constraints:  0 < n <= 10^5
                  2 <= A[i], B[i] <= 10^9
                  Each element in both arrays are generated randomly between 2 and 10^9
    
    Approach:   (1). Sieve the prime numbers efficiently which are needed to factorize the numbers in array A and B.
                (2). Build a network consisting three layers: array A, primes, array B.
                (3). Link elements in A and B with their prime factors in the prime layer (with unit edge capacity).
                (4). Find the maximum flow (I've used dinitz algorithm).
                 
*/

#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int v, flow;
    Edge(int v, int flow) : v(v), flow(flow) {}
};

bool prime[32000];
int fprime[32000];
vector<int> p;
vector<vector<int>> graph;
vector<Edge> edges;
vector<int> level;
vector<int> last;

// Sieve of Eratosthenes (Sieve primes upto sqrt(1e9) i.e. upto 3401th prime which is:
// 31607 * 31607 = 999002449).
void sieve() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= 32000; ++i)
        if (prime[i])
            for (int j = i * i; j < 32000; j += i)
                if (prime[j])
                {
                    prime[j] = false;
                    fprime[j] = i;
                }
    for (int i = 0 ; i < 32000; i++)
        if (prime[i])
            p.push_back(i);
}

// Find the prime factors of numbers less than 31607.
vector<int> getFactors(int n) {
    vector<int> factors;
    while (n > 1) {
        int r = prime[n] ? n : fprime[n];
        factors.push_back(r);
        while (n % r == 0)
            n /= r;
    }
    return factors;
}

// Handle the numbers larger than 31607.
vector<int> getFactorsBig(int n) {
    if (n < 32000)
        return getFactors(n);
    vector<int> factors;
    for (int i = 0; i < p.size() && p[i] * p[i] <= n; i++) {
        if (n % p[i] == 0) {
            factors.push_back(p[i]);
            while (n % p[i] == 0)
                n /= p[i];
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

// Find augmenting paths using breadth first search.
bool bfs(int s, int t)
{
    level.assign(graph.size(), -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++)
        {
            Edge &e = edges[graph[u][i]];
            if (e.flow > 0 && level[e.v] == -1)
            {
                level[e.v] = level[u] + 1;
                q.push(e.v);                    
            }
        }
    }
    return level[t] != -1;
}

// Augment the augmenting path which is found by the breadth first search.
int dfs(int s, int t, int u, int flow)
{
    if (u == t)
        return flow;
    for (int &i = last[u]; i < graph[u].size(); i++)
    {
        int id = graph[u][i];
        Edge &e = edges[id];
        if (e.flow > 0 && level[e.v] == level[u] + 1)
        {
            int res = dfs(s, t, e.v, min(flow, e.flow));
            if (res > 0)
            {
                e.flow -= res;
                edges[id ^ 1].flow += res;
                return res;
            }
        }
    }
    level[u] = -1;
    return 0;
}

int computerGame(int n, int A[], int B[]) {
    vector<int> primes;
    vector<vector<int>> facA(n), facB(n);
    // Primes corresponding to elements in A.
    for (int i = 0; i < n; i++) {
        facA[i] = getFactorsBig(A[i]);
        primes.insert(primes.end(), facA[i].begin(), facA[i].end());
    }
    // Primes corresponding to elements in B.
    for (int i = 0; i < n; i++) {
        facB[i] = getFactorsBig(B[i]);
        primes.insert(primes.end(), facB[i].begin(), facB[i].end());
    }
    // Remove duplicates.
    sort(primes.begin(), primes.end());
    primes.erase(unique(primes.begin(), primes.end()), primes.end());

    int total = 0, N = 2 * n + primes.size() + 2;
    int s = 0, t = N - 1;
    // Residual graph.
    graph.resize(N);

    // Add edges from source to A and B to sink.
    for (int i = 1; i <= n; i++) {
        edges.push_back(Edge(i, 1));
        edges.push_back(Edge(s, 0));
        graph[s].push_back(edges.size() - 2);
        graph[i].push_back(edges.size() - 1);

        edges.push_back(Edge(t, 1));
        edges.push_back(Edge(n + primes.size() + i, 0));
        graph[n + primes.size() + i].push_back(edges.size() - 2);
        graph[t].push_back(edges.size() - 1);
    }
    // Add edges from A to primes.
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < facA[i - 1].size(); j++) {
            int k = lower_bound(primes.begin(), primes.end(), facA[i - 1][j]) - primes.begin();
            edges.push_back(Edge(n + k + 1, 1));
            edges.push_back(Edge(i, 0));
            graph[i].push_back(edges.size() - 2);
            graph[n + k + 1].push_back(edges.size() - 1);
        }
    }
    // Add edges from primes to B.
    for (int i = 1 + n + primes.size(); i <= 2 * n + primes.size(); i++) {
        for (int j = 0; j < facB[i - n - primes.size() - 1].size(); j++) {
            int k = lower_bound(primes.begin(), primes.end(), facB[i - n - primes.size() - 1][j]) - primes.begin();
            edges.push_back(Edge(i, 1));
            edges.push_back(Edge(n + k + 1, 0));
            graph[n + k + 1].push_back(edges.size() - 2);
            graph[i].push_back(edges.size() - 1);
        }
    }

    // Find augmenting paths and augment.
    while (bfs(s, t)) {
        last.assign(N, 0);
        while (int flow = dfs(s, t, s, INT_MAX))
            total += flow;
    }
    return total;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int A[n], B[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    sieve();
    cout << computerGame(n, A, B) << endl;
    return 0;
}
