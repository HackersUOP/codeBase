/*
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement:  There are N bikers present in a city (shaped as a grid) having M bikes. All the bikers want to participate in 
                        the HackerRace competition, but unfortunately only K bikers can be accommodated in the race. Jack is organizing 
                        the HackerRace and wants to start the race as soon as possible. He can instruct any biker to move towards any 
                        bike in the city. In order to minimize the time to start the race, Jack instructs the bikers in such a way that 
                        the first K bikes are acquired in the minimum time.
                        Every biker moves with a unit speed and one bike can be acquired by only one biker. A biker can proceed in any 
                        direction. Consider distance between bikes and bikers as Euclidean distance.
                        Jack would like to know the square of required time to start the race as soon as possible.
                        
    Approach:   Assume we know the minimum time required for the K bikers to aquire one bike for each. Now all we have to do is to find 
                the maximum matches possible to match at most one bike to one biker which is a bipartite matching problem. Then we have
                to find the minimum time that K bikes can be aquired. Since we know the lower bound and upper bound for the time
                required to aquire bikes, a simple binary search will solve this problem. I've used hopcroft-karp algorithm to match
                the bipartites because it only requires O(sqrt(N + M) * NM) time.
                
    Total Time Complexity:  O(log(1e14) * sqrt(N + M) * NM)
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
int n, m, k;
// d[i][j] : Euclidean squared distance from ith biker to kth bike.
// augDistance[u] : Distance of the current augmenting path to vertex u.
lli d[251][251], augDistance[251];
// Initially unmatched vertices in each partite to store the matches.
int unmatchedBikers[251], unmatchedBikes[251];
vector<int> biGraph[251];
const lli INF = 2e9;

bool dfs(int biker) {
    if (biker != 0) {
        for (int bike: biGraph[biker]) {
            if (augDistance[unmatchedBikes[bike]] == augDistance[biker] + 1) {
                if(dfs(unmatchedBikes[bike])) {
                    unmatchedBikes[bike] = biker;
                    unmatchedBikers[biker] = bike;
                    return true;
                }
            }
        }
        augDistance[biker] = INF;
        return false;
    }
    return true;
}

bool bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (unmatchedBikers[i] == 0) {
            augDistance[i] = 0;
            q.push(i);
        }
        else
            augDistance[i] = INF;
    }
    augDistance[0] = INF;
    while (!q.empty()) {
        int biker = q.front();
        q.pop();
        if (augDistance[biker] < augDistance[0]) {
            for (int bike: biGraph[biker]) {
                if (augDistance[unmatchedBikes[bike]] == INF) {
                    augDistance[unmatchedBikes[bike]] = augDistance[biker] + 1;
                    q.push(unmatchedBikes[bike]);
                }
            }
        }
    }
    return augDistance[0] != INF;
}

int hopcroftKarp() {
    memset(unmatchedBikers, 0, sizeof(unmatchedBikers));
    memset(unmatchedBikes, 0, sizeof(unmatchedBikes));
    int matches = 0;
    while (bfs()) {
        for (int i = 1; i <= n; i++)
            if (unmatchedBikers[i] == 0 && dfs(i))
                matches++;
    }
    return matches;
}

bool can(lli squaredT) {
    for (int i = 1; i <= n; i++) {
        biGraph[i].clear();
        for (int j = 1; j <= m; j++) {
            if (d[i][j] <= squaredT) {
                biGraph[i].push_back(j);
            }
        }
    }
    if (hopcroftKarp() >= k)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    pair<lli, lli> bikers[n + 1];
    pair<lli, lli> bikes[m + 1];
    for (int i = 1; i <= n; i++)
        cin >> bikers[i].first >> bikers[i].second;
    for (int i = 1; i <= m; i++)
        cin >> bikes[i].first >> bikes[i].second;
    // Distances from ith biker to jth bike.
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            d[i][j] = (bikers[i].first - bikes[j].first) * (bikers[i].first - bikes[j].first) + (bikers[i].second - bikes[j].second) * (bikers[i].second - bikes[j].second);
    // Binary search for the minimum squared time.
    lli low = 0, high = 1e14; // (Search upto the squared value of max possible distance)
    while (low < high) {
        lli minSquaredT = (low + high) / 2;
        if (can(minSquaredT))
            high = minSquaredT;
        else
            low = minSquaredT + 1;
    }
    cout << low << endl;
}
