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
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, ans1 = 0, ans2 = 0;
        cin >> n;
        vector<float> naomi;
        vector<float> ken;
        vector<bool> ynn;
        vector<bool> ynk;
        for (int j = 0; j < n; j++) {
            float tmp;
            cin >> tmp;
            naomi.push_back(tmp);
            ynn.push_back(false);
        }
        for (int j = 0; j < n; j++) {
            float tmp;
            cin >> tmp;
            ken.push_back(tmp);
            ynk.push_back(false);
        }
        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (ken[k] > naomi[j] && !ynk[k]) {
                    ans1++;
                    ynk[k] = true;
                    break;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (naomi[k] > ken[j] && !ynn[k]) {
                    ans2++;
                    ynn[k] = true;
                    break;
                }
            }
        }
        ans1 = n - ans1;
        printf("Case #%d: %d %d\n", i + 1, ans2, ans1);
    }
    return 0;
}
