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
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    string s;
    string s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi", s2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", s3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    string S1 = "our language is impossible to understand", S2 = "there are twenty six factorial possibilities", S3 = "so it is okay if you want to just give up";
    map<char, char> mp;
    for (unsigned int i = 0; i < s1.size(); i++) mp[s1[i]] = S1[i];
    for (unsigned int i = 0; i < s2.size(); i++) mp[s2[i]] = S2[i];
    for (unsigned int i = 0; i < s3.size(); i++) mp[s3[i]] = S3[i];
    mp['y'] = 'a';
    mp['e'] = 'o';
    mp['q'] = 'z'; mp['z'] = 'q';
    vector<char> tmp;
    for (auto iter : mp) {
        tmp.push_back(iter.first);
    }
    sort(tmp.begin(), tmp.end());
    for (unsigned int i = 0; i < tmp.size(); i++) cout << tmp[i] << " ";
    cout << endl;
    int t;
    getline(cin, s);
    stringstream(s) >> t;
    for (int i = 0; i < t; i++) {
        string ans = "";
        getline(cin, s);
        for (unsigned int j = 0; j < s.size(); j++) ans += mp[s[j]];
        printf("Case #%d: %s\n", i + 1, ans.c_str());
    }
    return 0;
}
