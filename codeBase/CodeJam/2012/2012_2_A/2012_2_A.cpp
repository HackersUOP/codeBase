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
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;
bool solve(vector<pr> &vines, map<pr, bool> &mp, ll D, ll s, ll e, ll n) {
    if (mp.find(make_pair(s, e)) != mp.end()) return mp[make_pair(s, e)];
    ll len, d;
    if (vines[e].second < vines[e].first - vines[s].first) {
        d = vines[e].first - vines[e].second;
        len = vines[e].second;
    }
    else {
        d = vines[s].first;
        len = vines[e].first - vines[s].first;
    }
    if ((vines[e].first + len) >= D) {
        mp[make_pair(s, e)] = true;
        return true;
    }
    for (ll i = e + 1; i <= n; i++) {
        if ((vines[i].first <= vines[e].first + len) && (vines[i].first > vines[e].first)) {
            if (mp.find(make_pair(e, i)) != mp.end()) {
                if (mp[make_pair(e, i)]) return true;
            }
            else {
                if (solve(vines, mp, D, e, i, n)) {
                    mp[make_pair(e, i)] = true;
                    return true;
                }
            }
        }
        else break;
    }
    mp[make_pair(s, e)] = false;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n;
        cin >> n;
        vector<pr> vines;
        map<pr, bool> mp;
        for (ll j = 0; j < n; j++) {
            ll d, l;
            cin >> d >> l;
            vines.push_back(make_pair(d, l));
        }
        ll D;
        cin >> D;
        if (i <= 22) continue;
        sort(vines.begin(), vines.end());
        vines.insert(vines.begin(), make_pair(0, 0));
        bool ans = solve(vines, mp, D, 0, 1, n);
        if (ans) printf("Case #%d: YES\n", i + 1);
        else printf("Case #%d: NO\n", i + 1);
    }
    return 0;
}
