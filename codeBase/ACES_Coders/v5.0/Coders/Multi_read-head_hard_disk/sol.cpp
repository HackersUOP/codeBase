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
        int x, y;
        cin >> x >> y;
        vector<string> vec(y);
        vector<string> tar(y);
        for (int i = 0; i < y; i++) {
            cin >> vec[i];
        }
        for (int i = 0; i < y; i++) {
            cin >> tar[i];
        }
        sort(tar.begin(), tar.end());
        for (int i = 0; i < y; i++) {
            string g = "";
            for (int j = 0; j < x; j++) {
                if (vec[0][j] != tar[i][j]) g += "1";
                else g += "0";
            }
            vector<string> temp = vec;
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < x; k++) {
                    if (g[k] == '1') {
                        if (temp[j][k] == '1') temp[j][k] = '0';
                        else temp[j][k] = '1';
                    }
                }
            }
            sort(temp.begin(), temp.end());
            if (temp == tar) {
                cout << g << endl;
                goto here;
            }
        }
        cout << "Impossible" << endl;
here:;
    }
    return 0;
}
