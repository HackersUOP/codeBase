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
using namespace std;


int main() {
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        string s;
        cin >> s;
        int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
        int n = s.size();
        int T = 0;
        bool C = false;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == 'E') {
                n1 += 1;
                continue;
            }
            else n1 += 2;
            if (n2 < n1) n2 = n1 + 3;
            else n2 += 3;
            if (c == 'M') {
                if (n4 < n2) n4 = n2 + 2;
                else n4 += 2;
            }
            else {
                if (c == 'C') C = true;
                else if (c == 'L') C = false;
                if (c == 'S' && C) {
                    if (n3 < n2) n3 = n2 + 2;
                    else n3 += 2;
                    continue;
                }
                else {
                    if (n3 < n2) n3 = n2 + 3;
                    else n3 += 3;
                    if (n4 < n3) n4 = n3 + 2;
                    else n4 += 2;
                }
            }
        }
        vector<int> vec{n1, n2, n3, n4};
        sort(vec.rbegin(), vec.rend());
        cout << vec[0] << endl;
    }
    return 0;
}
