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
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s, s1;
        cin >> s;
        s1 = s;
        if (s.size() == 1) printf("Case #%d: %s %s\n", i + 1, s.c_str(), s.c_str());
        else {
            string S = s;
            map<char, int> mp;
            for (int j = 0; j < s.size(); j++) {
                mp[s[j]] = INT_MIN;
            }
            for (int j = 0; j < s.size(); j++) {
                mp[s[j]] = max(j, mp[s[j]]);;
            }
            sort(S.rbegin(), S.rend());
            for (int j = 0; j < s.size(); j++) {
                if (s[j] != S[j]) {
                    char c = s[j];
                    s[j] = S[j];
                    s[mp[S[j]]] = c;
                    break;
                }
            }
            sort(S.begin(), S.end());
            int zeros = 0;
            for (int j = 0; j < S.size(); j++) {
                if (S[j] == '0') {
                    zeros++;
                }
                else break;
            }
//cout<<S<<endl;
            char ch = S[zeros];
            S.erase(S.begin() + zeros);
            S.insert(S.begin(), ch);
//cout<<S<<endl;
            for (int j = 0; j < s1.size() - 1; j++) {
                if (s1[j] != S[j]) {
                    char c = s1[j];
                    s1[j] = S[j];
                    s1[mp[S[j]]] = c;
                    break;
                }
            }
            printf("Case #%d: %s %s\n", i + 1, s1.c_str(), s.c_str());
        }
    }
    return 0;
}
