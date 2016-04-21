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
/*
Author: Samurdhi Karunarathne @ samurdhilbk
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int segments = 0;
        vector<int> uones;
        vector<int> lones;
        vector<int> uparents;
        vector<int> lparents;
        map<int, bool> umap;
        map<int, bool> lmap;
        int lasth = -1;
        int lastp = 0;
        for (int k = 0; k < n; k++) {
            char c;
            cin >> c;
            if (c == 'X') {
                if (k - lasth >= 2) {
                    segments++;
                    if (k - lasth == 2) uones.push_back(lasth + 1);
                    umap[lasth + 1] = false;
                }
                uparents.push_back(-1);
                lasth = k;
                lastp = k + 1;
            }
            else {
                if (k == n - 1) {
                    if (k + 1 - lasth >= 2) {
                        segments++;
                        if (k + 1 - lasth == 2) uones.push_back(lasth + 1);
                        umap[lasth + 1] = false;
                    }
                }
                uparents.push_back(lastp);
            }
        }
        lasth = -1;
        lastp = 0;
        for (int k = 0; k < n; k++) {
            char c;
            cin >> c;
            if (c == 'X') {
                if (k - lasth >= 2) {
                    segments++;
                    if (k - lasth == 2) lones.push_back(lasth + 1);
                    lmap[lasth + 1] = false;
                }
                lparents.push_back(-1);
                lasth = k;
                lastp = k + 1;
            }
            else {
                if (k == n - 1) {
                    if (k + 1 - lasth >= 2) {
                        segments++;
                        if (k + 1 - lasth == 2) lones.push_back(lasth + 1);
                        lmap[lasth + 1] = false;
                    }
                }
                lparents.push_back(lastp);
            }
        }
        int numg = 0, nums = 0;
        for (int k = 0; k < uones.size(); k++) {
            int j = uones[k];
            numg++;
            nums++;
            if (lparents[j] != -1 && !lmap[lparents[j]]) {
                lmap[lparents[j]] = true;
                nums++;
            }
        }
        for (int k = 0; k < lones.size(); k++) {
            int j = lones[k];
            if (!lmap[j]) {
                numg++;
                nums++;
                if (uparents[j] != -1 && !umap[uparents[j]]) {
                    umap[uparents[j]] = true;
                    nums++;
                }
            }
        }
        printf("Case #%d: %d\n", i + 1, numg + segments - nums);
    }
    return 0;
}
