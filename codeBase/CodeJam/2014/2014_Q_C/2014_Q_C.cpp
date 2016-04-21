/*
Copyright Hackers' Club, University Of Peradeniya
Author : E/13/181 (Samurdhi Karunarathne)
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at *
http://www.apache.org/licenses/LICENSE-2.0 *
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
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
vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
vector<int> findd(vector<int> coins, map<int, vector<int> > &mp, int num, int x) {
    vector<int> ret;
    for (int i = 0; i < coins.size(); i++) {
        if (num % coins[i] == 0 && ((num - (num % coins[i])) / coins[i] <= x)) {
            vector<int> ret;
            for (int j = 0; j < (num - (num % coins[i])) / coins[i]; j++) ret.push_back(coins[i]);
            return ret;
        }
    }
    for (unsigned int i = coins.size(); i-- > 0;) {
        if (num > coins[i]) {
            vector<int> ans;
            if (mp.find(num - coins[i]) != mp.end()) ans = mp[num - coins[i]];
            else {
                vector<int> tmp = findd(coins, mp, num - coins[i], x - 1);
                mp[num - coins[i]] = tmp;
                ans = tmp;
            }
            if (ans.size() != 0) {
                ans.push_back(coins[i]);
                sort(ans.begin(), ans.end());
                return ans;
            }
        }
    }
    return ret;
}
bool solve(int r, int c, int m, int t) {
    char grid[r][c];
    int e = r * c - m;
    if (e == 0) return false;
    if (m == 0) {
        cout << "Case #" << (t + 1) << ":" << endl; //<<r<<" "<<c<<" "<<m<<endl;
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) grid[j][k] = '.';
        }
        grid[0][0] = 'c';
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) cout << grid[j][k];
            cout << endl;
        }
        return true;
    }
    if (r == 1) {
        cout << "Case #" << (t + 1) << ":" << endl; //<<r<<" "<<c<<" "<<m<<endl;
        cout << 'c';
        for (int j = 1; j < e; j++) cout << '.';
        for (int j = e; j < c; j++) cout << '*';
        cout << endl;
        return true;
    }
    if (c == 1) {
        cout << "Case #" << (t + 1) << ":" << endl; //<<r<<" "<<c<<" "<<m<<endl;
        cout << 'c' << endl;
        for (int j = 1; j < e; j++) cout << '.' << endl;
        for (int j = e; j < r; j++) cout << '*' << endl;
        return true;
    }
    if (e == 1) {
        cout << "Case #" << (t + 1) << ":" << endl;
        for (int k = 0; k < r; k++) {
            for (int g = 0; g < c; g++) grid[k][g] = '*';
        }
        grid[0][0] = 'c';
        for (int k = 0; k < r; k++) {
            for (int g = 0; g < c; g++) cout << grid[k][g];
            cout << endl;
        }
        return true;
    }
    if (e < 4) return false;
    for (int k = 0; k < r; k++) {
        for (int g = 0; g < c; g++) grid[k][g] = '-';
    }
    for (int j = 2; j <= r; j++) {
        if (e % j == 0 && (e / j) <= c && (e / j) >= 2) {
            for (int k = 0; k < j; k++) {
                for (int g = 0; g < (e / j); g++) grid[k][g] = '.';
            }
            grid[0][0] = 'c';
            for (int k = 0; k < r; k++) {
                for (int g = 0; g < c; g++) {
                    if (grid[k][g] != '.' && grid[k][g] != 'c') grid[k][g] = '*';
                }
            }
            cout << "Case #" << (t + 1) << ":" << endl;
            for (int k = 0; k < r; k++) {
                for (int g = 0; g < c; g++) cout << grid[k][g];
                cout << endl;
            }
            return true;
        }
    }
    if (e <= r * 2) {
        if (e % 2 == 0) {
//cout<<"one"<<endl;
            for (int j = 0; j < e / 2; j++) {grid[j][0] = '.'; grid[j][1] = '.';}
            for (int j = e / 2; j < r; j++) {grid[j][0] = '*'; grid[j][1] = '*';}
            grid[0][0] = 'c';
            for (int j = 2; j < c; j++) {
                for (int k = 0; k < r; k++) grid[k][j] = '*';
            }
            cout << "Case #" << (t + 1) << ":" << endl; //<<r<<" "<<c<<" "<<m<<endl;
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) cout << grid[j][k];
                cout << endl;
            }
            return true;
        }
    }
    if (e <= c * 2) {
        if (e % 2 == 0) {
//cout<<"three"<<endl;
            for (int j = 0; j < e / 2; j++) {grid[0][j] = '.'; grid[1][j] = '.';}
            for (int j = e / 2; j < c; j++) {grid[0][j] = '*'; grid[1][j] = '*';}
            grid[0][0] = 'c';
            cout << "Case #" << (t + 1) << ":" << endl; //<<r<<" "<<c<<" "<<m<<endl;
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < c; k++) cout << grid[j][k];
                cout << endl;
            }
            for (int j = 2; j < r; j++) {
                for (int k = 0; k < c; k++) cout << '*';
                cout << endl;
            }
            return true;
        }
    }
    for (int u = 3; u <= r; u++) {
        vector<int> feed;
        /*int ind=0;
        while(primes[ind]<u&&ind<=14){
        feed.push_back(primes[ind]);
        ind++;
        }*/
        for (int h = 2; h <= u; h++) feed.push_back(h);
        map<int, vector<int> > mp;
        vector<int> ret = findd(feed, mp, e - u * 2, c - 2);
        if (ret.size() != 0) {
//cout<<"rrrr "<<u<<endl;
            sort(ret.rbegin(), ret.rend());
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < u; k++) grid[k][j] = '.';
            }
            for (int j = 2; j < (2 + ret.size()); j++) {
                for (int k = 0; k < ret[j - 2]; k++) grid[k][j] = '.';
            }
            grid[0][0] = 'c';
            for (int k = 0; k < r; k++) {
                for (int g = 0; g < c; g++) {
                    if (grid[k][g] != '.' && grid[k][g] != 'c') grid[k][g] = '*';
                }
            }
            cout << "Case #" << (t + 1) << ":" << endl; //<<r<<" "<<c<<" "<<m<<endl;
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) cout << grid[j][k];
                cout << endl;
            }
            return true;
        }
    }
    for (int u = 3; u <= c; u++) {
//cout<<"ccccc"<<endl;
        vector<int> feed;
        /*int ind=0;
        while(primes[ind]<u&&ind<=14){
        feed.push_back(primes[ind]);
        ind++;
        }*/
        for (int h = 2; h <= u; h++) feed.push_back(h);
        map<int, vector<int> > mp;
        vector<int> ret = findd(feed, mp, e - u * 2, r - 2);
        if (ret.size() != 0) {
            sort(ret.rbegin(), ret.rend());
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < u; k++) grid[j][k] = '.';
            }
            for (int j = 2; j < (2 + ret.size()); j++) {
                for (int k = 0; k < ret[j - 2]; k++) grid[j][k] = '.';
            }
            grid[0][0] = 'c';
            for (int k = 0; k < r; k++) {
                for (int g = 0; g < c; g++) {
                    if (grid[k][g] != '.' && grid[k][g] != 'c') grid[k][g] = '*';
                }
            }
            cout << "Case #" << (t + 1) << ":" << endl; //<<r<<" "<<c<<" "<<m<<endl;
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) cout << grid[j][k];
                cout << endl;
            }
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int r, c, m;
        cin >> r >> c >> m;
        if (!solve(r, c, m, i)) cout << "Case #" << (i + 1) << ":" << endl << "Impossible" << endl;
    }
    return 0;
}
