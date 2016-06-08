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
typedef long long ll;
typedef pair<int, int> pr;
string pad(string s, ll b) {
    string ret = s;
    for (int f = 0; f < (b - s.size()) / 2; f++) ret = "0" + ret + "0";
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    vector<vector<ll> > palindromes;
    vector<ll> fns{1, 2, 3, 121, 484};
    vector<ll> one{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<ll> two{11, 22, 33, 44, 55, 66, 77, 88, 99};
    palindromes.push_back(one);
    palindromes.push_back(two);
    for (ll i = 3; i <= 7; i++) {
        vector<ll> tmp;
        string zs = "";
        for (int u = 0; u <= (i - 3); u++) zs += "0";
        for (int k = 1; k < 10; k++) {
            string e = to_string(k) + zs + to_string(k);
            string::size_type sz = 0;
            ll num = stoll(e, &sz, 0);
            string s3 = to_string(num * num);
            string s4 = s3;
            reverse(s3.begin(), s3.end());
            if (s3 == s4) fns.push_back(num * num);
            tmp.push_back(num);
            for (int g = (i + 1) % 2; g <= (i - 3); g += 2) {
                vector<ll> mid = palindromes[g];
                for (ll j = 0; j < mid.size(); j++) {
                    string s;
                    s = to_string(k) + pad(to_string(mid[j]), (i - 2)) + to_string(k);
                    string::size_type sz = 0;
                    ll num = stoll(s, &sz, 0);
                    string s3 = to_string(num * num);
                    string s4 = s3;
                    reverse(s3.begin(), s3.end());
                    if (s3 == s4) fns.push_back(num * num);
                    tmp.push_back(num);
                }
            }
        }
        palindromes.push_back(tmp);
    }
    sort(fns.begin(), fns.end());
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll A, B;
        cin >> A >> B;
        int a_ind = -1, b_ind = fns.size() - 1, ans = 0;
        for (int j = 0; j < fns.size(); j++) if (fns[j] >= A) {a_ind = j; break;}
        for (int j = 0; j < fns.size(); j++) {
            if (fns[j] >= B) {
                if (fns[j] > B) b_ind = j - 1;
                else b_ind = j;
                break;
            }
        }
        if (a_ind != -1) ans = b_ind - a_ind + 1;
        printf("Case #%d: %d\n", i + 1, ans);
    }
    return 0;
}
