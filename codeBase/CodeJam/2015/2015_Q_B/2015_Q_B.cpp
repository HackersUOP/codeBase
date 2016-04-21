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
bool yn(vector<int> vec, int x, int u) {
    if (x >= vec.back()) return true;
    else {
        int sm = 0;
        for (int g = 0; g < vec.size(); g++) {
            if (vec[g] > x - u) sm += (vec[g] - 1) / (x - u);
            if (sm > u) return false;
        }
        return true;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    map<vector<int>, int> mp;
    for (int i = 0; i < t; i++) {
        int d;
        cin >> d;
        int mx = INT_MIN;
        vector<int> vec;
        for (int j = 0; j < d; j++) {
            int tmp;
            cin >> tmp;
            mx = (mx > tmp) ? mx : tmp;
            vec.push_back(tmp);
        }
        if (mx <= 3) {
            printf("Case #%d: %d\n", i + 1, mx);
            continue;
        }
        sort(vec.begin(), vec.end());
        int l = 0, r = 1000, x;
        while (l < r) {
            x = (l + r) / 2;
            bool cann = false;
            for (int u = 1; u < x; u++) {
                if (yn(vec, x, u)) {
                    cann = true;
                    break;
                }
            }
            if (cann) r = x;
            else l = x + 1;
        }
        printf("Case #%d: %d\n", i + 1, l);
    }
    return 0;
}
