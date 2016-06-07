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

#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    map<string, int> mp;
    getline(cin, s);
    stringstream ss(s);
    int e;
    ss >> e;
    for (int i = 0; i < e; i++) {
        getline(cin, s);
        string s1 = "", s2 = "";
        int j = -1;
        while (1) {
            j++;
            s1 += s[j];
            if (s[j] == ')') break;
        }
        j++;
        while (1) {
            j++;
            s2 += s[j];
            if (s[j] == ')') break;
        }
        if (mp.find(s1) != mp.end()) mp[s1]++;
        else mp[s1] = 1;
        if (mp.find(s2) != mp.end()) mp[s2]++;
        else mp[s2] = 1;
    }
    int count = 0;
    for (auto &iter : mp) {
        if (iter.second % 2 == 1) count++;
        if (count > 2) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}
