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
#include <cfloat>
#define eps 1e-9
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ll> pr;
pr find(vector<ld> &psum, ld c) {
//cout<<"c "<<c<<endl;
    if (c == 0.0) return make_pair(0.0, 0);
    if (c >= psum.back()) return find(psum, c - psum.back() * floor(c / psum.back()));
    ll l = 0, r = psum.size() - 1, x;
    while (l <= r) {
        x = (l + r) / 2;
        if (psum[x] <= c) l = x + 1;
        else r = x - 1;
    }
    return make_pair(c - psum[l - 1], l - 1);
}
ld solve(vector<ld> &psum, ld l, ld r, ld range) {
    ld ans = 0.0;
    while (l < r) {
        pr ret = find(psum, l);
        ld foo = min(l + psum[ret.second + 1] - psum[ret.second] - ret.first, r);
//cout<<"foo "<<foo<<endl;
        ans += (ret.first + foo - l + ret.first) / 2.0 * (foo - l) / range;
        l = foo;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n;
        ld a, b;
        cin >> n >> a >> b;
        vector<ld> psum;
        psum.push_back(0.0);
        ld sm = 0.0;
        for (ll j = 0; j < n; j++) {
            ld tmp;
            cin >> tmp;
            sm += tmp;
            psum.push_back(sm);
        }
        printf("Case #%d: %.9Lf\n", i + 1, solve(psum, a, b, b - a));
    }
    return 0;
}
