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
#include <climits>
using namespace std;
typedef tuple<int, int, int> tr;
tr operator-(const tr &one, const tr &two) {
    tr ret;
    get<0>(ret) = get<0>(one) - get<0>(two);
    get<1>(ret) = get<1>(one) - get<1>(two);
    get<2>(ret) = get<2>(one) - get<2>(two);
    return ret;
}
bool solve(vector<tr> &vec, map<tr, bool> &mp, tr trans) {
    if (get<0>(trans) < 10) return false;
    if (get<1>(trans) < 10) return false;
    if (get<2>(trans) < 10) return false;
    if (binary_search(vec.begin(), vec.end(), trans)) return true;
    if (mp.find(trans) != mp.end()) return mp[trans];
    for (int i = 0; i < vec.size(); i++) {
        tr tri = trans - vec[i];
        if (solve(vec, mp, tri)) {
            mp[tri] = true;
            return true;
        }
        else {
            mp[tri] = false;
        }
    }
    mp[trans] = false;
    return false;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int i1, i2, i3;
        cin >> i1 >> i2 >> i3;
        tr target = make_tuple(i1, i2, i3);
        int n;
        cin >> n;
        vector<tr> vec;
        map<tr, bool> mp;
        for (int j = 0; j < n; j++) {
            int i1, i2, i3;
            cin >> i1 >> i2 >> i3;
            vec.push_back(make_tuple(i1, i2, i3));
        }
        sort(vec.begin(), vec.end());
        if (solve(vec, mp, target)) printf("Case #%d: yes\n", i + 1);
        else printf("Case #%d: no\n", i + 1);
    }
    return 0;
}
