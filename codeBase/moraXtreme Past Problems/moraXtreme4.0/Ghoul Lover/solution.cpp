/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-4-0/challenges/ghoul-lover
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    cin >> m;
    vector<pair<int, int>> energy(m);
    for (int i = 0; i < m; i++) {
        int p, e;
        cin >> p >> e;
        energy[i] = {p, e};
    }
    // Sort by the position of a ghoul
    sort(energy.begin(), energy.end());
    // Pre-calculate the indices of the lastly killed ghouls (sorted by their positions) by an attack from positive infinity ending at position x = i 
    int lastKill[1000001], p = 0;
    for (int j = 0, i = 0; i <= energy[m - 1].first && j < m; i++) {
        lastKill[i] = p;
        if (energy[j].first == i) {
            j++;
            p = j;
        }
    }
    int minKills = 1000001;
    // Try killing the last half of the ghouls
    for (int i = m; i >= (m + 1) / 2; i--) {
        // Check how many kills can the current ghoul do
        int kills = 0;
        for (int j = i - 1; j >= 0;) {
            int last = energy[j].first - energy[j].second;  // Last position the energy can reach at
            if (last < 0)
                last = 0;
            kills += j - lastKill[last];
            j = lastKill[last] - 1;
        }
        // m - i is the number of ghouls we're trying to kill in order to minimize the number of kills
        minKills = min(minKills, kills + m - i);
        if (m - i > minKills)
            break;
    }
    cout << minKills;
}
