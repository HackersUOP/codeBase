/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-4-0/challenges/strange-house
    
    Approach: Note that two walls in two regions getting aligned is equivalent to the number of rooms in those reigions have a common factor. So, in order to partition the whole
              house into isolated parts, all three reigions must have a common factor in their number of rooms. Therefore, if gcd(n, m, k) = 1 any room is reachable from any
              other room because there will be no isolated partitions. But if it's not the case, we have to check whether both rooms are in the same isolated partition or not.
              Because any room in a particular isolated partition is reachable from any other room inside that partition. We can simply check that by dividing the 0-indexed
              index number of the rooms by the number of rooms inside an isolated partition of their corresponding reigion and comparing whether they're equal or not.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long region[3];
    int q;
    cin >> region[0], cin.ignore(), cin >> region[1], cin.ignore(), cin >> region[2], cin.ignore(), cin >> q;
    long long g = __gcd(region[0], __gcd(region[1], region[2]));
    if (g != 1)
        region[0] /= g, region[1] /= g, region[2] /= g; // Calculate the number of rooms inside an isolated partition for each region
    for (int t = 0; t < q; t++) {
        long long x, y, w, z;
        cin >> x, cin.ignore(), cin >> y, cin.ignore(), cin >> w, cin.ignore(), cin >> z;
        if (g == 1)
            cout << "YES" << endl;
        else if ((y - 1) / region[x - 1] == (z - 1) / region[w - 1]) {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
